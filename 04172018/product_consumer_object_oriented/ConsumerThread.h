 ///
 /// @file    ConsumerThread.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-17 10:30:08
 ///
 
#ifndef __CONSUMERTHREAD_H__
#define __CONSUMERTHREAD_H__
#include<iostream>
#include"thread.h"
#include"Buffer.h"
using namespace std;
namespace meihao
{
	class ConsumerThread:public Thread
	{
		public:
			ConsumerThread(Buffer& buff):_buff(buff){}
			void run();
		private:
			Buffer& _buff;
	};
};
#endif
