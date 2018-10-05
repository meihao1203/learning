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
