 ///
 /// @file    override.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-03 17:01:12
 ///
 
#include<iostream>
using namespace std;
class A
{
	public:
		virtual void fun1()
		{
			cout<<"A::fun1()"<<endl;
		}
		virtual void fun2()
		{
			cout<<"A::fun2()"<<endl;
		}
};
class B:public A
{
	public:
		void fun1()  // B中的fun1覆盖了A中的fun1，同时继承了A中的fun2
		{
			cout<<"B::fun1()"<<endl;
		}
};
class C:public B
{
	public:
		void fun2()
		{
			cout<<"C::fun2()"<<endl;  //C类继承了B中的fun1，同时重定义覆盖了fun2
		}
};
int main()
{
	A* p = new C;
	p->fun1();
	p->fun2();
	return 0;
}
//B::fun1()
//C::fun2()
