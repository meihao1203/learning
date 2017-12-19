///
/// @file    sizeofObject.cpp
/// @author  meihao1203(meihao19931203@outlook.com)
/// @date    2017-12-19 15:00:04
///

#include <iostream>
using namespace std;
//64位操作系统默认对齐系数是8  //sizeof(cex):  56
#pragma pack(4)
class cex
{
	private:
		int a;	//int型，在一般系统上占据4个内存字节 4
		char b;	//char型，占1个内存字节	1 
		float c;	//单精度浮点型，占4个内存字节	4+1+3+4=12
		double d;	//double型，占8个内存字节	12+8=20 ;   64位操作系统默认对齐系数8   这里就是12+4+8=24
		short e[5]; //short型数组，每个元素占2个内存字节	2*5=10 ; 20+10=30;          24+10=34
		char & f;	//引用，当成指针维护,8个内存字节	30+2+8=40                       34+6+8=48
		double & g; //引用，当成指针维护,8个内存字节 40+8=48                            48+8=56
		static int h;	//static成员，公共内存，不影响单个对象的大小 0

	public:
		cex():f(b), g(d) //构造函数，引用成员必须在初始化表中初始化
	{
	}
		void print()	//成员函数的定义，普通成员函数不影响对象大小
		{
			cout << "Hello" << endl;
		}
};
//min(4,8)  按4对齐，48刚好是4的倍数
//min(8,8)  56刚好是8的倍数
int cex::h = 0;		//static成员的初始化

int main()
{
	cex c;
	cout << "sizeof(cex):  " << sizeof(cex) << endl; //输出类对象的大小sizeof(cex) = 48
	return 0;
}
//sizeof(cex):  48
