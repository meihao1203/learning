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
		for(int j=1;j<argc;++j)
		{
			u = atoll(argv[j]);
			cout<<"child writing "<<u<<" to efd"<<endl;
			ssize_t s = write(efd,&u,sizeof(uint64_t));  // 会把写入的数据累加到计数器上的
			if(s!=sizeof(uint64_t))
			{
				handle_error("write");
			}
		}
		cout<<"child completed write loop\n";
		exit(EXIT_SUCCESS);
	}
	else
	{
		//sleep(2);  // 等子进程创建好,并循环完毕
		for(int i=0;i<argc-1;++i)
		{
			ssize_t s = read(efd,&u,sizeof(uint64_t));  // 每次读完,计数器会变成0
			if(s!=sizeof(uint64_t))
			{
				handle_error("read");
			}
			cout<<"parent read "<<u<<" from efd\n";
		}
		exit(EXIT_SUCCESS);
	}
}
//父进程在睡眠2s的过程中，子进程已经完成了for循环，向内核的计数器上写了1,2,3;
//加上初值10,一共就是16
//child writing 1 to efd
//child writing 2 to efd
//child writing 3 to efd
//child completed write loop
//parent read 16 from efd

//父进程不睡眠，for循环读走所有输入
//父进程先于子进程运行，读走了计数器的值10，计数器此时值变为0，后面父进程读操作处于阻塞状态
//等到子进程写入1的时候唤醒父进程，父进程接着读。
//$>./a.out 1 2 3
//parent read 10 from efd
//child writing 1 to efd
//parent read 1 from efd
//child writing 2 to efd
//parent read 2 from efd
//$>child writing 3 to efd
