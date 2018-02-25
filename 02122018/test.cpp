 ///
 /// @file    test.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-02-13 15:04:39
 ///
 
#include<iostream>
using namespace std;
int x = 100;  //全局变量
int y = 200;
class test
{
	int x;
	int y;
	public:
	test(int x1=0,int y1=0):x(x1),y(y1){}
	void print(int x)
	{
		cout<<"传递来的x:"<<x<<endl;
		cout<<"成员x:"<<(this->x)<<"成员y:"<<y<<endl;
		cout<<"成员x:"<<test::x<<endl;
		cout<<"全局x:"<<::x<<"全局y:"<<::y<<endl;
	}
};
int main()
{
	test t1(2,3);
	t1.test::print(4);
	cout<<"--------------------------"<<endl;
	t1.print(5);
	return 0;
}
//传递来的x:4
//成员x:2成员y:3
//成员x:2
//全局x:100全局y:200
//--------------------------
//传递来的x:5
//成员x:2成员y:3
//成员x:2
//全局x:100全局y:200
