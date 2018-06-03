 ///
 /// @file    tryCatch.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-06-03 09:21:15
 ///
 
#include<iostream>
#include<exception>
using namespace std;
void func()
{
	throw *(new exception());
}
int main()
{
	int i = 0;
	try
	{
		func();
	}
	catch(exception& e)
	{
		cout<<e.what()<<endl;
		cout<<"hello,world"<<endl;
	}
}
//std::exception
//hello,world
