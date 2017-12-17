///
/// @file    const.cpp
/// @author  meihao1203(meihao19931203@outlook.com)
/// @date    2017-12-17 15:52:38
///

#include<iostream>
using namespace std;
class point
{
	private:
		int _x;
		int _y;
	public:
		point(int x=0,int y=0):_x(x),_y(y)
		{
			cout<<"point(int,int)"<<endl;
		}
		point(const point &rhs)
		{
			_x = rhs._x;
			_y = rhs._y;
			cout<<"point(const point &)"<<endl;
		}
		void print()const
		{
			cout<<"print()const";
			cout<<"("<<_x<<","<<_y<<")"<<endl;
		}
		void print()
		{
			cout<<"print()";
			cout<<"("<<_x<<","<<_y<<")"<<endl;
		}
};
void func1(const point &tmp)
{
	tmp.print();
}
void func2(point &tmp1)
{
	tmp1.print();
}
//非const变量可以调用const函数，如果有适合的非const函数就去调用非const函数
//const变量只能调用const函数
int main()
{
	point pt1(1,2);
	const point pt2(3,4);
	func1(pt1);
	func1(pt2);  //奇怪，这里不发生拷贝构造函数，我把func2的tmp改成tmp1就好了，定义函数这个也有关系？
	func2(pt1);
	//func2(pt2);   //error,func2函数之能调用非const的print
	return 0;
}
//point(int,int)
//point(int,int)
//print()const(1,2)
//point(const point &)
//print()const(3,4)
//print()(1,2)
//修改tmp1之后的
//point(int,int)
//point(int,int)
//point(const point &)
//print()const(1,2)
//point(const point &)
//print()const(3,4)
//point(const point &)
//print()(1,2)
//
//函数传值改成传引用
//point(int,int)
//point(int,int)
//print()const(1,2)
//print()const(3,4)
//print()(1,2)
