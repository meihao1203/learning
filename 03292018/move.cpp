 ///
 /// @file    move.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-29 09:28:09
 ///
 
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
class String
{
	public:
		//定义正常的构造函数
		String():_str(new char[1]){}
		String(const char*);
		String(const String&);
		String& operator=(const String&);
		void swap(String&);

		//当同时定义了复制构造函数和移动构造函数时,如果传递的
		//实参就是右值时,会优先调用移动构造函数;同理,移动赋值
		//运算符函数也有这样的优先权
		String(String&&);
		String& operator=(String&&);

		~String();
	private:
		char* _str;
		friend ostream& operator<<(ostream&,const String&);
};
String::String(const char* str)
{
	cout<<"String(char*)"<<endl;
	_str = new char[strlen(str)+1];
	strcpy(_str,str);
}
String::~String()
{
	cout<<"~String()"<<endl;
	delete []_str;
	_str = NULL;
}
String::String(const String& rhs)
{
	cout<<"String(const Stirng)"<<endl;
	_str = new char[strlen(rhs._str)+1];
	strcpy(_str,rhs._str);
}
void String::swap(String& rhs)
{
	cout<<"swap(String&)"<<endl;
	char* tmp;
	tmp = _str;
	_str = rhs._str;
	rhs._str = _str;
}
String& String::operator=(const String& rhs)
{
	cout<<"operator=(const String&)"<<endl;
	String tmp(rhs);  // 这里用局部变量来赋值，离开作用域就会自动调用析构函数，释放了rhs的空间
	swap(tmp);  // 参数为引用，防止调用拷贝构造函数
}
ostream& operator<<(ostream& os,const String& rhs)
{
	os<<rhs._str;
}
///
//移动构造函数
String::String(String&& rhs)
{
	cout<<"String(String&&)"<<endl;
	_str = rhs._str;
	rhs._str = NULL;
}
//移动赋值运算符
String& String::operator=(String&& rhs)
{
	cout<<"operator=(String&&)"<<endl;
	delete []_str;
	_str = rhs._str;
	rhs._str = NULL;
}
int main()
{
	String s1("hello");
	String s2("world");
	cout<<"s1="<<s1<<" "<<"s2="<<s2<<endl;
	String s3 = String("meihao");  // String(const char*)
	//定义了移动构造函数，这里就会调用operator=(String&&)
	cout<<s3<<endl;
	s2 = move(s1);  // 显示的将左值转换成右值
	cout<<"s2="<<s2<<endl;
	cout<<"-------"<<endl;
	//cout<<"s1="<<s1<<endl;  // 当使用std::move函数将某个对象s1转成右值后,
	// s1不能再使用
	cout<<cin.good()<<endl;
	cout<<"s3="<<s3<<endl;
	return 0;
}
/// 有输出s1
//String(char*)
//String(char*)
//s1=hello s2=world
//String(char*)
//String(String&&)
//~String()
//meihao
//operator=(String&&)
//s2=hello
//s1=[meihao@ubuntu ~/learning/03292018]$>
//
////
//String(char*)
//String(char*)
//s1=hello s2=world
//String(char*)
//String(String&&)
//~String()
//meihao
//operator=(String&&)
//s2=hello
//1
//s3=meihao
//~String()
//~String()
//~String()
