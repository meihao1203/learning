 ///
 /// @file    String.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-01-31 16:04:57
 ///
 
#include<iostream>
#include<string.h>
using namespace std;
class String
{
	public:
		String();
		String(const char*);
		String(const String&);
		~String();
		String& operator=(const String&);
		String& operator=(const char*);

		String& operator+=(const String&);
		String& operator+=(const char*);

		size_t size()const;
		const char* c_str()const;
	
		friend bool operator==(const String&,const String&);
		friend bool operator!=(const String&,const String&);

		friend bool operator<(const String&,const String&);
		friend bool operator>(const String&,const String&);
		friend bool operator<=(const String&,const String&);
		friend bool operator>=(const String&,const String&);

		friend ostream& operator<<(ostream& os,const String &s);
		friend istream& operator>>(istream& is,String &s);

		friend String operator+(const String&,const String&);
		friend String operator+(const String&,const char*);
		friend String operator+(const char*,const String&);

		void print(){ cout<<_pstr<<endl; }
	private:
		char* _pstr;
};
String::String()
{
	cout<<"String()"<<endl;
	_pstr = new char[1];
	strcpy(_pstr,"");
}
String::~String()
{
	cout<<"~String()"<<endl;
	delete []_pstr;
}
String::String(const char* tmp)
{
	cout<<"String(const char*)"<<endl;
	_pstr = new char[strlen(tmp)+1];
	strcpy(_pstr,tmp);
}
String::String(const String& tmp)
{
	cout<<"String(const String&)"<<endl;
	_pstr = new char[strlen(tmp._pstr)+1];  //深拷贝
	strcpy(_pstr,tmp._pstr);
}
String& String::operator=(const String& tmp)
{
	cout<<"String& operator=(const String&)"<<endl;
	delete []this->_pstr;
	_pstr = new char[strlen(tmp._pstr)+1];
	strcpy(_pstr,tmp._pstr);
}
String& String::operator=(const char* tmp)
{
	cout<<"String& operator=(const char*)"<<endl;
	delete []_pstr;
	_pstr = new char[strlen(tmp)+1];
	strcpy(_pstr,tmp);
}
String& String::operator+=(const String& lhs)
{
	cout<<"String& operator!=(const String&)"<<endl;
	strcat(this->_pstr,lhs._pstr);
	return *this;
}
String& String::operator+=(const char* tmp)
{
	cout<<"String& operator+=(const char*)"<<endl;
	strcat(this->_pstr,tmp);
	return *this;
}
size_t String::size()const
{
	cout<<"size_t size()const"<<endl;
	int len = strlen(this->_pstr);
	return len;
}
const char* String::c_str()const
{
	cout<<"const char* c_str()const"<<endl;
	char* tmp = new char[strlen(this->_pstr)+1];
	strcpy(tmp,this->_pstr);
	return tmp;
}
bool operator==(const String& rhs,const String& lhs)
{
	cout<<"bool operator==(const String&,const String&)"<<endl;
	if(strcmp(rhs._pstr,lhs._pstr)==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool operator!=(const String& rhs,const String& lhs)
{
	cout<<"bool operator!=(const String&,const String&)"<<endl;
	if(strcmp(rhs._pstr,lhs._pstr)==0)
	{
		 return 0;
	}
	else
	{
		return 1;
	}
}
bool operator<(const String& rhs,const String& lhs)
{
	cout<<"bool operator<(const String&,const String&)"<<endl;
	if(strcmp(rhs._pstr,lhs._pstr)<0)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}
bool operator>(const String& rhs,const String& lhs)
{
	cout<<"bool operator>(const String&,const String&)"<<endl;
	if(strcmp(rhs._pstr,lhs._pstr)>0)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}
bool operator<=(const String& rhs,const String& lhs)
{
	cout<<"bool operator<=(const String&,const String&)"<<endl;
	if(strcmp(rhs._pstr,lhs._pstr)<=0)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}
bool operator>=(const String& rhs,const String& lhs)
{
	cout<<"bool operator>=(const String&,const String&)"<<endl;
	if(strcmp(rhs._pstr,lhs._pstr)>=0)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}
ostream& operator<<(ostream& os,const String &s)
{
	cout<<"ostream& operator<<(ostream&,const String&)"<<endl;
	os<<s._pstr;
	return os;
}
istream& operator>>(istream& is,String &s)  // String()构造函数要给它赋值一个空字符串
	// 这里我第一个直接赋NULL,这里输入就段错误
{
	cout<<"istream& operator>>(istream&,String&)"<<endl;
	is>>s._pstr;
	return is;
}
String operator+(const String& rhs,const String& lhs)
{
	cout<<"String operator+(const String& rhs,const String& lhs)"<<endl;
	String tmp(rhs);
	tmp += lhs;
	return tmp;
}
String operator+(const String& rhs,const char* tmp)
{
	cout<<"String operator+(const String&,const char*)"<<endl;
	String tmps(rhs);
	strcat(tmps._pstr,tmp);
	return tmps;
}
String operator+(const char* tmp1,const String& tmp2)
{
	cout<<"String operator+(const char*,const String&)"<<endl;
	String tmps;
	strcpy(tmps._pstr,tmp1);
	strcat(tmps._pstr,tmp2._pstr);
	return tmps;
}
int main()
{
	String str1("hello,world");
	cout<<str1.c_str()<<endl;
}
