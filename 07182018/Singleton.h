 ///
 /// @file    Singleton.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-07-18 19:44:00
 ///
 
#include<iostream>
#include<pthread.h>
using namespace std;
namespace meihao
{
	class Singleton
	{
		public:
			static Singleton* getInstance();
			static void destroy();
		private:
			static Singleton* _pInstance;
			static pthread_once_t once_control;
		private:
			Singleton(){ cout<<"Singleton()"<<endl; } 
			~Singleton();
			static void init();
	};
};
