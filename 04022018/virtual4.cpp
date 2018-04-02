 ///
 /// @file    virtual4.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-02 19:07:25
 ///
 
#include<iostream>
using namespace std;
class Base
{
	public:
		virtual void display()
		{
			cout<<"Base::display()"<<endl;
		}
		void play()
		{
			cout<<"Base::play()"<<endl;
		}
		void callBase1()
		{
			this->display();
		}
		void callBase2()
		{
			Base::display();
		}
};
class Derived:public Base
{
	public:
		void display()
		{
			cout<<"Derived::display()"<<endl;
		}
		void play()
		{
			cout<<"Derived::play()"<<endl;
		}
		void callDerived1()
		{
			this->display();
		}
		void callDerived2()
		{
			Base::display();
		}
};
int main()
{
	Base bb1;
	Derived dd1;
	bb1.callBase1();
	bb1.callBase2();
	dd1.callDerived1();
	dd1.callDerived2();
	cout<<endl;
	Base* pb = &bb1;
	pb->callBase1();
	pb->callBase2();
	cout<<endl;
	pb = &dd1;
	pb->callBase1();  // 动态多态性
	pb->callBase2();
	return 0;
}
//Base::display()
//Base::display()
//Derived::display()
//Base::display()
//
//Base::display()
//Base::display()
//
//Derived::display()
//Base::display()
