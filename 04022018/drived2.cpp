 ///
 /// @file    drived2.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-02 10:38:06
 ///
 
#include<iostream>
#include<string.h>
using namespace std;
class base
{
	public:
		base(const char* buf):_buf(new char[strlen(buf)+1])
		{
			cout<<"base::base(const char*)"<<endl;
			strcpy(_buf,buf);
		}
		base(const base& rhs):_buf(new char[strlen(rhs._buf)+1])
		{
			cout<<"base::base(const base&)"<<endl;
			strcpy(_buf,rhs._buf);
		}
		base& operator=(const base& rhs)
		{
			cout<<"base& operator=(const base&)"<<endl;
			if(this!=&rhs)
			{
				delete []_buf;
				_buf = new char[strlen(rhs._buf)+1];
				strcpy(_buf,rhs._buf);
			}
			return *this;
		}
		void display()
		{
			cout<<_buf;
		}
	private:
		char* _buf;
};
class drived:public base
{
	public:
		drived(const char* buf,const char* buf2):base(buf),_dbuf(new char[strlen(buf2)+1])
		{// 派生类显示定义了构造函数就不会在自动调用基类构造函数
		 // 派生类必须显示调用基类构造函数
			cout<<"drived::drived(const char*,const char*)"<<endl;
			strcpy(_dbuf,buf2);
		}
		drived(const drived& rhs):base(rhs),_dbuf(new char[strlen(rhs._dbuf)+1])
		{//显示调用基类的复制构造函数
		 //不显示调用基类构造函数会导致最后基类调用默认的构造函数
			cout<<"drived::dirved(const drived&)"<<endl;
			strcpy(_dbuf,rhs._dbuf);
		}
		drived& operator=(const drived& rhs)
		{
			cout<<"drived& operator="<<endl;
			if(this!=&rhs)
			{
				base::operator=(rhs);  //显示调用基类的赋值运算符函数
				delete []_dbuf;
				_dbuf = new char[strlen(_dbuf)+1];
				strcpy(_dbuf,rhs._dbuf);
			}
			return *this;
		}
		void display()
		{
			base::display();
			cout<<" "<<_dbuf;
			cout<<endl;
		}
	private:
		char* _dbuf;
};
int main()
{
	drived d1("hello","world");
	d1.display();
	drived d2("C++","learning");
	d2.display();
	cout<<endl;
	d1 = d2;
	d1.display();
	d2.display();
	cout<<endl;
	drived d3 = d1;
	d3.display();
	return 0;
}
//base::base(const char*)
//drived::drived(const char*,const char*)
//hello world
//base::base(const char*)
//drived::drived(const char*,const char*)
//C++ learning
//
//drived& operator=
//base& operator=(const base&)
//C++ learning
//C++ learning
//
//base::base(const base&)
//drived::dirved(const drived&)
//C++ learning
