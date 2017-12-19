 ///
 /// @file    newObjectarr.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-19 17:10:23
 ///
 
#include <iostream>
#include<stdlib.h>
using namespace std;

class point
{
private:								//private数据成员列表
	int x;
	int y;

public:
	point(int xp=0,int yp=0)			//构造函数，带缺省参数值
	{
		x=xp;
		y=yp;
		cout<<"point(int,int)"<<endl;
	}
	~point()							//析构函数
	{
		cout<<"~point()"<<endl;
	}
	void print()						//成员函数，类内部实现
	{
		cout<<"x:  "<<x<<", y:  "<<y<<endl;
	}
};

int main()
{
	point* p = new point(4,5);	//动态申请一块内存，存储point类对象，并将地址赋值给point型指针p
	p->print();					//使用指针加－>调用成员函数
	delete p;					//释放动态申请的内存，防止内存泄露
	p=NULL;						//养成良好习惯，防止野指针

	point *pp = new point[3];	//此时你会发现分配了28个字节的内存空间，多出的最开始的4个字节的内存空间，存放3
	pp[0] = point(1,2);   //只能这样初始化
	pp[1] = point(3,4);
	pp[2] = point(5,6);
	delete[] pp;
	return 0;
}
//point(int,int)
//x:  4, y:  5
//~point()
//point(int,int)
//point(int,int)
//point(int,int)
//point(int,int)
//~point()
//point(int,int)
//~point()
//point(int,int)
//~point()
//~point()
//~point()
//~point()
