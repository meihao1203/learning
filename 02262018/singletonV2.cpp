 ///
 /// @file    singletonV2.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-02-26 19:58:17
 ///
 
// 单例类自动释放
#include<iostream>
#include<pthread.h>
#include<stdlib.h>
using namespace std;
class singleton
{
	public:
		static singleton* getInstance();
		static void destroy();  // main函数结束自动调用
		static void init();
	private:
		singleton();
		~singleton();
	private:
		static singleton* _pSingleton;
		static pthread_once_t once_control;
};
// 静态变量初始化
singleton* singleton::_pSingleton = NULL;
pthread_once_t singleton::once_control = PTHREAD_ONCE_INIT;

singleton::singleton()
{
	cout<<"singleton()"<<endl;
}
singleton::~singleton()
{
	cout<<"~singleton()"<<endl;
}
void singleton::destroy()
{
	cout<<"destoy()"<<endl;
	if(NULL!=_pSingleton)
	{
		delete _pSingleton;
	}
}
void singleton::init()
{
	cout<<"init()"<<endl;
	::atexit(singleton::destroy);
	if(NULL==_pSingleton)
	{
		_pSingleton = new singleton;
	}
}
singleton* singleton::getInstance()
{
	cout<<"getInstance()"<<endl;
	//::atexit(singleton::destroy);  // 注册函数,main函数结束调用
	//这里注册会注册多次，最后重复destroy,段错误
	pthread_once(&once_control,init);  // 线程安全,多次调用getInstance()只执行一次
	return _pSingleton;
}
int main()
{
	singleton* p1 = singleton::getInstance();
	singleton* p2 = singleton::getInstance();
	singleton* p3 = singleton::getInstance();
	cout<<"p1 = %p"<<p1<<endl;
	cout<<"p2 = %p"<<p2<<endl;
	cout<<"p3 = %p"<<p3<<endl;
	return 0;
	cout<<"test"<<endl;
}
//getInstance()
//init()
//singleton()
//getInstance()
//getInstance()
//p1 = %p0x1160030
//p2 = %p0x1160030
//p3 = %p0x1160030
//destoy()
//~singleton()
