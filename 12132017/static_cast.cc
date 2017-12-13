 ///
 /// @file    static_cast.cc
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-13 16:36:04
 ///
 
#include<iostream>
using std::cout;
using std::endl;
int main(void)
{
	double b = 3.14159;
	int a = (int)b;
	int c = int(b);
	int e = (int)(b);
	cout<<"a="<<a<<endl;
	cout<<"c="<<c<<endl;
	cout<<"e="<<e<<endl;

	int d = static_cast<int>(b);
	cout<<"d="<<d<<endl;
	return 0;
}
