 ///
 /// @file    singleton.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-02-26 16:31:35
 ///
 
// 嵌套类+静态对象实现单例类自动释放
#include<iostream>
using namespace std;
class singleton
{
	public:
		class nested;
	private:
		static singleton* _pSingleton;
		static nested _nested;
		//构造函数私有化
		singleton();
		~singleton();
	public:
		static singleton* getInstance();
		class nested
		{
			public:
				nested();
				~nested();
		};
};
//静态成员初始化
singleton* singleton::_pSingleton = singleton::getInstance();  //getInstance存放在全局静态区，必须要加上限定;  
singleton::nested singleton::_nested;
//类成员初始化
singleton::singleton()
{
	cout<<"singleton()"<<endl;
}
singleton::~singleton()  // 堆空间,只能delete来释放空间.
{
	cout<<"~singleton()"<<endl;
}
//非线程安全
singleton* singleton::getInstance()
{
	cout<<"getInstance()"<<endl;
	if(NULL==_pSingleton)
	{
		_pSingleton = new singleton;
	}
	return _pSingleton;
}
singleton::nested::nested()
{
	cout<<"nested()"<<endl;
}
singleton::nested::~nested()
{
	cout<<"~nested()"<<endl;
	if(NULL!=_pSingleton)
	{
		delete _pSingleton;
	}
}
int main()
{
	cout<<"main()"<<endl;
	singleton* p1 = singleton::getInstance();
	cout<<"p1 = %p"<<p1<<endl;
	singleton* p2 = singleton::getInstance();
	cout<<"p2 = %p"<<p2<<endl;
	return 0;  //程序结束,全局变量和静态变量都会自动释放,释放嵌套类的时候delete调用singleton的析构函数.
} // 如果不是单例类，正常的嵌套类，最后释放，先调用外部类的析构函数，完了才是嵌套类的析构函数
//getInstance()
//singleton()
//nested()
//main()
//getInstance()
//p1 = %p0x1924030
//getInstance()
//p2 = %p0x1924030
//~nested()
//~singleton()
