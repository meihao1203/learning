 ///
 /// @file    conversion.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-02-04 22:28:58
 ///
 
// 类类型转换
#include<iostream>
using namespace std;
class AnotherPoint
{
	public:
		AnotherPoint(double dx=0,double dy=0):_dx(dx),_dy(dy)
		{
			cout<<"AnotherPoint(double,double)"<<endl;
		}
	private:
		double _dx;
		double _dy;
	friend ostream& operator<<(ostream&,const AnotherPoint&);
};
class point
{
	public:
		point(int x=0,int y=0):_x(x),_y(y)
		{
			cout<<"point(int,int)"<<endl;
		}
		operator int()
		{
			return _x;
		}
		operator double()
		{
			return _x*_y;
		}
		operator AnotherPoint() //返回类类型
		{
			return AnotherPoint(_x,_y);   // 这里直接返回类类型对象，所以不能单单AnotherPoint类前向声明，必须给出完整定义
		}
	private:
		int _x;
		int _y;
	friend ostream& operator<<(ostream&,const point&);
};
ostream& operator<<(ostream& os,const AnotherPoint& rhs)
{
	os<<"("<<rhs._dx<<","<<rhs._dy<<")";
	return os;
}
ostream& operator<<(ostream& os,const point& rhs)
{
	os<<"("<<rhs._x<<","<<rhs._y<<")";
	return os;
}
int main()
{
	point p1(1,2);
	cout<<p1<<endl;
	int i = p1;
	cout<<i<<endl;
	double j = p1;
	cout<<j<<endl;
	AnotherPoint ap = p1;
	cout<<ap<<endl;
	return 0;
}
//point(int,int)
//(1,2)
//1
//2
//AnotherPoint(double,double)
//(1,2)
