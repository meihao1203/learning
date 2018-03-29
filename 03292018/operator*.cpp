 ///
 /// @file    operator*.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-29 10:43:07
 ///
 
#include<iostream>
using namespace std;
class rational
{
	public:
		rational(int numerator=0,int denominator=1):_n(numerator),_d(denominator){cout<<"rational"<<endl;}
		~rational(){cout<<"~rational"<<endl;}
		rational(const rational&);
		int numerator()const{return _n;}
		int denomiator()const{return _d;}
	private:
		int _n;
		int _d;
};
rational::rational(const rational& rhs)
{
	cout<<"rational(const rational&)"<<endl;
	_n = rhs._n;
	_d = rhs._d;
}
const rational operator*(const rational& lhs,const rational& rhs)
{
	cout<<"operator*"<<endl;
	rational tmp(lhs.numerator()*rhs.numerator(),lhs.denomiator()*rhs.denomiator());
	return tmp;
}
int main()
{
	rational x(1,5),y(2,9);
	rational z = x*y;
	cout<<"z:"<<z.numerator()<<"/"<<z.denomiator()<<endl;
	return 0;
}
