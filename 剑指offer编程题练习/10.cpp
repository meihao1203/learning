//计算一个数的二进制表示中有多少个1
// 扩展：输入两个整数m和n，判断m经过多少位变换可以变成n
// 思路，先异或，再求1的个数
#include<iostream>
using namespace std;
int num1Cnt(int n);
void test(int n,int expected);
#if 0
int main()
{
	test(13,3);  //1101 - 1 = 1100 & 1101 = 1100 - 1 = 1011 & 1100 = 1000
	test(0x7fffffff,31);
	test(0xffffffff,32);
	system("pause");
}
#endif
int num1Cnt(int n)
{
	int count = 0;
	while(n)
	{
		++count;
		n = (n - 1) & n;  //
	}
	return count;
}
void test(int n,int expected)
{
	if(num1Cnt(n)!=expected)
		cout<<"fail"<<endl;
}