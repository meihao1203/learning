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
#define handle_error(msg) \
	   do{\
		   perror(msg);\
		   exit(EXIT_FAILURE);\
		}while(0)
using namespace std;
int main(int argc,char** argv)
{
	uint64_t u;
	int efd = eventfd(10,0);  // 计数器的初值为10,第二个参数写0
	//最新的进程/线程通信
	if(-1==efd)
	{
		handle_error("eventfd");
	}
	int ret = fork();
	if(0==ret)
	{
//		struct pollfd pfd;
//		pfd.fd = 0;
//		pfd.events = POLLIN;
		for(int j=1;j<argc;++j)
		{
			//cout<<"child writing "<<argv[j]<<" to efd"<<endl;
			u = atoll(argv[j]);
			cout<<"child writing "<<u<<" to efd"<<endl;
			ssize_t s = write(efd,&u,sizeof(uint64_t));  // 读完计数器会自动清0
			if(s!=sizeof(uint64_t))
			{
				handle_error("write");
			}
		//	poll(&pfd,1,1000);  // 等待efd可读，的等待时间不超过1000ms
		}
		cout<<"child completed write loop\n";
		exit(EXIT_SUCCESS);
	}
	else
	{
		struct pollfd ppfd;
		ppfd.fd = 0;
		ppfd.events = POLLIN;
		sleep(2);  // 等子进程创建好,并循环完毕
//		for(int i=0;i<argc-1;++i)
//		{
			ssize_t s = read(efd,&u,sizeof(uint64_t));
			if(s!=sizeof(uint64_t))
			{
				handle_error("read");
			}
	//		poll(&ppfd,1,2000);  // 事件在等待ppfd可读，等待过程中父进程睡眠
	//		事件发生就唤醒，接着向下执行
	//		没有这个读一次就会卡住
			cout<<"parent read "<<u<<" from efd\n";
//		}
		exit(EXIT_SUCCESS);
	}
}
