 ///
 /// @file    const_cast.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-07 08:45:35
 ///
 
#include<iostream>
using namespace std;
int main()
{
	int i = 5;
	const int* p = &i;
	//*p = 6;  // 不能被修改了
	cout<<"i="<<i<<endl;
	cout<<"(*p)="<<*p<<endl<<endl;
	int* p2 = const_cast<int*> (p);
	*p2 = 6;
	//*p = 7;  // p指向的单元依然不可以修改
	cout<<"i="<<i<<endl;
	cout<<"(*p)="<<*p<<endl<<endl;
	return 0;
}
//i=5
//(*p)=5
//
//i=6
//(*p)=6
//
