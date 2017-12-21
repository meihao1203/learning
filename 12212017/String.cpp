 ///
 /// @file    String.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-21 08:21:00
 ///
 
#include<iostream>
#include<string.h>
using namespace std;
class String
{
	private:
		char *_pstr;
	public:
		String()
		{
			cout<<"String()"<<endl;
			_pstr = new char[1];
			strcpy(_pstr,"");
		}
		String(const char *pstr)
		{
			cout<<"String(const char *)"<<endl;
			_pstr = new char[strlen(pstr)+1];
			strcpy(_pstr,pstr);
		}
		String(const String &rhs)
		{
			cout<<"String(const String &)"<<endl;
			_pstr = new char[strlen(rhs._pstr)+1];
			strcpy(_pstr,rhs._pstr);
		}
		String & operator=(const String &rhs)
		{
			cout<<"operator=(const String &)"<<endl;
			if(rhs._pstr == this->_pstr)
				return *this ;
			delete []_pstr;
			_pstr = new char[strlen(rhs._pstr)+1];
			strcpy(_pstr,rhs._pstr);
		}
		void print()
		{
			cout<<"print():"<<_pstr<<endl;
		}
		~String()
		{
			cout<<"~String()"<<endl;
			delete []_pstr;
			_pstr = NULL;
		}
};
int main()
{
	String str1;
	str1.print();
	
	String str2 = "Hello,world";   //构造函数，隐士转化;  加上explicit就要报错了
	String str3 = "meihao";
	str2.print();
	str3.print();
	
	String str4 = str3;     //拷贝构造函数
	str4.print();

	str4 = str2;     //赋值运算符重载
	str4.print();
	return 0;
}
//String()
//print():
//String(const char *)
//String(const char *)
//print():Hello,world
//print():meihao
//String(const String &)
//print():meihao
//operator=(const String &)
//print():Hello,world
//~String()
//~String()
//~String()
//~String()
