 ///
 /// @file    staticPrivate.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-03 10:54:51
 ///
 
#include<iostream>
using namespace std;
class A
{
	public:
		static A* createObject(int x)
		{
			return new A(x);
		}
		~A()  // 静态对象没有this指针
		{
			cout<<"~A()"<<endl;
		}
		static void deleteObject(A* p)
		{  // 所以要这样来析构
			if(NULL!=p)
			{
				delete p;
				p = NULL;
			}
		}
		void disp()
		{
			cout<<"x = "<<_x<<endl;
		}
	private:
		int _x;
		A(int x=0):_x(x){}
};
int main()
{
	//A a;  //错误, Example的构造函数是private类型, 不能访问
	//A* a = new A(1);  //错误, Example的构造函数是private类型, 不能new
	A* a = A::createObject(1);
	a->disp();
	//A::deleteObject(a);
	delete a;
	return 0;
}
//x = 1
//~A()
