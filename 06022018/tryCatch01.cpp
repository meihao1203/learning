 ///
 /// @file    tryCatch01.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-06-02 15:18:08
 ///
 
#include<iostream>
using namespace std;
double division(int a,int b)
{
	if(0==b)  //除数为0，抛出异常
	{
		throw "除数不能为0";   //异常类型是const char *
	}
	return a/b;
}
int main()
{
	int a = 4, b = 0;
	int res;
	try
	{//保护代码
		res = division(a,0);
	}
//	catch(const char* msg)
//	{
//		cout<<msg<<endl;
//	}
	catch(...)
	{
		cout<<"有异常产生"<<endl;
	}
	cout<<"res = "<<res<<endl;
	return 0;
}
//除数不能为0
//res = 0
