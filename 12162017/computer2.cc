 ///
 /// @file    computer1.cc
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-16 08:34:26
 ///
 
#include<iostream>
#include<string.h>
using namespace std;
class computer
{
	char *_brand;
	float _price;
	public:
	computer(const char *brand,float price)
		:_price(price)
	{
		_brand = new char[strlen(brand)+1];
		strcpy(_brand,brand);
		cout<<_brand<<"构造函数"<<endl;
	}
	void print()
	{
		cout<<"computer brand is"<<_brand<<endl;
		cout<<"computer price is"<<_price<<endl;
	}
	~computer()
	{
		cout<<_brand<<"析构函数"<<endl;;
		delete []_brand;
		_brand = NULL;
	}
};
computer com1("联想",1000);
int main(void)
{
	cout<<"Enter main"<<endl;
	cout<<"com1.print()"<<endl;
	com1.print();
	computer *p = new computer("华硕",2000);
	cout<<"p->print()"<<endl;
	p->print();
	delete p;
	p = NULL;   //new创造的对象，只有在delete的时候才能释放
	static computer com2("IBM",3000);
	return 0;
}
//联想构造函数
//Enter main
//com1.print()
//computer brand is联想
//computer price is1000
//华硕构造函数
//p->print()
//computer brand is华硕
//computer price is2000
//华硕析构函数
//IBM构造函数
//IBM析构函数
//联想析构函数
