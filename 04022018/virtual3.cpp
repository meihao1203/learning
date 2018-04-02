 ///
 /// @file    virtual3.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-02 17:03:37
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
			cout<<"derived::play()"<<endl;
		}
};
int main()
{
	Base base;
	Base* ba = &base;
	ba->display();
	ba->play();
	Base& ref = base;
	ref.display();
	ref.play();
	cout<<endl;
	Derived derived;
	ba = &derived;
	ba->display();
	ba->play();
	cout<<endl;
	Base& ref2 = derived;
	ref2.display();
	ref2.play();
	Base base2;
	ref2 = base2;  //引用一经声明，调用的函数就不会在改变，因为地址是不会改变的，虽然值改变了
	ref2.display();
	return 0;
}
//Base::display()
//Base::play()
//Base::display()
//Base::play()
//
//Derived::display()
//Base::play()
//
//Derived::display()
//Base::play()
//Derived::display()
