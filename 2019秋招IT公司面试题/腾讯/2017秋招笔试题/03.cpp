//给定一个正整数，编写程序计算有多少对质数的和等于输入的这个正整数，并输出结果。输入值小于1000。
//如，输入为10, 程序应该输出结果为2。（共有两对质数的和为10,分别为(5,5),(3,7)）
//输入描述:
//
//输入包括一个整数n,(3 ≤ n < 1000)
//
//
//
//输出描述:
//
//输出对数
//
//
//输入例子1:
//
//10
//
//
//输出例子1:
//
//2
#if 0
#include<iostream>
using namespace std;
int cntPair(int num);
bool isPrim(int num);
int main()
{
	int num;
	cin>>num;
	cout<<cntPair(num);
	//system("pause");
}
int cntPair(int num)
{
	if(num<3||num>=1000)
		return 0;
	int cnt = 0;
	for(int idx=0;idx!=num;++idx)
	{
		if(isPrim(idx))
		{
			for(int iidx=idx;iidx!=num;++iidx)
			{
				if(isPrim(iidx))
				{
					if(num==idx+iidx)
						++cnt;
				}
			}
		}
	}
	return cnt;
}
bool isPrim(int num)
{
	if(num<=1||num>=1000)
		return false;
	for(int idx=2;idx!=num;++idx)
	{
		if(0==num%idx)
			return false;
	}
	return true;
}
#endif