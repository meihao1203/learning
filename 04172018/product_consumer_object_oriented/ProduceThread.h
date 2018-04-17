 ///
 /// @file    ProduceThread.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-17 10:12:47
 ///
 
#ifndef __PRODUCETHREAD_H__
#define __PRODUCETHREAD_H__
#include<iostream>
#include"thread.h"
#include"Buffer.h"
using namespace std;
namespace meihao
{
	class ProduceThread:public Thread
	{
		public:
			ProduceThread(Buffer& buff):_buff(buff){}
			void run();
		private:
			Buffer& _buff;
	};
};
#endif
