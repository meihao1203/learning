 ///
 /// @file    extern.cc
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-13 15:25:22
 ///
 //C++支持函数重载:　
 //实现原理：名字改编(name mangling)
 //		当函数名称相同时，会根据形参的个数，类型，顺序
 //		来进行名字改编
 //对源文件只进行编译-c，得到的目标文件.o 可以使用nm命令
 //进行查看
#include<iostream>
using std::cout;
using std::endl;
int add(int a,int b)
{
	cout<<"add(a,b)";
	return a+b;
}
int add(int a,int b,int c)   
{
	cout<<"add(a,b,c)";
	return a+b;
}
int main(void)
{
	int a = 3;
	int b = 4;
	int c;
	cout<<"a+b="<<add(a,b)<<endl;
	cout<<"a+b+c="<<add(a,b,c)<<endl;
	return 0;
}
