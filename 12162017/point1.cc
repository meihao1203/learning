 ///
 /// @file    point1.cc
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-16 09:29:25
 ///
 
#include<iostream>
using namespace std;
class point
{
	int _ix;
	int _iy;
	public:
	point()
	{
		cout<<"point()"<<endl;
	}
	point(int ix,int iy)
	{
		cout<<"point(int,int)"<<endl;
		_ix = ix;
		_iy = ix;
	}
};
int main(void)
{
	point p1;
	point p2(3,5);
	return 0;
}
//point()
//point(int,int)
