 ///
 /// @file    test1.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-01-31 11:00:49
 ///
#include<iostream>
using namespace std;
//调用运算符重载()
class compare
{
	public:
		int operator()(int a,int b)
		{
			return a>b?a:b;
		}
		double operator()(double a,double b,double c)
		{
			return a>b?(a>c?a:c):(b>c?b:c);
		}
};
int main()
{
	compare com1;
	cout<<com1(2,3)<<endl;
	cout<<com1.operator()(2,3)<<endl; //函数对象，泛型思考问题的方式
	cout<<com1(3.3,2.3,6.7)<<endl;
	cout<<com1.operator()(3.3,2.3,6.7)<<endl;
	return 0;
}
//3
//3
//6.7
//6.7
