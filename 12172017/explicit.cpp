///
/// @file    explicit.cpp
/// @author  meihao1203(meihao19931203@outlook.com)
/// @date    2017-12-17 15:00:14
///

#include<iostream>
using namespace std;
class point
{
	private:
		int _x;
		int _y;
	public:
#if 0
		point(int x=0,int y=0)
			:_x(x)
			 ,_y(y)
	{
		cout<<"point(int,int)"<<endl;
	}
#endif
		explicit point(int x,int y)
			:_x(x)
			 ,_y(y)
	{
		cout<<"point(int,int)"<<endl;
	}
		explicit point()
		{
			cout<<"point()"<<endl;
		}
		point(point &rhs)
			:_x(rhs._x)
			 ,_y(rhs._y)
	{
		cout<<"point(point &)"<<endl;
	}
		point & operator = (const point &rhs)
		{
			this->_x = rhs._x;
			this->_y = rhs._y;
			cout<<"operator=(const point&)"<<endl;
		}
		void print()
		{
			cout<<"("<<_x<<","<<_y<<")"<<endl;
		}
};
int main()
{
	point pt1(3,4);
	point pt2 = pt1;   //调用拷贝构造函数
	pt2.print();
	//point pt3 = 1;   //加了关键字explicit，禁止这种转换
	//pt3.print();
	point pt4(pt1);
	pt4.print();
	return 0;
}
//point(int,int)
//point(point &)
//(3,4)
//point(point &)
//(3,4)
