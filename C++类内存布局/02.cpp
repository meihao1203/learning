#include<iostream>
using namespace std;
//单个继承，带虚函数
class A
{
public:
	A():_ia(10){}
	virtual void f(){  cout<<"A::f()"<<endl;  }
	void fa(){  cout<<"A::fa()"<<endl;  }
	virtual ~A() { cout<<"~A()"<<endl; }
private:
	int _ia;
};
class B:public A
{
	B():_ib(20){}
	//void f(){  cout<<"B::f()"<<endl;  }
	//virtual void f2(){  cout<<"B::f2()"<<endl;  }
	void f3(){  cout<<"B::f3()"<<endl;  }
private:
	int _ib;
};
int main()
{
	return 0;
}
//1>  class A	size(8):
//1>  	+---
//1>   0	| {vfptr}
//1>   4	| _ia
//1>  	+---
//1>  
//1>  A::$vftable@:
//1>  	| &A_meta
//1>  	|  0
//1>   0	| &A::f
//1>  
//1>  A::f this adjustor: 0

//1>  class B	size(12):
//1>  	+---
//1>  	| +--- (base class A)
//1>   0	| | {vfptr}
//1>   4	| | _ia
//1>  	| +---
//1>   8	| _ib
//1>  	+---
//1>  
//1>  B::$vftable@:
//1>  	| &B_meta
//1>  	|  0
//1>   0	| &B::f
//1>   1	| &B::f2
//1>  
//1>  B::f this adjustor: 0
//1>  B::f2 this adjustor: 0

//派生类没有虚函数

//1>  class B	size(12):
//1>  	+---
//1>  	| +--- (base class A)
//1>   0	| | {vfptr}
//1>   4	| | _ia
//1>  	| +---
//1>   8	| _ib
//1>  	+---
//1>  
//1>  B::$vftable@:
//1>  	| &B_meta
//1>  	|  0
//1>   0	| &A::f