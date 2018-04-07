 ///
 /// @file    reinterpret_cast.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-07 09:24:01
 ///
 
#include<iostream>
using namespace std;
int main()
{
	double d = 2.5;
	double* pd = &d;
	int* pi = reinterpret_cast<int*> (pd);  // 指针间的相互转换，地址赋值
	cout<<"pd="<<pd<<"\t\tpi"<<pi<<endl;
	cout<<"*pd="<<*pd<<"\t\t*pi="<<*pi<<endl;
	return 0;
}
//pd=0x7fff22c006f0		pi0x7fff22c006f0
//*pd=2.5		*pi=0
