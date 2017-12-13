 ///
 /// @file    extern.cc
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-13 15:25:22
 ///
 
#include<iostream>
using std::cout;
using std::endl;
//编译带上-D meihao 就要报错，两个一样的函数 
#ifdef meihao
int add(int a,int b)
{
	cout<<"add(a,b)";
	return a+b;
}
#endif
//默认参数或者缺省参数的赋值只能从右到左进行
int add(int a,int b,int c=1)   //这里如果最后一个参数缺省赋值了，就和上面的构不成重载
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
