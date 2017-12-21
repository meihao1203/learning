 ///
 /// @file    singleton.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-21 09:20:22
 ///
 

//要求： 内存中一个类只能产生一个对象
//1. 该对象不能是栈对象, 全局对象;   ；全局变量会破坏“封装”特性，还有对象空间程序运行期间一直存在
//2. 将构造函数放入private区域
//3. 在public区域提供一个静态成员函数
//4. 提供一个static数据成员
#include<iostream>
using namespace std;
class singleton
{
	private:
		static singleton * _pInstance;
		singleton()   //构造函数和析构函数全部私有化，防止类外定义对象，达到一个类只有一个对象实例
		{
			cout<<"singleton()"<<endl;
		}
		~singleton()
		{
			cout<<"~singleton()"<<endl;
		}
	public:
		static singleton * getInstance()
		{
			cout<<"getInstance()"<<endl;
			if(_pInstance == NULL)
			{
				_pInstance = new singleton();    //单例类，只创建一个类对象
			}
			return _pInstance;
		}
		static void destory()
		{
			cout<<"destory()"<<endl;
			delete _pInstance;   //静态数据成员，所有类对象共享，一次delete会调用析构函数全部释放
			_pInstance = NULL;
		}
};
singleton * singleton::_pInstance = NULL;
int main()
{
	singleton *p1 = singleton::getInstance();
	cout<<p1<<endl;
	singleton *p2 = singleton::getInstance();
	cout<<p2<<endl;
	singleton *p3 = singleton::getInstance();
	cout<<p3<<endl;
	singleton::destory();
}
