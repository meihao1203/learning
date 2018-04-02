 ///
 /// @file    drived.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-02 10:04:41
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
			cout<<"operator=(const base&)"<<endl;
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
			cout<<_buf<<endl;
		}
	private:
		char* _buf;
};
class drived:public base
{
	public:
		drived(const char* buf):base(buf){  cout<<"drived::drived(const char*)"<<endl;  }
};
int main()
{
//当派生类没有定义复制构造函数，而基类显示的定义了复制构造函数，
//则派生类对象之间进行复制时，会自动调用基类复制构造函数
	drived d1("hello");
	d1.display();
	drived d2("world");
	d2.display();
	cout<<endl;
	d1 = d2;  //派生类使用缺省的赋值构造函数，基类调用用户定义的赋值构造函数
	d1.display();
	cout<<endl;
	drived d3(d1);
	d3.display();
	return 0;
}
//base::base(const char*)
//drived::drived(const char*)
//hello
//base::base(const char*)
//drived::drived(const char*)
//world
//
//operator=(const base&)
//world
//
//base::base(const base&)
//world
