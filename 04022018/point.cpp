 ///
 /// @file    point.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-02 09:45:06
 ///
 
#include<iostream>
using namespace std;
class point
{
	public:
		point(int x=0,int y=0):_x(x),_y(y) {}
		void display()
		{
			cout<<"("<<_x<<","<<_y<<")"<<endl;
		}
	protected:
		int _x;
		int _y;
};
class point3D:public point
{
	public:
		point3D(int x=0,int y=0,int z=0):point(x,y),_z(z) {}
		void display()
		{
			cout<<"("<<_x<<","<<_y<<","<<_z<<")"<<endl;
		}
	private:
		int _z;
};
int main()
{
	point p1(1,2);
	point3D p2(3,4,5);
	p1.display();
	p2.display();
	cout<<endl;
	p1 = p2;  // 基类和派生类对象之间转换
	p1.display();
	point& ref = p2;
	ref.display();
	point* p3 = &p2;
	p3->display();
	return 0;
}
//(1,2)
//(3,4,5)
//
//(3,4)
//(3,4)
//(3,4)
