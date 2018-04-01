 ///
 /// @file    virtual.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-01 11:19:43
 ///
 
#include<iostream>
using namespace std;
class A
{
	public:
		A(int x=0):_x(x){}
		void setX(int x)
		{
			_x = x;
		}
		void print()
		{
			cout<<"A::print()"<<_x<<endl;
		}
	private:
		int _x;
};
class B:virtual public A{};
class C:virtual public A{};
class D:public B,public C{};
int main()
{
	D d ;
	cout<<"sizeof(A)="<<sizeof(A)<<endl;
	cout<<"sizeof(B)="<<sizeof(B)<<endl;
	cout<<"sizeof(C)="<<sizeof(C)<<endl;
	cout<<"sizeof(D)="<<sizeof(D)<<endl;
	d.print();
	d.setX(5);
	d.print();
	return 0;
}
//sizeof(A)=4
//sizeof(B)=16
//sizeof(C)=16
//sizeof(D)=24
//A::print()0
//A::print()5
