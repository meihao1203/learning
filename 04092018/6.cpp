#include<iostream>
using namespace std;
//多重虚继承，派生类不带特有虚函数 
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
class Derived:virtual public Base1,virtual public Base2,virtual public Base3
{
public:
	Derived():_iDerived(10000){}
	void f(){}
	/*virtual*/ void g1(){}
private:
	int _iDerived;
};
int main()
{
	cout<<sizeof(Derived)<<endl;
	system("pause");
	return 0;
}
/*
1>  class Derived	size(44):
1>  	+---
1>   0	| {vbptr}
1>   4	| _iDerived
1>  	+---
1>  8	| (vtordisp for vbase Base1)
1>  	+--- (virtual base Base1)
1>  12	| {vfptr}
1>  16	| _iBase1
1>  	+---
1>  20	| (vtordisp for vbase Base2)
1>  	+--- (virtual base Base2)
1>  24	| {vfptr}
1>  28	| _iBase2
1>  	+---
1>  32	| (vtordisp for vbase Base3)
1>  	+--- (virtual base Base3)
1>  36	| {vfptr}
1>  40	| _iBase3
1>  	+---
1>  
1>  Derived::$vbtable@:
1>   0	| 0
1>   1	| 12 (Derivedd(Derived+0)Base1)
1>   2	| 24 (Derivedd(Derived+0)Base2)
1>   3	| 36 (Derivedd(Derived+0)Base3)
1>  
1>  Derived::$vftable@Base1@:
1>  	| -12
1>   0	| &(vtordisp) Derived::f
1>   1	| &Base1::g
1>   2	| &Base1::h
1>  
1>  Derived::$vftable@Base2@:
1>  	| -24
1>   0	| &(vtordisp) thunk: this-=12; goto Derived::f
1>   1	| &Base2::g
1>   2	| &Base2::h
1>  
1>  Derived::$vftable@Base3@:
1>  	| -36
1>   0	| &(vtordisp) thunk: this-=24; goto Derived::f
1>   1	| &Base3::g
1>   2	| &Base3::h
1>  
1>  Derived::f this adjustor: 12
*/