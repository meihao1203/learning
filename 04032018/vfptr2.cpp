 ///
 /// @file    vfptr2.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-03 09:14:17
 ///
 
#include<iostream>
using namespace std;
class A
{
	int i;
	void f();
	virtual void fun();
	virtual void fun1();
	virtual void fun2();
};
class B:virtual public A
{
	virtual void fun1();
	virtual void fun3();
};
//虚继承已经有虚函数表了，fun3()特有的，只要
//加入虚函数表就可以了
int main()
{
	cout<<"sizeof A="<<sizeof(A)<<endl;
	cout<<"sizeof B="<<sizeof(B)<<endl;
	return 0;
}
//sizeof A=16
//sizeof B=24
