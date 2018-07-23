///
/// @file    factory.h
/// @author  meihao1203(meihao19931203@outlook.com)
/// @date    2018-07-22 16:34:12
///

#include<iostream>
using namespace std;
class product;
class factory
{
	public:
		factory(){ cout<<"factory()"<<endl; }
		virtual ~factory() { cout<<"~factory()"<<endl; }
		//工厂抽象类，提供造对象的纯虚函数接口
		virtual product* create() = 0;
};
class product
{
	public:
		product(){ cout<<"product()"<<endl; }
		virtual ~product(){ cout<<"~product()"<<endl; }
		virtual void display(){ cout<<"this is product display"<<endl; }
};
class A
{
	public:
		A(){ cout<<"A()"<<endl; }
		virtual ~A(){ cout<<"~A()"<<endl; }
};
class myProduct:public product
{
	public:
		myProduct(A* a):_a(a){ cout<<"myProduct()"<<endl; }
		~myProduct(){ cout<<"~myProduct()"<<endl; }
		void display(){ cout<<"this is myProduct display"<<endl; }
	private:
		A* _a;
};
//具体的工厂类创建产品对象
class myFactory:public factory
{
	public:
		myFactory(){ cout<<"myFactory()"<<endl; }
		~myFactory(){ cout<<"~myFactory()"<<endl; }
		product* create();
};

