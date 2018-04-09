#include<iostream>
using namespace std;
//多重虚继承，带虚函数
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
	virtual void g1(){}
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
1>  class Derived	size(48):
1>  	+---
1>   0	| {vfptr}
1>   4	| {vbptr}
1>   8	| _iDerived
1>  	+---
1>  12	| (vtordisp for vbase Base1)
1>  	+--- (virtual base Base1)
1>  16	| {vfptr}
1>  20	| _iBase1
1>  	+---
1>  24	| (vtordisp for vbase Base2)
1>  	+--- (virtual base Base2)
1>  28	| {vfptr}
1>  32	| _iBase2
1>  	+---
1>  36	| (vtordisp for vbase Base3)
1>  	+--- (virtual base Base3)
1>  40	| {vfptr}
1>  44	| _iBase3
1>  	+---
1>  
1>  Derived::$vftable@Derived@:
1>  	| &Derived_meta
1>  	|  0
1>   0	| &Derived::g1
1>  
1>  Derived::$vbtable@:
1>   0	| -4
1>   1	| 12 (Derivedd(Derived+4)Base1)
1>   2	| 24 (Derivedd(Derived+4)Base2)
1>   3	| 36 (Derivedd(Derived+4)Base3)
1>  
1>  Derived::$vftable@Base1@:
1>  	| -16
1>   0	| &(vtordisp) Derived::f
1>   1	| &Base1::g
1>   2	| &Base1::h
1>  
1>  Derived::$vftable@Base2@:
1>  	| -28
1>   0	| &(vtordisp) thunk: this-=12; goto Derived::f
1>   1	| &Base2::g
1>   2	| &Base2::h
1>  
1>  Derived::$vftable@Base3@:
1>  	| -40
1>   0	| &(vtordisp) thunk: this-=24; goto Derived::f
1>   1	| &Base3::g
1>   2	| &Base3::h
1>  
1>  Derived::f this adjustor: 16
1>  Derived::g1 this adjustor: 0
1>  
1>  vbi:	   class  offset o.vbptr  o.vbte fVtorDisp
1>             Base1      16       4       4 1
1>             Base2      28       4       8 1
1>             Base3      40       4      12 1
*/