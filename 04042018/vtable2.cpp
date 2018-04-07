 ///
 /// @file    vtable2.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-04 14:04:01
 ///
 
#include<iostream>
using namespace std;
//测试一：单个虚拟继承，不带虚函数	
//虚拟继承与继承的区别：
//1. 虚基类处于对象内存的末尾
//2. 多了一个虚基指针
class A
{
	public:
		A():_ia(10){}
		void f(){  cout<<"A::f()"<<endl;  }
	private:
		int _ia;
};
class B:virtual public A
{
	public:
		B():_ib(20){}
		void fb(){  cout<<"B::fb()"<<endl;  }
		void f(){  cout<<"B::f()"<<endl;  }
		void fb2(){ cout<<"B::fb()"<<endl; }
	private:
		int _ib;
};// 类A大小4，虚继承有一个虚基指针8,8+4+4=16；最后一个4是B类自己的成员_ib的大小
int main()
{
	B b;
	cout<<"sizeof(b)="<<sizeof(b)<<endl;
	return 0;
}
//sizeof(b)=16
