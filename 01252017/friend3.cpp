 ///
 /// @file    friend3.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-01-25 19:10:27
 ///
 
//友元类
#include<iostream>
#include<math.h>
using namespace std;
class line;
class point 
{
	friend class line;
	public:
		point(int x=0,int y=0):_x(x),_y(y)
		{
			cout<<"point(int,int)"<<endl;
		}
		~point()
		{
			cout<<"~point()"<<endl;
		}
		void display()
		{
			cout<<"("<<_x<<","<<_y<<")"<<endl;
		}
	private:
		int _x;
		int _y;
};
class line
{
	public:
		float distance(const point &p1,const point &p2)
		{
			return sqrt(
					(p2._x-p1._x)*(p2._x-p1._x) + 
					(p2._y-p1._y)*(p2._y-p1._y)
					);
		}
		void set(point &p1,int x,int y)
		{
			p1._x = x;
			p1._y = y;
		}
};
int main()
{
	point p1(1,2);
	point p2(3,4);
	line l1;
	cout<<l1.distance(p1,p2)<<endl;
	l1.set(p2,5,6);
	p2.display();
	cout<<l1.distance(p1,p2)<<endl;
	return 0;
}
//point(int,int)
//point(int,int)
//2.82843
//(5,6)
//5.65685
//~point()
//~point()
