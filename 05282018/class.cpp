 ///
 /// @file    class.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-28 19:36:57
 ///
 
#include<iostream>
using namespace std;
class test
{
	public:
		test(){}
		//~test(){};
		virtual ~test(){}
};
int main()
{
	test a;
	cout<<sizeof(a)<<endl;
}
//1

//8
