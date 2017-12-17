///
/// @file    object.cpp
/// @author  meihao1203(meihao19931203@outlook.com)
/// @date    2017-12-17 18:39:40
///

//类的成员是其他类的对象
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
		point(const point &rhs):_x(rhs._x),_y(rhs._y)
		{
			cout<<"point(const point &)"<<endl;
		}
		void print()
		{
			cout<<"("<<_x<<","<<_y<<")";
		}
};
class line
{
	private:
		point _pt1;
		point _pt2;
	public:
		//line(const point pt1,const point pt2):_pt1(pt1),_pt2(pt2)
		line(const point &pt1,const point &pt2):_pt1(pt1),_pt2(pt2)
		{
			cout<<"line(point,point)"<<endl;
		}
		void draw()
		{
			_pt1.print();
			cout<<"->";
			_pt2.print();
			cout<<endl;
		}
};
int main(void)
{
	point p1(1,2);
	point p2(8,9);
	line l1(p1,p2);
	l1.draw();
	return 0;
}
//line没有采用引用的方式
//point(int,int)
//point(int,int)
//point(const point &)
//point(const point &)
//point(const point &)
//point(const point &)
//line(point,point)
//(1,2)->(8,9)

//line采用引用的方式，就只有初始化的时候调用拷贝构造函数
//point(int,int)
//point(int,int)
//point(const point &)
//point(const point &)
//line(point,point)
//(1,2)->(8,9)
