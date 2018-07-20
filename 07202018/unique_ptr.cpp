 ///
 /// @file    unique_ptr.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-07-20 11:38:59
 ///
 
#include<iostream>
#include<memory>
using namespace std;
unique_ptr<int> getValue()
{
	unique_ptr<int> upi(new int(88));
	return upi;
}
int main()
{
	unique_ptr<int> tmp = getValue();
	cout<<*tmp<<endl;
}
