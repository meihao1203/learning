 ///
 /// @file    test.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-21 16:43:49
 ///
 
#include<iostream>
#include"Eventfd.h"
#include"Thread.h"
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
using namespace std;
void produce()
{
	::srand(time(NULL));
	int num = rand()%100;
	cout<<"produce a num "<<num<<endl<<endl;
}
int main()
{
	meihao::Eventfd event(bind(&produce));	
	meihao::Thread thread(bind(&meihao::Eventfd::start,&event));
	thread.start();  // 启动线程去执行Event里面的start函数 
	int cnt = 5;
	while(cnt--)
	{
		event.wakeup();  // 触发poll向下继续执行Eventfd里面的start函数
		sleep(2);
	}
	event.stop();  // 线程执行体退出，结束线程
	thread.join();  // main线程等待回收子线程资源
	
	return 0;
}
//start time Sat Apr 21 16:59:23 2018
//
//poll trigger time Sat Apr 21 16:59:23 2018
//produce a num 93
//
//poll trigger time Sat Apr 21 16:59:25 2018
//produce a num 6
//
//poll trigger time Sat Apr 21 16:59:27 2018
//produce a num 38
//
//poll trigger time Sat Apr 21 16:59:29 2018
//produce a num 39
//
//poll trigger time Sat Apr 21 16:59:31 2018
//produce a num 57
//
