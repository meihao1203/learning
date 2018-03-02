 ///
 /// @file    template.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-02 14:27:12
 ///
 
#include<iostream>
using namespace std;
template<class T,int num>
class A
{
	public:
		A(T a=num):_num(a)
		{
			cout<<"A()"<<endl;
		}
		int returnNum();
	private:
		T _num;
};
template<class T,int num>
int A<T,num>::returnNum()
{
	cout<<"returnNum()"<<endl;
	cout<<_num<<endl;
}
template<template<class T,int num>class T1,class T2,int num1>
void disp()
{
	cout<<"disp()"<<endl;
	T1<T2,num1> ob;
	ob.returnNum();
}
int main()
{
	disp<A,int,8>();
	return 0;
}
//disp()
//A()
//returnNum()
//8
