 ///
 /// @file    abstract.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-03 10:27:06
 ///
 
#include<iostream>
using namespace std;
class A
{
	public:
		void disp()
		{
			cout<<"x="<<_x<<endl;
		}
	protected:  // 构造函数为保护成员，也是抽象类
		A(int x=0):_x(x){}
	private:
		int _x;
};
class B:public A
{
	public:
		//A a;  // error,在派生类不能创建A类对象,和在main函数建立对象一样
		B(int x):A(x){};  // 派生类中可调用protected构造函数
};
int main()
{
	//A a;
	B b(6);
	b.disp();
	return 0;
}
// x=6
