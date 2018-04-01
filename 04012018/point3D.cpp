 ///
 /// @file    point3D.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-01 09:45:38
 ///
 
#include<iostream>
using namespace std;
class point
{
	public:
		point(int x=0,int y=0):_x(x),_y(y)
		{
			cout<<"point()"<<endl;
		}
		~point()
		{
			cout<<"~point()"<<endl;
		}
		int getx()const
		{
			return _x;
		}
		int gety()const
		{
			return _y;
		}
		void display()const 
		{
			cout<<"("<<_x<<","<<_y<<")"<<endl;
		}
	private:
		int _x;
		int _y;
};
class point3D:public point
{
	public:
		point3D(int x=0,int y=0,int z=0):point(x,y),_z(z)
		{
			cout<<"point3D()"<<endl;
		}
		~point3D()
		{
			cout<<"~point3D()"<<endl;
		}
		void display()const
		{
			cout<<"("<<getx()<<","<<gety()<<","<<_z<<")"<<endl;  // 不能直接访问基类私有成员
		}
	private:
		int _z;  // 增加一个_Z
};
int main()
{
	point p1(1,2);
	p1.display();
	cout<<endl;
	point3D p2(3,4,5);
	p2.display();
	return 0;
}
//point()
//(1,2)
//
//point()
//point3D()
//(3,4,5)
//~point3D()
//~point()
//~point()
