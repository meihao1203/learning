 ///
 /// @file    block.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-01-25 09:44:10
 ///
 
#include<iostream>
using namespace std;
void Work(int a,int b)
{
	class point
	{
		public:
			point(int x=0,int y=0)
			{
				_x = x;
				_y = y;
			}
			void print()
			{
				cout<<"("<<_x<<","<<_y<<")"<<endl;
			}
		private:
			int _x,_y;
	};
	point p(a,b);   //函数内创建point类对象p; 块作用域
	p.print();
}
int main()
{
	Work(5,6);
	//point(2,3);  //可见域不在文件范围
	return 0;
}
//(5,6)
