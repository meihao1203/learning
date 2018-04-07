 ///
 /// @file    vtable.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-04 09:45:48
 ///
 
//测试虚表的存在
#include<iostream>
using namespace std;
class A
{
	int i;
	void func(){}
	virtual void run(){ cout<<"A::run()"<<endl; }
	virtual void run1(){ cout<<"A::run1()"<<endl; }
	virtual void run2(){ cout<<"A::ru2()"<<endl; }
};
class B:virtual public A
{
	virtual void run(){ cout<<"B::run()"<<endl; }
	virtual void run1(){ cout<<"B::run1()"<<endl; }
	virtual void run2(){ cout<<"B::run2()"<<endl; }
	virtual void run3(){ cout<<"B::run3()"<<endl; }
};
int main()
{
	cout<<"sizeof(A):"<<sizeof(A)<<"  sizeof(B):"<<sizeof(B)<<endl;
	B b;
	typedef void(*Function)(void);
#if 1 
	int** pVtable = (int**)&b;
	for(int idx=0;pVtable[0][idx]!=NULL;++idx)
	{
		Function f = (Function)pVtable[0][idx];
		f();
	}
	cout<<(int*)pVtable[1]<<endl;
	Function f1 = (Function)pVtable[0][0];  // 只能这样访问，其它都是段错误
	// 不懂啊
	f1();
#endif
#if 0
	int* pVtable = (int*)&b;
	Function f = (Function)pVtable;
	f();
#endif 
	return 0;
}
//sizeof(A):16  sizeof(B):24
//B::run()
//0x400e60
