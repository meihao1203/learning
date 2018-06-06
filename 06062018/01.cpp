//复习笔记开到一个多基派生和虚基派生产生的二义性
//这里测试下虚基派生的二义性
#include<iostream>
using namespace std;
class A
{
public:
	A(int x=0):_x(x)
	{ cout<<"A(int)"<<endl; }
	void setx(int x)
	{ _x = x; }
	void print()
	{ cout<<"A::_x="<<_x<<endl; }
protected:
	int _x;
};
class B:virtual public A {};
class C:virtual public A {};
class D:public B,public C{};
int main()
{
	D d;
	cout<<"sizeof(C)="<<sizeof(C)<<endl;
	cout<<"sizeof(B)="<<sizeof(B)<<endl;
	cout<<"sizeof(D)="<<sizeof(d)<<endl;
	d.setx(5);
	d.print();
	system("pause");
	return 0;
}
//A(int)
//sizeof(C)=8
//sizeof(B)=8
//sizeof(D)=12
//A::_x=5
/*这个结果是默认对齐系数4*/

//1>  class A	size(4):
//1>  	+---
//1>   0	| _x
//1>  	+---


//1>  class B	size(8):
//1>  	+---
//1>   0	| {vbptr}
//1>  	+---
//1>  	+--- (virtual base A)
//1>   4	| _x
//1>  	+---
//1>  
//1>  B::$vbtable@:
//1>   0	| 0
//1>   1	| 4 (Bd(B+0)A)


//1>  class C	size(8):
//1>  	+---
//1>   0	| {vbptr}
//1>  	+---
//1>  	+--- (virtual base A)
//1>   4	| _x
//1>  	+---
//1>  
//1>  C::$vbtable@:
//1>   0	| 0
//1>   1	| 4 (Cd(C+0)A)

//1>  class D	size(12):
//1>  	+---
//1>  	| +--- (base class B)
//1>   0	| | {vbptr}
//1>  	| +---
//1>  	| +--- (base class C)
//1>   4	| | {vbptr}
//1>  	| +---
//1>  	+---
//1>  	+--- (virtual base A)
//1>   8	| _x
//1>  	+---
//1>  
//1>  D::$vbtable@B@:
//1>   0	| 0
//1>   1	| 8 (Dd(B+0)A)
//1>  
//1>  D::$vbtable@C@:
//1>   0	| 0
//1>   1	| 4 (Dd(C+0)A)