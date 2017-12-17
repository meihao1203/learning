 ///
 /// @file    computer2.cc
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-17 08:50:04
 ///
 
#include<iostream>
#include<string.h>
using namespace std;
class computer
{
	public:
		computer(const char *brand,float price):_price(price)
		{
			_brand = new char[strlen(brand)+1];
			strcpy(_brand,brand);
		}
#if 0
		//显示定义拷贝构造函数，类就不再显示提供自己的复制构造函数
		//浅拷贝，析构函数两次释放就要core dumped
		computer(const computer &rhs)    //类成员函数，所以可以直接访问私有成员
			:_brand(rhs._brand)
			 ,_price(rhs._price)
		{
			cout<<"computer(const computer &rhs)"<<endl;
		}
#endif 
		//深拷贝
		computer(const computer &rhs)   //形参必须是对象引用，不然形参和实参结合又要发送调用拷贝构造函数，无限递归
			:_price(rhs._price)
		{
			_brand = new char[strlen(rhs._brand)+1];
			strcpy(_brand,rhs._brand);
			cout<<"computer(const computer &rhs)"<<endl;
		}
		//在类里面定义的成员函数都是inline函数
		//inline函数在调用它的地方会直接将函数执行体部分展开
		//没有函数调用的开销
		void print()
		{
			cout<<"品牌: "<<_price<<endl;
			cout<<"价格: "<<_price<<endl;
		}
		~computer()
		{
			delete []_brand;
			_brand = NULL;
			cout<<"~computer()"<<endl;
		}
		
	private:
		char *_brand;
		float _price;
};
int main(void)
{
	computer p1("ASUS",1000);
	p1.print();
	//computer p2 = p1;   //等价于下面的语句
	computer p2(p1);
	p2.print();
	return 0 ;
}
//品牌: 1000
//价格: 1000
//computer(const computer &rhs)
//品牌: 1000
//价格: 1000
//
//品牌: 1000
//价格: 1000
//computer(const computer &rhs)
//品牌: 1000
//价格: 1000
//~computer()
//~computer()
