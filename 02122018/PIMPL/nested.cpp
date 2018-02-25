 ///
 /// @file    nested.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-02-25 15:19:18
 ///

// LinePimpl 实现
#include"nested.h"
#include<iostream>
using namespace std;
class Line::LinePimpl
{
	private:
		class Point  // 嵌套类
		{
				int _x;   // 最开头，默认private
				int _y;
			public:
				Point(int x=0,int y=0):_x(x),_y(y)
				{
					cout<<"Line::LinePimpl::Point::Point(int,int)"<<endl;
				}
				~Point()
				{
					cout<<"Line::LinePimpl::Point::~Point()"<<endl;
				}
				void printPoint();
		};
		Point _p1;
		Point _p2;
	public:
		LinePimpl(int ix=0,int iy=0,int jx=0,int jy=0):_p1(ix,iy),_p2(jx,jy)
		{
			cout<<"Line::LinePimpl::LinePimpl(int,int,int,int)"<<endl;
		}
		~LinePimpl()
		{
			cout<<"Line::LinePimpl::~LinePimpl()"<<endl;
		}
		void printLine();
};
void Line::LinePimpl::Point::printPoint()
{
	cout<<"Line::LinePimpl::Point::printPoint()"<<endl;
	cout<<"("<<_x<<","<<_y<<")"<<endl;
}
void Line::LinePimpl::printLine()
{
	cout<<"Line::LinePimpl::printLine()"<<endl;
	_p1.printPoint();
	cout<<"->"<<endl;
	_p2.printPoint();
}
//外围类Line实现
Line::Line(int x1=0,int y1=0,int x2=0,int y2=0):_LinePimpl(new LinePimpl(x1,y1,x2,y2))
{
	cout<<"Line::Line(int,int,int,int)"<<endl;
}
Line::~Line()
{
	cout<<"Line::~Line()"<<endl;
	delete _LinePimpl;
}
void Line::printLine()
{
	cout<<"Line::printLine()"<<endl;
	_LinePimpl->printLine();
}
