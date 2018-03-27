 ///
 /// @file    bind2.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-27 10:19:35
 ///
 
#include<iostream>
#include<functional>
using namespace std;
using namespace std::placeholders;
void func(int x,int y,int z,const int& u,int& e)
{
	cout<<"("<<x<<" "<<y<<" "<<z<<" "<<u<<" "<<e<<")"<<endl;
}
struct foo
{
	int data = 10;
};
int main()
{
	int n=10,m=8;
	auto f = bind(&func,_2,_1,42,cref(n),ref(m));  // cref 和 ref 里面不能直接写数字，数字表示的是一个右值，不能引用
	f(2,1);
	n = 11;
	f(3,4,5,6,7,8);  // 绑定在多数也没用
    foo fo; fo.data = 12;
	auto f2 = bind(&foo::data,fo);
	cout<<f2(fo)<<endl;  // 搞不懂为什么还要这样写
	auto f3 = bind(&foo::data,_1);
	cout<<f3(fo)<<endl;
}
//(1 2 42 10 8)
//(4 3 42 11 8)
//12
//12
