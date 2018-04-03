 ///
 /// @file    virtualDestructure.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-03 14:55:19
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
		virtual ~Base()  // 虚析构函数
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
		~Derived()  //虚析构函数，virtual从继承结构中得来
		{
			delete []_mstr;
			cout<<"~Derived()"<<endl;
		}
	private:
		char* _mstr;
};
class DDerived:public Derived
{
	public:
		DDerived():Derived(),_mmstr(new char[32])  // 构造函数只要调用自己直接父类的构造函数就好了
		{
			cout<<"DDerived()"<<endl;
		}
		~DDerived()  //虚析构函数，virtual从继承结构中得来
		{
			delete []_mmstr;
			cout<<"~DDerived()"<<endl;
		}
	private:
		char* _mmstr;
};

int main()
{
	Base* p = new Derived;
	delete p;
	cout<<endl;
	Derived* p1 = new DDerived;
	delete p1;
	cout<<endl;
	Base* p2 = new DDerived;
	delete p2;
	cout<<endl;
	DDerived* p3 = (DDerived*)new Base;
	delete p3;
	return 0;
}
//Base()
//Derived()
//~Derived()
//~Base()
//
//Base()
//Derived()
//DDerived()
//~DDerived()
//~Derived()
//~Base()
//
//Base()
//Derived()
//DDerived()
//~DDerived()
//~Derived()
//~Base()
//
//Base()
//~Base()
