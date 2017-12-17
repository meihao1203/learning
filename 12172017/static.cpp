 ///
 /// @file    static.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-17 18:59:58
 ///
 
#include<iostream>
using namespace std;
class computer
{
	private:
		float _cprice;
		static float _price;
	public:
		computer(float cprice=0):_cprice(cprice)
		{
			_price += _cprice;
			cout<<"computer(float)"<<endl;
		}
		void print()
		{
			cout<<"总价格："<<_price<<endl;
		}
		~computer()
		{
			_price -= _cprice;
			cout<<"~computer()"<<endl;
		}
};
float computer::_price = 0;
int main(void)
{
	computer cr1(1000);
	cr1.print();
	computer cr2(2000);
	cr2.print();
	computer cr3(3000);
	cr3.print();
	cr3.~computer();
	cr2.print();
	return 0;
}
//computer(float)
//总价格：1000
//computer(float)
//总价格：3000
//computer(float)
//总价格：6000
//~computer()
//总价格：3000
//~computer()
//~computer()
//~computer()
