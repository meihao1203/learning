 ///
 /// @file    newObject.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-19 14:46:21
 ///
 
#include<iostream>
using namespace std;
class point
{
	private:
		int _x;
		int _y;
	public:
		point():_x(0),_y(0)
		{
			cout<<"point()"<<endl;
		}
		point(int x,int y):_x(x),_y(y)
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
};
int main(void)
{
	point(6,7);   //匿名变量，定义完执行下一条语句就释放
	point pt1(1,1);
	pt1.print();
	point arr[3] = {point(2,3),point(4,5)};    //缺省的一个自动调用没有参数的构造函数 
	arr[0].print();
	arr[1].print();
	arr[2].print();
	return 0;
}
//point(int,int)
//~point()
//point(int,int)
//(1,1)
//point(int,int)
//point(int,int)
//point()
//(2,3)
//(4,5)
//(0,0)
//~point()
//~point()
//~point()
//~point()
