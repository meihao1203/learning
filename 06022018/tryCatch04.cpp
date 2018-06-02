 ///
 /// @file    tryCatch04.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-06-02 19:56:24
 ///
 
#include<iostream>
#include<exception>
using namespace std;
class myException:public exception
{
	public:
		myException(const char* str):_str(const_cast<char*>(str)) { }
		virtual ~myException()throw() { cout<<"~myException()"<<endl; }
		//析构函数不能抛出异常，不许加异常规格说明throw()
		const char* what()
		{
			return _str;
		}
	private:
		char* _str;
};
int func(int a ,int b)throw(myException)
{
	if(0==b)
	{
	//	myException* me = new myException("除数不能为0");
	//	throw *me;	
		throw *(new myException("除数不能为0"));  //两种都可以
	}
	return a/b;
}
int main()
{
	int a = 5,b = 0;
	int res;
	try
	{
		res = func(a,b);
	}
	catch(myException& e)
	{
		cout<<e.what()<<endl;
	//	delete &e;
		//已经释放了，不用再释放了
	}
	cout<<res<<endl;
	return 0;
}
//除数不能为0
//~myException()
//0
