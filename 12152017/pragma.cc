 ///
 /// @file    pragma.cc
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-15 11:04:31
 ///
 
#pragma pack(2)   //内存对齐系数2 
//结构中的各个成员min(#pragma pack()指定的数，这个数据成员的自身长度) 的倍数
//结构中的各个成员完成对齐后，结构(或联合)本身也要进行对齐
//对齐将按照min(#pragma pack指定的数值,结构(或联合)中最大数据成员长度)
#include<iostream>
using namespace std;
class BU
{
	int num;  //4
	union BUffer  //13 min(2,4)  13+4
	{
		char buffer[13];
		int number;
	}ubuf;
	void fool(){};
	typedef char *(*f)(void*);   //0,这里只是定义了一个函数指针类型，并没有定义变量
	//char *(*f)(void*);    //8,定义一个函数指针，64位系统，8个字节
	enum{hdd,ssd,blueray}disk;  //4,17 min(2,4) 18+4=44
}bu;
//4 + 13 + 1 + 4 =22;
//min(2,13)  按照2对齐，刚好22是2的倍数
int main(void)
{
	cout<<sizeof(bu)<<endl;  //22
	return 0;
}
