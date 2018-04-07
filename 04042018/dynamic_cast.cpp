 ///
 /// @file    dynamic_cast.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-04 18:26:54
 ///
 
#include<iostream>
using namespace std;
class A
{
	public:
		virtual void fun()
		{
			cout<<"A::fun()"<<endl;
		}
		void printA()
		{
			cout<<"A::printA()"<<endl;
		}
};
class B:public A
{
	public:
		virtual void fun()
		{
			cout<<"B::fun()"<<endl;
		}
		void printB()
		{
			cout<<"B::printB()"<<endl;
		}
};
int main()
{
	A* pa = new B;
	B* pb = dynamic_cast<B*>(pa);
	if(NULL==pb)
	{
		cout<<"convert1 fail!"<<endl;
	}
	else 
	{
		pb->printB();
	}
	pa = new A;
	pb = dynamic_cast<B*>(pa);
	if(NULL==pb)
	{
		cout<<"convert2 fail!"<<endl;
	}
	else 
	{
		pb->printB();
	}
	return 0;
}
