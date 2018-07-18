 ///
 /// @file    Singleton.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-07-18 19:49:55
 ///
 
#include<iostream>
#include<stdlib.h>
#include<pthread.h>
#include"Singleton.h"
using namespace std;
namespace meihao
{
	Singleton* Singleton::_pInstance = NULL;
	pthread_once_t Singleton::once_control = PTHREAD_ONCE_INIT;
	void Singleton::init()
	{
		cout<<"init()"<<endl;
		::atexit(Singleton::destroy);
		if(NULL==_pInstance)
		{
			_pInstance = new Singleton;
		}
	}
	Singleton* Singleton::getInstance()
	{
		cout<<"getInstance()"<<endl;
		pthread_once(&once_control,Singleton::init);
		return _pInstance;
	}
	Singleton::~Singleton()
	{
		cout<<"~Singleton()"<<endl;
	}
	void Singleton::destroy()
	{
		cout<<"destroy()"<<endl;
		if(NULL!=_pInstance)
		{
			delete _pInstance;
			_pInstance = NULL;
		}
	}
};
