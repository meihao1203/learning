#include<iostream>
using namespace std;
//多重继承，带虚函数
class Base1
{
public:
	Base1():_iBase1(10){}
	virtual void f(){}
	virtual void g(){}
	virtual void h(){}
private:
	int _iBase1;
};
class Base2
{
public:
	Base2():_iBase2(100){}
	virtual void f(){}
	virtual void g(){}
	virtual void h(){}
private:
	int _iBase2;
};
class Base3
{
public:
	Base3():_iBase3(1000){}
	virtual void f(){}
	virtual void g(){}
	virtual void h(){}
private:
	int _iBase3;
};
class Derived:public Base1,public Base2,public Base3
{
public:
	Derived():_iDerived(10000){}
	void f(){}
	virtual void g1(){}
private:
	int _iDerived;
};
int main()
{
	return 0;
}
//1>  class Base1	size(8):
//1>  	+---
//1>   0	| {vfptr}
//1>   4	| _iBase1
//1>  	+---
//1>  
//1>  Base1::$vftable@:
//1>  	| &Base1_meta
//1>  	|  0
//1>   0	| &Base1::f
//1>   1	| &Base1::g
//1>   2	| &Base1::h

//1>  class Derived	size(28):
//1>  	+---
//1>  	| +--- (base class Base1)
//1>   0	| | {vfptr}
//1>   4	| | _iBase1
//1>  	| +---
//1>  	| +--- (base class Base2)
//1>   8	| | {vfptr}
//1>  12	| | _iBase2
//1>  	| +---
//1>  	| +--- (base class Base3)
//1>  16	| | {vfptr}
//1>  20	| | _iBase3
//1>  	| +---
//1>  24	| _iDerived
//1>  	+---
//1>  
//1>  Derived::$vftable@Base1@:
//1>  	| &Derived_meta
//1>  	|  0
//1>   0	| &Derived::f
//1>   1	| &Base1::g
//1>   2	| &Base1::h
//1>   3	| &Derived::g1
//1>  
//1>  Derived::$vftable@Base2@:
//1>  	| -8
//1>   0	| &thunk: this-=8; goto Derived::f
//1>   1	| &Base2::g
//1>   2	| &Base2::h
//1>  
//1>  Derived::$vftable@Base3@:
//1>  	| -16
//1>   0	| &thunk: this-=16; goto Derived::f
//1>   1	| &Base3::g
//1>   2	| &Base3::h
//1>  
//1>  Derived::f this adjustor: 0
//1>  Derived::g1 this adjustor: 0