#include<iostream>
using namespace std;
//�����̳У������麯��
class A
{
public:
	A():_ia(10){}
	void f()
	{
		cout<<"A::f()"<<endl;
	}
private:
	int _ia;
};
class B:public A
{
public:
	B():_ib(20){}
	void f(){  cout<<"B::f()"<<endl;  }
	void fb(){  cout<<"B::f()"<<endl;  }
	void fb2(){  cout<<"B::f()"<<endl;  }
private:
	int _ib;
};
int main()
{
	system("pause");
	return 0;
}
//1>  class A	size(4):
//1>  	+---
//1>   0	| _ia
//1>  	+---

//1>  class B	size(8):
//1>  	+---
//1>  	| +--- (base class A)
//1>   0	| | _ia
//1>  	| +---
//1>   4	| _ib
//1>  	+---