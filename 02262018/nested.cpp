 ///
 /// @file    nested.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-02-26 16:07:50
 ///
 
#include<iostream>
using namespace std;
class first
{
	public:
		class second;
		//first(int a=0):_a(a){  cout<<"first(int)"<<endl; n2 = second(2); }
		first(int a=0):_a(a){  cout<<"first(int)"<<endl; }
		~first(){  cout<<"~first()"<<endl;  }
		class second
		{
			public:
				second(int b=0):_b(b){  cout<<"second(int)"<<endl;  }
				~second(){  cout<<"~second()"<<endl;  }
			private:
				int _b;
		};
	private:
		int _a;
		//2、
		second n2;
};
int main()
{
	first n1;
	return 0;
}
//1、
//first(int)
//~first()
//
//2、
//second(int)
//first(int)
//second(int)
//~second()
//~first()
//~second()

//构造函数没有初始化n2对象
//second(int)
//first(int)
//~first()
//~second()
