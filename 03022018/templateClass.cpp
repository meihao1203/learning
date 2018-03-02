 ///
 /// @file    templateClass.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-02 13:25:14
 ///
 

// 函数模板作为类模板的成员函数 
#include<iostream>
using namespace std;
template<class T>
class test
{
	public:
		template<class D>
		T convert(D);  //类内定义和类外定义，有的编译器不支持类外定义
};
template<class T>
template<class D>
T test<T>::convert(D d)
{
	return (T)d;
}
int main()
{
	test<int> t1;
	cout<<t1.convert(3.3)<<endl;  // 隐士实例化
	cout<<t1.convert<double>(4.4)<<endl;
	return 0;
}
//3
//4
