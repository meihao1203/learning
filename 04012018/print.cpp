 ///
 /// @file    print.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-01 10:27:23
 ///
 
#include<iostream>
using namespace std;
class A
{
	public:
		void display()
		{
			cout<<"A::display()"<<endl;
		}
};
class B
{
	public:
		void display()
		{
			cout<<"B::display()"<<endl;
		}
};
class C:public A,public B
{
	public:
		void play()
		{
			A::display();
			B::display();
		}
		void display()
		{
			if(true) B::display();
			else     A::display();
		}
};
int main()
{
	C c;
	c.play();
	cout<<endl;
	c.A::display();
	c.display();  // 默认调用类C里面的display
	return 0;
}
//A::display()
//B::display()
//
//A::display()
//B::display()
