 ///
 /// @file    copyStructure.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-28 19:43:51
 ///
 
#include<iostream>
using namespace std;
class A
{
	public:
		A(int n){_value = n;}
		A(const A& other){_value = other._value;}
		void print(){cout<<_value<<endl;}
	private:
		int _value;
};
int main()
{
	A a = 10;
	A b = a;
	b.print();
}
