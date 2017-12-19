 ///
 /// @file    staticFunc.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-19 10:21:31
 ///
 
#include<iostream>
#include<string.h>
using namespace std;
class computer
{
	private:
		float _price;
		char *_brand;
		static float _sprice;
		static void printTotalprice()
		{
			cout<<"总价格："<<_sprice<<endl;
		}
	public:
		computer(const char *brand,float price):_price(price)
		{
			cout<<"computer(const char*,float)"<<endl;
			_brand = new char[strlen(brand)+1];
			strcpy(_brand,brand);
			_sprice += _price;
		}
		~computer()
		{
			delete []_brand;
			_brand = NULL;
			_sprice -= _price;
			cout<<"~computer()"<<endl;
		}
		static void print(const computer &rhs)
		{
			cout<<"品牌："<<rhs._brand<<endl;   //非静态成员，要在静态函数内调用，没有this指针
			//只能把类对象传递进来
			cout<<"价格："<<rhs._price<<endl;
			printTotalprice();   //静态成员函数，只能内部调用静态成员函数
		}
};
float computer::_sprice = 0;
int main(void)
{
	computer cr("IBM",1000);
	computer::print(cr);   //静态函数所有类对象共享，不能对象调用，只能加类名作用域
	computer cr2("lenovo",2000);
	computer::print(cr2);
	{
		computer cr3("ASUS",3000);
		computer::print(cr3);
	}
	computer::print(cr2);
	return 0;
}
//computer(const char*,float)
//品牌：IBM
//价格：1000
//总价格：1000
//computer(const char*,float)
//品牌：lenovo
//价格：2000
//总价格：3000
//computer(const char*,float)
//品牌：ASUS
//价格：3000
//总价格：6000
//~computer()
//品牌：lenovo
//价格：2000
//总价格：3000
//~computer()
//~computer()
