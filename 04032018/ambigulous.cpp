 ///
 /// @file    ambigulous.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-03 15:35:30
 ///
 
#include<iostream>
using namespace std;
class A
{
	public:
		virtual void a()
		{
			cout<<"a() in A"<<endl;
		}
		virtual void b()
		{
			cout<<"b() in A"<<endl;
		}
		virtual void c()
		{
			cout<<"c() in A"<<endl;
		}
};
class B
{
	public:
		virtual void a()
		{
			cout<<"a() in B"<<endl;
		}
		virtual void b()
		{
			cout<<"b() in B"<<endl;
		}
		void c()
		{
			cout<<"c() in B"<<endl;
		}
		void d()
		{
			cout<<"d() in B"<<endl;
		}
};
class C:public A,public B
{
	public:
		virtual void a()
		{
			cout<<"a() in C"<<endl;
		}
		void c()
		{
			cout<<"c() in C"<<endl;
		}
		void d()
		{
			cout<<"d() in C"<<endl;
		}
};
int main()
{
	C c;
	//c.b();  //b()在A, B类中都定义为虚函数, C中没有无法确定使用哪个版本
	c.B::b();  // 解决办法
	cout<<endl;

	A* pA = &c;
	pA->a();
	pA->b();  //b()在A, B类中都是虚函数, C类中没有定义, 编译器无法确定使用
		//哪个版本, 只能采用静态联编. 由于pA的类型是A *，所以输出: b() in A
	pA->c();  //c()在A中为虚函数, B中为普通函数, C中进行了重定义. 此时输出
	   //取决于指针pA的类型A, 由于c()在A中为虚函数, 故按照虚函数的规则处理,输出c() in C
	//pA->d();  //d只在B和C中有，静态联编
	cout<<endl;

	B* pB = &c;
	pB->a();  //a()在A, B , C三个类中都是虚函数, 调用C类的c(), 输出: a() in C
	pB->b();  //b()在A, B类中都是虚函数, C类中没有定义, 编译器无法确定使用
	    //哪个版本, 只能采用静态联编. 由于pB的类型是B *，所以输出: b() in B
	pB->c();  //c()在A中为虚函数, B中为普通函数, C中进行了重定义. 此时输出
		//取决于指针pB的类型B, 由于c()在B中为普通函数, 故按照普通函数的规则处理,输出c() in B
	pB->d();  //d()在B, C类中都定义为普通函数, C中的d()会隐藏基类B中的d(), 
		//但pB类型为B *, 故输出d() in B
	cout<<endl;
	
	C* pC = &c;
	pC->a();  //a()在A, B , C三个类中都是虚函数, 调用C类的c(), 输出: a() in C
	//pC->b();  //b()在A, B类中都定义为虚函数, C中无法确定使用哪个版本, 
		//引起二义性错误. 解决: pC->B::b();
	pC->c();  //c()在A中为虚函数, B中为普通函数, C中进行了重定义(?). 此时输//出取决于指针pC的类型C, c()在C中无论是虚函数还是普通函数, 都输出c() in C
	pC->d();  //d()在B, C类中都定义为普通函数, C中的d()会隐藏基类B中的d(), 
		//但pC类型为C *, 故输出d() in C
	return 0;
}
//b() in B
//
//a() in C
//b() in A
//c() in C
//
//a() in C
//b() in B
//c() in B
//d() in B
//
//a() in C
//c() in C
//d() in C
