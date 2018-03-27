 ///
 /// @file    mem_fn.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-27 15:03:08
 ///
 
//成员函数适配器
#include<iostream>
#include<functional>
using namespace std;
using namespace std::placeholders;
struct foo
{
	void display_greeting(){  cout<<"hello,world!"<<endl;  }
	void display_num(int n){  cout<<n<<endl;  }
	int data = 7;
};
int main()
{
	foo fo;
	auto f1 = mem_fn(&foo::display_greeting);  // _1这个占位符可要可不要
	f1(fo);
	auto f2 = mem_fn(&foo::display_num);
	f2(fo,6);
	auto f3 = mem_fn(&foo::data);
	cout<<f3(fo)<<endl;
	return 0;
}
//hello,world!
//6
//7
