 ///
 /// @file    num2.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-02-27 12:35:15
 ///
 
#include<iostream>
using namespace std;
template<class T>
T add(T a,T b)
{
	cout<<"template<class T>add(T)"<<endl;
	return a+b;
}
template<>  // 模板特化，必须先有上面的通用模式，又能有特化的形式，优先执行
double add(double a,double b)
{
	cout<<"template<>add(double)"<<endl;
	return a+b;
}
int main()
{
	cout<<add(1,2)<<endl;
	cout<<add<int>(1,2)<<endl;
	cout<<add(1.1,2.2)<<endl;
	return 0;
}
//template<class T>add(T)
//3
//template<class T>add(T)
//3
//template<>add(double)
//3.3
