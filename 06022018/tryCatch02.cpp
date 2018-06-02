 ///
 /// @file    tryCatch02.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-06-02 15:58:27
 ///
 
//继承exeception类实现自己的异常
#include<iostream>
#include<exception>
using namespace std;
class MyException:public exception
{
	public:
		const char* what()const throw()  //函数后面必须跟throw(),括号里面不能有任务参数，表示不抛出任务异常
			//因为这个已经是一个异常处理信息了，不能再抛异常。
		{
			return "MyException";
		}
};
int main()
{
	try
	{
		throw MyException();
	}
	catch(MyException& e)  //传引用，防止调用拷贝构造函数
	{
		cout<<"this is MyException"<<endl;
		cout<<e.what()<<endl;
	}
}
//this is MyException
//MyException
