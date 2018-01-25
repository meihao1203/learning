 ///
 /// @file    complex1.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-01-25 19:51:55
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
				if(_imag>0)
				{
					cout<<"+"<<_imag<<"i"<<endl;
				}
				else
				{
					cout<<"-"<<(-1)*_imag<<"i"<<endl;
				}
			}
			if(0==_real)
			{
				if(_imag>0)
				{
					cout<<"+"<<_imag<<"i"<<endl;
				}
				else
				{
					cout<<"-"<<(-1)*_imag<<"i"<<endl;
				}
			}
		}
		friend complex1 operator+(const complex1 &com1,const complex1 &com2);
	private:
		double _real;
		double _imag;
};
complex1 operator+(const complex1 &com1,const complex1 &com2)
{
	double real = com1._real+com2._real;
	double imag = com1._imag+com2._imag;
	return complex1(real,imag);
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
