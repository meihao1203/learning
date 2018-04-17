 ///
 /// @file    ConsumerThread.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-17 10:32:40
 ///
 
#include<iostream>
#include"ConsumerThread.h"
#include<unistd.h>
using namespace std;
namespace meihao
{
	void ConsumerThread::run()
	{
		int i = 0;
		while(i<5)
		{
			int num = _buff.pop();
			cout<<"Consumer a num "<<num<<endl;
			sleep(2);
		i++;
		}
	}
};
