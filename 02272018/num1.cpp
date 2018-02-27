 ///
 /// @file    num1.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-02-27 10:46:04
 ///
 
#include<iostream>
using namespace std;
template<class T,int num>
T add(T);  // 函数模板声明

int main()
{
	//add(3,4);  // 函数模板带有常量,不能隐士实例化
	cout<<add<int,4>(3)<<endl;  // 只能显示实例化
	return 0;
}

//函数模板的实现必须在同一个文件里面，
//.cpp实现，要在main文件里include".cpp"
template<class T,int num>
T add(T a)
{
	return a+num;
}
