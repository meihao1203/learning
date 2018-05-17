 ///
 /// @file    test.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-19 15:13:19
 ///
 
#include<iostream>
#include"Threadpool.h"
#include<unistd.h>
#include<stdlib.h>
using namespace std;
class MyTask:public meihao::Task
{
	public:
		void process()
		{
			::srand(time(NULL));
			int num = ::rand()%100;
			cout<<"produce a num:"<<num<<endl;
		}
};
int main()
{
	meihao::Threadpool threadpool(4,10);  // 定义一个线程池，里面有4个线程，去处理10个任务
	threadpool.start();
	meihao::Task* ptask = new MyTask();  // 定义一个具体的任务
	int cnt = 10;
	while(cnt--)
	{
		threadpool.addTask(ptask);  // 线程池中添加任务
		//sleep(1);
	}
	threadpool.stop();
	return 0;
}
//produce a num:22
//produce a num:48
//produce a num:17
//produce a num:20
//produce a num:13
//produce a num:31
//produce a num:13
//produce a num:98
//produce a num:23
//produce a num:27
