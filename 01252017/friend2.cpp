///
/// @file    friend2.cpp
/// @author  meihao1203(meihao19931203@outlook.com)
/// @date    2018-01-25 16:48:09
///

#include<iostream>
#include<math.h>
using namespace std;
class point; //前向声明
class line 
{
	public:
		float distance(const point &,const point &); //类line的成员作为point类的友元函数
		//必须先定义line类，而不仅仅是声明；
#if 0
		{
			return sqrt(
					(p2._x-p1._x)*(p2._x-p1._x) +
					(p2._y-p1._y)*(p2._y-p1._y)
					);   //_x和_y在这里未知
		}
#endif
};
class point
{
	public:
		point(int x=0,int y=0):_x(x),_y(y)
		{
			cout<<"point(int,int)"<<endl;
		}
		~point()
		{
			cout<<"~point()"<<endl;
		}
		void print()
		{
			cout<<"("<<_x<<","<<_y<<")"<<endl;
		}
		friend float line::distance(const point &,const point &);  //实现必须要放到point类外面，因为里面用到了point
#if 0
		{//类point还没有定义完，这里point未知
			return sqrt(
					(p2._x-p1._x)*(p2._x-p1._x) +
					(p2._y-p1._y)*(p2._y-p1._y)
					);   //_x和_y在这里未知
		}
#endif
	private:
		int _x;
		int _y;
};
#if 1
float line::distance(const point &p1,const point &p2)
{
	return sqrt(
			(p2._x-p1._x)*(p2._x-p1._x) +
			(p2._y-p1._y)*(p2._y-p1._y)
			);
}
#endif
int main()
{
	point p1(1,2);
	point p2(3,4);
	line tmp;
	cout<<tmp.distance(p2,p1)<<endl;
	return 0;
}
//point(int,int)
//point(int,int)
//2.82843
//~point()
//~point()
