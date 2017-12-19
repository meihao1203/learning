 ///
 /// @file    this.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-19 08:51:04
 ///
//此类的所有对象共用这个成员函数体。 
//编译之后，此成员函数地址即已确定。
//而成员函数之所以能把属于此类的各个对象的数据区别开, 就是靠这个this指针。
//函数体内所有对类数据成员的访问， 都会被转化为this->数据成员的方式
#include<iostream>
using namespace std;
class nullPoint
{
	private:
		int _i;
		static int _si;
	public:
		static void test1()
		{
			cout<<"static void test1()"<<_si<<endl;
		}
		void test2()
		{
			cout<<"void test2()"<<endl;
		}
		void test3(int i)
		{
			cout<<"void test3(int)"<<i<<endl;
		}
		void test4()
		{
			cout<<"void test4()"<<_i<<endl;
		}
};
int nullPoint::_si = 6;
int main(void)
{
	nullPoint *point = NULL;
	point->test1();   //静态成员，类所有对象共有，不必知道具体调用的对象，所以不需要this指针
	point->test2();   //被调用函数没有涉及到要使用对象特有的数据成员
	point->test3(2);  //同上
	//point->test4(); //段错误，涉及到要访问对象的数据成员，
	//但是point指针是null,
	//多以传递的this指针也是null
	return 0;
}
//static void test1()6
//void test2()
//void test3(int)2
//Segmentation fault (core dumped)
