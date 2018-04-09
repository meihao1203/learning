#include<iostream>
using namespace std;
// #pragma vtordisp(off)  // 关闭产生vtordisp for vbase A指针
//单个虚拟继承
class A
{
public:
	A():_ia(10){}
	virtual void f(){  cout<<"A::f()"<<endl;  }
	void fa(){  cout<<"A::fa()"<<endl;  }
private:
	int _ia;
};
class B: virtual public A
{
	B():_ib(20){}
	void f(){  cout<<"B::f()"<<endl;  }
	//virtual void f2(){  cout<<"B::f2()"<<endl;  }
	void f3(){  cout<<"B::f3()"<<endl;  }
private:
	int _ib;
};
int main()
{
	return 0;
}
/*
1>  class A	size(8):
1>  	+---
1>   0	| {vfptr}
1>   4	| _ia
1>  	+---
1>  
1>  A::$vftable@:
1>  	| &A_meta
1>  	|  0
1>   0	| &A::f
*/

/*
1>  class B	size(24):
1>  	+---
1>   0	| {vfptr}
1>   4	| {vbptr}
1>   8	| _ib
1>  	+---
1>  12	| (vtordisp for vbase A)
1>  	+--- (virtual base A)
1>  16	| {vfptr}
1>  20	| _ia
1>  	+---
1>  
1>  B::$vftable@B@:
1>  	| &B_meta
1>  	|  0
1>   0	| &B::f2
1>  
1>  B::$vbtable@:
1>   0	| -4
1>   1	| 12 (Bd(B+4)A)
1>  
1>  B::$vftable@A@:
1>  	| -16
1>   0	| &(vtordisp) B::f
1>  
1>  B::f this adjustor: 16
1>  B::f2 this adjustor: 0
*/

//类B没有特有的虚函数
/*
1>  class B	size(20):
1>  	+---
1>   0	| {vbptr}
1>   4	| _ib
1>  	+---
1>  8	| (vtordisp for vbase A)
1>  	+--- (virtual base A)
1>  12	| {vfptr}
1>  16	| _ia
1>  	+---
1>  
1>  B::$vbtable@:
1>   0	| 0
1>   1	| 12 (Bd(B+0)A)
1>  
1>  B::$vftable@:
1>  	| -12
1>   0	| &(vtordisp) B::f
1>  
1>  B::f this adjustor: 12
*/
//类B一个虚函数也没有
/*
1>  class B	size(16):
1>  	+---
1>   0	| {vbptr}
1>   4	| _ib
1>  	+---
1>  	+--- (virtual base A)
1>   8	| {vfptr}
1>  12	| _ia
1>  	+---
1>  
1>  B::$vbtable@:
1>   0	| 0
1>   1	| 8 (Bd(B+0)A)
1>  
1>  B::$vftable@:
1>  	| -8
1>   0	| &A::f
*/
