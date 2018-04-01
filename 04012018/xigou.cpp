 ///
 /// @file    xigou.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-01 14:26:26
 ///
 
// 单基派生类的析构函数
#include<iostream>
using namespace std;
class A
{
	public:
		A(int x=0):_x(x)
		{
			cout<<"A()"<<endl;
		}
		~A()
		{
			cout<<"~A()"<<endl;
		}
		int getx()
		{
			return _x;
		}
	private:
		int _x;
};
class B
{
	public:
		B(){ cout<<"B()"<<endl; }
		~B(){ cout<<"~B()"<<endl; }
};
class C:public A
{
	public:
		C(int x,int y):_y(y),_b(),A(x)
		{
			cout<<"C(int,int)"<<endl;
		}
		~C()
		{
			cout<<"~C()"<<endl;
		}
		void print()
		{
			cout<<"("<<getx()<<","<<_y<<")"<<endl;
		}
	private:
		int _y;
		B _b;
};
int main()
{
	C c(1,2);
	c.print();
	return 0;
}
//A()
//B()
//C(int,int)
//(1,2)
//~C()
//~B()
//~A()
