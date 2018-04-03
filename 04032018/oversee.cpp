 ///
 /// @file    oversee.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-03 19:24:54
 ///
 
#include<iostream>
using namespace std;
class A
{
	public:
		void fun1(char*)
		{
			cout<<"A::fun1()"<<endl;
		}
		virtual void fun2(int)
		{
			cout<<"A::fun2()"<<endl;
		}
};
class B:public A
{
	public:
		void fun1(char*)  //参数相同，但是基类不是虚函数，构成隐藏oversee
		{
			cout<<"B::fun1()"<<endl;
		}
		void fun2(int)  //函数参数不同，无论基类函数是否是虚函数，基类函数都会被隐藏oversee
		{
			cout<<"B::fun2()"<<endl;
		}
};
int main()
{
	B b;
	b.fun1("hello");
	b.fun2(2);
	return 0;
}
//B::fun1()
//B::fun2()
