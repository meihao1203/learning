 ///
 /// @file    overload1.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-02 09:53:50
 ///
 
#include<iostream>
using namespace std;
template<class T>
T add(T a,T b)
{
	cout<<"template<T> T add(T,T)"<<endl;
	return a+b;
}
//函数模板与确定类型的普通函数重载
int add(int a,int b)
{
	cout<<"int add(int,int)"<<endl;
	return a+b;
}
int main()
{
	int a = 2,b = 3;
	cout<<add(a,b)<<endl;  // 优先调用普通函数
	double a1 = 2.2,b1 = 3.3;
	cout<<add<double>(a1,b1)<<endl;
	return 0;
}
//int add(int,int)
//5
//template<T> T add(T,T)
//5.5
