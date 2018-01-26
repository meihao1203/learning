 ///
 /// @file    complex2.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-01-26 09:33:55
 ///
 
#include<iostream>
using namespace std;
class complex1
{
	public:
		complex1(double real=0.0,double imag=0.0):_real(real),_imag(imag)
		{
			cout<<"complex1(read,imag)"<<endl;
		}
		void display()
		{
			if(0!=_real)
			{
				cout<<_real;
				if(_imag>=0)
				{
					cout<<"+"<<_imag<<"i"<<endl;
				}
				else //前面要>=0，因为如果没有=0，一个整数乘上负数还是负的，会出现--0i
				{
					cout<<"-"<<(-1)*_imag<<"i"<<endl;
				}
			}
			if(0==_real)
			{
				if(_imag>=0)
				{
					cout<<"+"<<_imag<<"i"<<endl;
				}
				else
				{
					cout<<"-"<<(-1)*_imag<<"i"<<endl;
				}
			}
		}
		complex1 operator+(const complex1 &com1);
		complex1& operator+=(const complex1 &com1);//复合赋值运算符的返回值使用引用更合理，这样可以避免返回值调用拷贝构造函数，减小开销
		complex1& operator++(); //前置++运算符，效率高于后置++
		complex1 operator++(int);
	private:
		double _real;
		double _imag;
};
complex1 complex1::operator+(const complex1 &com1)
{
	double real = this->_real+com1._real;
	double imag = this->_imag+com1._imag;
	return complex1(real,imag);
}
complex1& complex1::operator+=(const complex1 &com1)
{
	this->_real += com1._real;
	this->_imag += com1._imag;
	return *this;

}
complex1& complex1::operator++()
{
	++(this->_real);
	++(this->_imag);
	return *this;
}
complex1 complex1::operator++(int)
{
	complex1 tmp(*this); //拷贝构造函数
	++(this->_real);
	++(this->_imag);
	return tmp;
}
int main()
{
	complex1 com1(1,2);
	complex1 com2(2,-3);
	complex1 com3(0,-2);
	com1.display();
	com2.display();
	com3.display();
	complex1 com4 = com1+com2;
	com4.display();
	com3 += com1;
	com3.display();
	cout<<"******"<<endl;
	(com1++).display();
	com1.display();
	(++com2).display();
	com2.display();
	return 0;
}
//complex1(read,imag)
//complex1(read,imag)
//complex1(read,imag)
//1+2i
//2-3i
//-2i
//complex1(read,imag)
//3-1i
//1+0i
//******
//1+2i
//2+3i
//3-2i
//3-2i
