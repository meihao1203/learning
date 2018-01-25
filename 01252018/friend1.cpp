 ///
 /// @file    friend1.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-01-25 16:03:43
 ///
 
#include<iostream>
#include<math.h>
using namespace std;
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
		friend float dis(const point &,const point &); // 声明为友元函数，和共有私有没有关系，都能访问类内部所有数据
	private:
		int _x;
		int _y;

};
float dis(const point &p1,const point &p2)
{
	return sqrt((p2._x-p1._x)*(p2._x-p2._x)+(p2._y-p1._y)*(p2._y-p1._y));
}
int main()
{
	point p1(1,3);
	point p2(5,6);
	cout<<dis(p1,p2)<<endl;
	return 0;
}
//point(int,int)
//point(int,int)
//3
//~point()
//~point()
