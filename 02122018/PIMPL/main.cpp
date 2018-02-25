 ///
 /// @file    main.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-02-25 15:43:29
 ///
 
#include"nested.h"
#include<iostream>
using namespace std;
int main()
{
	Line l1(1,2,3,4);
	l1.printLine();
	return 0;
}
//Line::LinePimpl::Point::Point(int,int)
//Line::LinePimpl::Point::Point(int,int)
//Line::LinePimpl::LinePimpl(int,int,int,int)
//Line::Line(int,int,int,int)
//Line::printLine()
//Line::LinePimpl::printLine()
//Line::LinePimpl::Point::printPoint()
//(1,2)
//->
//Line::LinePimpl::Point::printPoint()
//(3,4)
//Line::~Line()
//Line::LinePimpl::~LinePimpl()
//Line::LinePimpl::Point::~Point()
//Line::LinePimpl::Point::~Point()
