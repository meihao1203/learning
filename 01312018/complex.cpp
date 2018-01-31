 ///
 /// @file    complex.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-01-31 15:12:39
 ///
 
#include<iostream>
#include<stdio.h>
using namespace std;
class complex1
{
	public:
		complex1(double real=0,double imag=0):_real(real),_imag(imag){};
		friend ostream& operator<<(ostream& os,const complex1& rhs);
		friend istream& operator>>(istream& in,complex1& rhs);
	private:
		double _real;
		double _imag;
};
ostream& operator<<(ostream& os,const complex1& rhs)
{
	os<<rhs._real;
	if(rhs._imag>0)
	{
		os<<"+"<<rhs._imag<<"i"<<endl;
	}
	else if(rhs._imag<0)
	{
		os<<"-"<<rhs._imag*(-1)<<"i"<<endl;
	}
	return os;
}
istream& operator>>(istream& in,complex1& rhs)
{
	in>>rhs._real;
	while(in.get()!='*')
	in>>rhs._imag;
	return in;
}
int main()
{
	complex1 com1(1,-2);
	cout<<com1;
	complex1 com2;
	cin>>com2;
	cout<<com2;
	fflush(stdin);
	return 0;
}
//1-2i
//3
//4
//3+4i
