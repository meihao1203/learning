 ///
 /// @file    nested.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-02-25 15:07:48
 ///
 
#ifndef __NESTED_H__
#define __NESTED_H__
#include<iostream>
using namespace std;
class Line
{
	private:
		class LinePimpl;  // 前向声明
		LinePimpl* _LinePimpl;
	public:
		Line(int,int,int,int);
		~Line();
		void printLine();
};
#endif
