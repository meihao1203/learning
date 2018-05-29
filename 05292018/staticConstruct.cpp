 ///
 /// @file    staticConstruct.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-29 10:56:49
 ///
 
#include<iostream>
using namespace std;
class A
{
	public:
		//C++静态构造函数不能定义，编译报错
		//C#可以
		//static A(){ cout<<"static A()"<<endl; }
		~A(){ cout<<"~A()"<<endl; }
};
int main()
{

}
