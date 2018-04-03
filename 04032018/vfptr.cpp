 ///
 /// @file    vfptr.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-03 09:04:51
 ///
 
#include<iostream>
using namespace std;
class A
{
	int i;
	virtual void fun();
	virtual void fun1();
	virtual void fun2();
};
// i 4个字节，vfptr指针8个字节，内存对齐 4+4+8=16
class B:virtual public A
{
	virtual void fun();
	virtual void fun1();
};
//继承A类的i占4个字节，虚继承有虚函数表，vfptr8个字节，对齐16。
//本身虚函数，又有vfptr，8个字节，一共就是24
int main()
{
	cout<<"sizeof A="<<sizeof(A)<<endl;
	cout<<"sizeof B="<<sizeof(B)<<endl;
	return 0;
}
//sizeof A=16
//sizeof B=24
