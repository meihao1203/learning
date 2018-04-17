 ///
 /// @file    ProduceThread.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-17 10:15:38
 ///
 
#include<iostream>
#include"ProduceThread.h"
#include<time.h>
#include<unistd.h>
using namespace std;
namespace meihao
{
	void ProduceThread::run()
	{
		::srand(time(NULL));
		int i = 0;
		while(i<5)
		{
			int num = ::rand()%100;
			_buff.push(num);
			cout<<"produce a num "<<num<<endl;
			sleep(1);
			i++;
		}
	}
};
