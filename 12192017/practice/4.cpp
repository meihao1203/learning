///
/// @file    4.cpp
/// @author  meihao1203(meihao19931203@outlook.com)
/// @date    2017-12-19 19:19:47
///

#include<iostream>
using namespace std;
class CSomething
{
	private:
		int _i;
	public:
		//CSomething(){cout<<"CSomething()"<<endl;}
#if 1
		CSomething(int i=0):_i(i)
		{
			cout<<"CSomething(int)"<<endl;
		}
#endif
		CSomething(const CSomething &rhs):_i(rhs._i)
		{
			cout<<"CSomething(const CSomething &)"<<endl;
		}
		~CSomething()
		{
			cout<<"~CSomething()"<<endl;
		}
		void print()
		{
			cout<<"print()"<<endl;
		}
};
int main()
{
	CSomething a();    //不会；CSomething a;  会调用构造函数; 
//我猜测啊，编译器把这个定义误解为一个函数声明
	CSomething b(2);   //会
	CSomething c[3];   //会
	CSomething &ra = b;//不会调用构造函数
	CSomething d = b;  //会,不过是拷贝构造函数
	CSomething *pA = c;//不会,定义了指针指向，并没有创造对象
	CSomething *p = new CSomething(4);   //会
	delete p;
	p = NULL;
	return 0;
}
//CSomething(int)
//CSomething(int)
//CSomething(int)
//CSomething(int)
//CSomething(const CSomething &)
//CSomething(int)
//~CSomething()
//~CSomething()
//~CSomething()
//~CSomething()
//~CSomething()
//~CSomething()
