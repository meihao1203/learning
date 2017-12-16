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
#if 0
	point()
	{
		cout<<"point()"<<endl;
	}
#endif
#if 0
	point(int ix=0,int iy=0)   //构造函数重载，带缺省值的构造函数
	{
		cout<<"point(int,int)"<<endl;
		_ix = ix;
		_iy = ix;
	}
#endif
	point(int ix,int iy)   //构造函数初始化列表
		:_ix(ix)
		 ,_iy(iy)
	{
		cout<<"point(int,int)"<<endl;
	}
	void print()
	{
		cout<<"_ix="<<_ix<<endl;
		cout<<"_iy="<<_iy<<endl;
	}
};
int main(void)
{
	//point p1;   //出错，没有合适的构造函数
	point p1(0,0);
	p1.print();
	point p2(3,5);
	p2.print();
	return 0;
}
//point(int,int)
//_ix=0
//_iy=0
//point(int,int)
//_ix=3
//_iy=5
