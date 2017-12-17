///
/// @file    computer3.cpp
/// @author  meihao1203(meihao19931203@outlook.com)
/// @date    2017-12-17 14:15:36
///

#include<iostream>
#include<string.h>
using namespace std;
class computer
{
	char *_brand;
	float _price;
	public:
	computer(const char* brand,float price)
		:_price(price)
	{
		_brand = new char[strlen(brand)+1];
		strcpy(_brand,brand);
	}
	~computer()
	{
			delete []_brand;
			_brand = NULL;
			cout<<"~computer()"<<endl;
	}
	computer(const computer &rhs)
		:_price(rhs._price)
	{
		_brand = new char[strlen(rhs._brand)+1];
		strcpy(_brand,rhs._brand);
		cout<<"computer(const computer &)"<<endl;
	}
#if 0
	computer & operator =(const computer &rhs)  //简单的修改指针，会导致内存泄露；析构函数多次释放段错误
	{
		this->_brand = rhs._brand;
		this->_price = rhs._price;
		cout<<"computer & operator = (const computer &)"<<endl;
	}
#endif
	computer & operator = (const computer &rhs)
	{
		delete []_brand;
		_brand = NULL;
		_brand = new char[strlen(rhs._brand)+1];
		strcpy(_brand,rhs._brand);
		_price = rhs._price;
		return *this;  //返回本身
	}
	void print()
	{
		cout<<"品牌："<<_brand<<endl;
		cout<<"价格："<<_price<<endl;
	}
};
int main()
{
	computer cr1("IBM",1234.56);
	cr1.print();
	computer cr2("ASUS",7890.12);
	cr2.print();
	cr1 = cr2;  //cr1.operator=(cr2);
	cr1.print();
	return 0;
}
//品牌：IBM
//价格：1234.56
//品牌：ASUS
//价格：7890.12
//品牌：ASUS
//价格：7890.12
//~computer()
//~computer()
