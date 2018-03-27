 ///
 /// @file    bind3.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-27 10:48:35
 ///
 
#include<iostream>
#include<functional>
using namespace std;
using namespace std::placeholders;
struct foo
{
	void sum(int x,int y) {  cout<<x+y<<endl;  }
	int data = 10;
};
int main()
{
	foo fo;
	auto f1 = bind(&foo::sum,fo,_1,_2);
	f1(1,2);
	fo.data = 12;
	auto f2 = bind(&foo::data,&fo);  // &fo,不要写fo，这样效率
	cout<<f2(10)<<endl;  // 12
	auto f3 = bind(&foo::data,_1);  // 编译通过
	f3(fo);
	cout<<f3(fo)<<endl;
}
//3
//12
//12
