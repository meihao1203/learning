 ///
 /// @file    static_cast.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-07 08:59:17
 ///
 
#include<iostream>
using namespace std;
class point
{
	public:
		point(int x=0,int y=0):_x(x),_y(y){}
		virtual void show()
		{
			cout<<"("<<_x<<","<<_y;
		}
	private:
		int _x;
		int _y;
};
class point3D:public point
{
	public:
		point3D(int _x=0,int _y=0,int z=0):point(_x,_y),_z(z){}
		virtual void show()
		{
			point::show();
			cout<<","<<_z<<")"<<endl;
		}
	private:
		int _z;
};
class String
{
	public:
		String():_mchar(new char[1]){}
		void show()
		{
			cout<<_mchar<<endl;
		}
	private:
		char* _mchar;
};
int main()
{
	//下面的转换本来是无意义和非法的，以后使用ps->Show()
	//成员函数时可能会引起内存错误或得到错误的值, 但编译却不出错. 留下隐患
	point3D p1(1,2,3);
	String* sp = (String*)&p1;
	sp->show();  // 编译通过，调用直接段错误  // 派生类里面加了point::限定就不会段错误了

	//但改成下面使用static_cast形式进行转换, 在编译时就报错, 能及时发现错误
	//sp = static_cast<String*> (&p1);  // 编译报错
	cout<<"----------------------------------------------------------------"<<endl;
	//而下面这种转换之所以能编译通过，是因为CPoint和CPoint3D的指针本来就可以相互转换
	point* pBase = static_cast<point*> (&p1);
	pBase->show();
	cout<<endl;
	return 0;
}
// 
//@
//----------------------------------------------------------------
//(1,2,3)
//
