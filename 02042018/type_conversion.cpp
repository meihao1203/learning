 ///
 /// @file    type_conversion.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-02-04 16:48:00
 ///
 
#include<iostream>
using namespace std;
class anotherPoint;
class point
{
	public:
		// explicit 禁止这种隐士转
		point(int x=0,int y=0):_x(x),_y(y)
		{
			cout<<"point(int,int)"<<endl;
		}
		point(const anotherPoint& rhs);
		//point& operator=(const anotherPoint& rhs);  // 赋值运算符只能两个相同类型的类对象之间 
		friend ostream& operator<<(ostream& os,const point&);
	private:
		int _x;
		int _y;
};
class anotherPoint
{
	friend class point;
	public:
		anotherPoint(double dx=0.0,double dy=0.0):_dx(dx),_dy(dy)
		{
			cout<<"anotherPoint(double,double)"<<endl;
		}
		friend ostream& operator<<(ostream& os,const anotherPoint&);
	private:
		double _dx;
		double _dy;
};
point::point(const anotherPoint& rhs)
{
	cout<<"point(const anotherPoint&)"<<endl;
	_x = rhs._dx;
	_y = rhs._dy;
}
ostream& operator<<(ostream& os,const point& rhs)
{
	cout<<"("<<rhs._x<<","<<rhs._y<<")";
	return os;
}
ostream& operator<<(ostream& os,const anotherPoint& rhs)
{
	cout<<"("<<rhs._dx<<","<<rhs._dy<<")";
	return os;
}
int main()
{
	point p1;
	p1 = 2;  // 重载了赋值运算符，这里就出错了;没有赋值运算符这里调用的是构造函数.
	cout<<p1<<endl;
	anotherPoint p2(1.5,0);
	p2 = 1.5;  // 其他类型向自定义类的转换
	cout<<p2<<endl;
	p1 = p2;   // 两个都是类类型，调用拷贝构造函数
	cout<<p1<<endl;
}
//point(int,int)
//point(int,int)
//(2,0)
//anotherPoint(double,double)
//anotherPoint(double,double)
//(1.5,0)
//point(const anotherPoint&)
//(1,0)
