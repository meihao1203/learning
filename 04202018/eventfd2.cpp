 ///
 /// @file    eventfd.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-19 19:19:28
 ///
 
#include<iostream>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/eventfd.h>
#include<sys/poll.h>
#include<sys/wait.h>
#define handle_error(msg) \
	   do{\
		   perror(msg);\
		   exit(EXIT_FAILURE);\
		}while(0)
using namespace std;
int main(int argc,char** argv)
{
	uint64_t u;
	int efd = eventfd(0,0);  // 计数器的初值为0,第二个参数写0
	//最新的进程/线程通信
	if(-1==efd)
	{
		handle_error("eventfd");
	}
	int ret = fork();
	if(0==ret)
	{
	//	struct pollfd pfd;
	//	pfd.fd = efd;
	//	pfd.events = POLLIN;
		for(int j=1;j<argc;++j)
		{
			u = atoll(argv[j]);
			cout<<"child writing "<<u<<" to efd"<<endl;
			ssize_t s = write(efd,&u,sizeof(uint64_t));  // 读完计数器会自动清0
			if(s!=sizeof(uint64_t))
			{
				handle_error("write");
			}
	//		poll(&pfd,1,-1);  // 等待efd可读,永久等待
		}
		cout<<"child completed write loop\n";
		//exit(EXIT_SUCCESS);
	}
	else
	{
		struct pollfd ppfd;
		ppfd.fd = efd;
		ppfd.events = POLLIN;
		for(int i=1;i<argc;++i)
		{
			poll(&ppfd,1,-1);  // 事件在等待ppfd可读，等待过程中父进程睡眠
	//		事件发生就唤醒，接着向下执行
	//		没有这个读一次就会卡住
			ssize_t s = read(efd,&u,sizeof(uint64_t));
			if(s!=sizeof(uint64_t))
			{
				handle_error("read");
			}
			cout<<"parent read "<<u<<" from efd\n";
		}
		wait(NULL);
	}
}
//child writing 1 to efd
//parent read 1 from efd
//child writing 2 to efd
//parent read 2 from efd
//child writing 3 to efd
//parent read 3 from efd
//child completed write loop
