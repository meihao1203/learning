 ///
 /// @file    virtual2.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-02 15:37:50
 ///
 
#include<iostream>
using namespace std;
class base
{
	public:
		virtual void display()
		{
			cout<<"base::display()"<<endl;
		}
};
class derived:public base
{
	public:
		virtual void display()
		{
			cout<<"derived::display()"<<endl;
		}
};
int main()
{//虚函数发生的条件：
//1、基类的指针或者引用指向派生类对象
//2、派生类覆盖了基类的虚函数
//3、通过基类的指针或引用调用虚函数，发生动态多态
	base b;
	base* pb = &b;
	pb->display();
	derived d;
	pb = &d;  // 派生类对象初始化基类指针
	pb->display();
	cout<<"sizeof(base)"<<sizeof(base)<<endl;
	cout<<"sizeof(derived)"<<sizeof(derived)<<endl;
	cout<<endl;
	d.display();   // 直接去代码区找到display(),然后去执行，没有多态机制
	cout<<endl;
	derived* pd = &d;  // 派生类对象初始化派生类指针
	pd->display();
	cout<<endl;
	return 0;
}
//base::display()
//derived::display()
//sizeof(base)8
//sizeof(derived)8
//
//derived::display()
//
//derived::display()
//
