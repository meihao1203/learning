 ///
 /// @file    vtable3.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-04 14:15:01
 ///
 
//测试二：单个虚拟继承，带虚函数
//如果派生类拥有自己的虚函数(并不是覆盖),它产生的虚指针是位于虚基指针的前面的
//或者说，一个类如果有自己的虚函数，它在内存中的布局一定是位于最开始的位置，
//原因是为了提高访问虚函数的速度
#include<iostream>
using namespace std;
class A
{
	public:
		A():_ia(10){}
		virtual void f(){  cout<<"A::f()"<<endl;  }
	private:
		int _ia;
};
class B:virtual public A
{
	public:
		B():_ib(20){}
		void fb(){  cout<<"B::fb()"<<endl;  }
		virtual void f(){  cout<<"B::f()"<<endl;  }
		virtual void fb2(){ cout<<"B::fb()"<<endl; }
	private:
		int _ib;
};
int main()
{
	typedef void (*Function)(void);
	B b;
	cout<<"sizeof(b)="<<sizeof(b)<<endl;
	int** pVftable = (int**)&b;
	int pVtableAddr = *(int*)&b;  // pVtableAddr保存是虚函数表的入口地址
	int pVfuncFirstAddr = *(int*)pVtableAddr;
	Function pFun = (Function)pVfuncFirstAddr;
	pFun();
	return 0;
}
//sizeof(b)=32
//B::f()
