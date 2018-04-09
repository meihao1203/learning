#include<iostream>
using namespace std;
//多继承，有共同基类
class B
{
public:
	B():_ib(10),_cb('B'){}
	virtual void f(){}
	virtual void Bf(){}
private:
	int _ib;
	char _cb;
};
class B1:public B
{
public:
	B1():_ib1(100),_cb1('B1'){}
	virtual void f(){}
	virtual void f1(){}
	virtual void Bf1(){}
private:
	int _ib1;
	char _cb1;
};
class B2:public B
{
public:
	B2():_ib2(1000),_cb2('2'){}
	virtual void f(){}
	virtual void f2(){}
	virtual void Bf2(){}
private:
	int _ib2;
	char _cb2;
};
class D:public B1,public B2
{
public:
	D():_id(10000),_cd('3'){}
	virtual void f(){}
	virtual void f1(){}
	virtual void f2(){}
	virtual void Df(){}
private:
	int _id;
	char _cd;
};
int main()
{
	return 0;
}
/*
1>  class B	size(12):
1>  	+---
1>   0	| {vfptr}
1>   4	| _ib
1>   8	| _cb
1>    	| <alignment member> (size=3)
1>  	+---
1>  
1>  B::$vftable@:
1>  	| &B_meta
1>  	|  0
1>   0	| &B::f
1>   1	| &B::Bf
1>  
1>  B::f this adjustor: 0
1>  B::Bf this adjustor: 0
*/

/*
1>  class B1	size(20):
1>  	+---
1>  	| +--- (base class B)
1>   0	| | {vfptr}
1>   4	| | _ib
1>   8	| | _cb
1>    	| | <alignment member> (size=3)
1>  	| +---
1>  12	| _ib1
1>  16	| _cb1
1>    	| <alignment member> (size=3)
1>  	+---
1>  
1>  B1::$vftable@:
1>  	| &B1_meta
1>  	|  0
1>   0	| &B1::f
1>   1	| &B::Bf
1>   2	| &B1::f1
1>   3	| &B1::Bf1
1>  
1>  B1::f this adjustor: 0
1>  B1::f1 this adjustor: 0
1>  B1::Bf1 this adjustor: 0
*/

/*
1>  class B2	size(20):
1>  	+---
1>  	| +--- (base class B)
1>   0	| | {vfptr}
1>   4	| | _ib
1>   8	| | _cb
1>    	| | <alignment member> (size=3)
1>  	| +---
1>  12	| _ib2
1>  16	| _cb2
1>    	| <alignment member> (size=3)
1>  	+---
1>  
1>  B2::$vftable@:
1>  	| &B2_meta
1>  	|  0
1>   0	| &B2::f
1>   1	| &B::Bf
1>   2	| &B2::f2
1>   3	| &B2::Bf2
*/

/*
1>  class D	size(48):
1>  	+---
1>  	| +--- (base class B1)
1>  	| | +--- (base class B)
1>   0	| | | {vfptr}
1>   4	| | | _ib
1>   8	| | | _cb
1>    	| | | <alignment member> (size=3)
1>  	| | +---
1>  12	| | _ib1
1>  16	| | _cb1
1>    	| | <alignment member> (size=3)
1>  	| +---
1>  	| +--- (base class B2)
1>  	| | +--- (base class B)
1>  20	| | | {vfptr}
1>  24	| | | _ib
1>  28	| | | _cb
1>    	| | | <alignment member> (size=3)
1>  	| | +---
1>  32	| | _ib2
1>  36	| | _cb2
1>    	| | <alignment member> (size=3)
1>  	| +---
1>  40	| _id
1>  44	| _cd
1>    	| <alignment member> (size=3)
1>  	+---
1>  
1>  D::$vftable@B1@:
1>  	| &D_meta
1>  	|  0
1>   0	| &D::f
1>   1	| &B::Bf
1>   2	| &D::f1
1>   3	| &B1::Bf1
1>   4	| &D::Df
1>  
1>  D::$vftable@B2@:
1>  	| -20
1>   0	| &thunk: this-=20; goto D::f
1>   1	| &B::Bf
1>   2	| &D::f2
1>   3	| &B2::Bf2
1>  
1>  D::f this adjustor: 0
1>  D::f1 this adjustor: 0
1>  D::f2 this adjustor: 20
1>  D::Df this adjustor: 0
*/