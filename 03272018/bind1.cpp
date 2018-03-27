 ///
 /// @file    bind1.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-27 09:25:22
 ///
 
#include<iostream>
#include<functional>
using namespace std;
int func(int x,int y)
{
	return x+y;
}
class A
{
	public:
	A(){  cout<<"A()"<<endl;  }
	A(const A& a){  cout<<"A(const A&)"<<endl;  }
	int func(int x,int y){  cout<<"func(x,y)"<<endl; return x+y;  }
};
int main()
{
	auto f = bind(&func,10,placeholders::_1);
	cout<<f(20)<<endl;
	A a;
	auto f2 = bind(&A::func,a,placeholders::_1,placeholders::_2);  //这里A::func必须取地址，不然报错：这不是一个静态成员;
	cout<<f2(1,2)<<endl;
	// 传参a要调用拷贝构造函数，&a表示传应用，就不会调用拷贝函数
	auto f3 = bind(&A::func,&a,placeholders::_1,placeholders::_2);
	cout<<f3(3,4)<<endl;
	auto f4 = bind(&A::func,placeholders::_1,placeholders::_2,placeholders::_3);
	cout<<f4(a,5,6)<<endl;
	cout<<f4(&a,7,8)<<endl;
	return 0;
}
//30
//A()
//A(const A&)
//func(x,y)
//3
//func(x,y)
//7
//func(x,y)
//11
//func(x,y)
//15
