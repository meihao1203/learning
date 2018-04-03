 ///
 /// @file    destructure.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-03 14:44:19
 ///
 
#include<iostream>
using namespace std;
class Base
{
	public:
		Base():_str(new char[32])
		{
			cout<<"Base()"<<endl;
		}
		~Base()
		{
			delete []_str;
			cout<<"~Base()"<<endl;
		}
	private:
		char* _str;
};
class Derived:public Base
{
	public:
		Derived():Base(),_mstr(new char[32])
		{
			cout<<"Derived()"<<endl;
		}
		~Derived()
		{
			delete []_mstr;
			cout<<"~Derived()"<<endl;
		}
	private:
		char* _mstr;
};
int main()
{
	Base* p = new Derived;
	delete p;
	return 0;
}
//Base()
//Derived()
//~Base()
