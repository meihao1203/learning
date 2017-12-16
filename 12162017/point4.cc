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
//初始化顺序只跟数据成员声明时的顺序有关，
//与其在初始化列表中的顺序无关
	point(int iy)   //构造函数初始化列表
		//:_ix(iy) 
		:_iy(iy)
		,_ix(iy)
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
	point p(3);
	p.print();
	return 0;
}
//point(int,int)
//_ix=3
//_iy=3
