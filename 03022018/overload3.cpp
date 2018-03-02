 ///
 /// @file    overload3.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-02 10:21:40
 ///
 
// 函数模板和数组的重载
#include<iostream>
using std::cout;
using std::endl;
template<class T>
T max(T a,T b)
{
	cout<<"max(T,T)"<<endl;
	return a>b?a:b;
}
template<class T>
//T max(T *a,T b)  // T max(T a[],T b)  // 都是错的
T max(T* a,int b)
{
	cout<<"max(T*,T)"<<endl;
	T tmp = 1>>sizeof(T);
	for(int i=1;i!=b;++i)
	{
		tmp = tmp>a[i]?tmp:a[i];
	}
	return tmp;
}
int main()
{
	int a[] = {1,2,6,4,5};
	int a1 = 1,a2 = 2;
	cout<<max(a1,a2)<<endl;
	cout<<max(a,sizeof(a)/sizeof(int))<<endl;
	return 0;
}
//max(T,T)
//2
//max(T*,T)
//6
