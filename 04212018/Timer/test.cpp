 ///
 /// @file    test.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-21 10:14:33
 ///
 
#include<iostream>
#include"TimerThread.h"
#include<stdlib.h>
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
	meihao::TimerThread timerThread(bind(&::produce),5,3);
	timerThread.start();  // 开启线程，去执行timer里的start函数
	sleep(20);  // main线程睡眠20s,不过子线程还在执行
	timerThread.stop();  // timer关闭，子线程就会退出while循环
	 // main线程等待回收退出的子线程
	return 0;
}
/*结果中，第20s的时候计时器关闭了，所有整个打印过程持续了17s*/
//计时器开启：
//Sat Apr 21 14:52:44 2018
//
//Sat Apr 21 14:52:49 2018
//produce a num 61
//
//Sat Apr 21 14:52:52 2018
//produce a num 24
//
//Sat Apr 21 14:52:55 2018
//produce a num 48
//
//Sat Apr 21 14:52:58 2018
//produce a num 94
//
//Sat Apr 21 14:53:01 2018
//produce a num 48
//
