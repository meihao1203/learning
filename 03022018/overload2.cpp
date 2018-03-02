 ///
 /// @file    overload2.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-02 09:59:50
 ///
 
#include<iostream>
using namespace std;
template<class T>
T max1(T a,T b)  // 为什么max1,因为max和std里面有重名
{
	cout<<"template<>max(T,T)"<<endl;
	return a>b?a:b;
}
template<class T>
T max1(T a,T b,T c)
{
	cout<<"template<>max(T,T,T)"<<endl;
	return a>b?(a>c?a:c):(b>c?b:c);
}
int main()
{
	int a=1,b=2,c=3;
	double a1=1.1,b2=2.2;
	cout<<max1(a,b,c)<<endl;
	cout<<max1(a1,b2)<<endl;
	return 0;
}
//template<>max(T,T,T)
//3
//template<>max(T,T)
//2.2
