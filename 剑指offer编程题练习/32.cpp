//题目32：输入一个整数n，求从1到n这n个整数的十进制表示中1出现的次数。
//例如输入12，从1到12这些整数中包含1的数字有1,10,11,12；1一共出现了5次。
//思路：假设n是21345，分两段，1~1345和1346~21345
//1346~21345中1出现的次数，首先1出现在最高位，10000~19999这10000个数字中一共出现10000个
//不是所有5位数在万位出现的次数都是10000个，12345中1出现的次数就是2346
//计算1出现在除最高位之外的其他四位数中的情况。1346~21345这20000个数字中后4位中1出现的次数是2000次。
//由于最高位为2，又可以分成1346~11345和11346~21345。每一段数字中，选择其中一位是1，其余三位可以在0~9这10个数字
//中任意选择，最终2*4*10^3=2000次。
//最后1~1345中可以递归求得，这就是最开始为什么要把21345分成1~1345和1346~21345
//时间复杂度O(logn)
#include<iostream>
#include<string.h>
using namespace std;
int NumberOf1Between1AndN(int n);
int NumberOf1(const char* strN);
int PowerBase10(unsigned int n);
int main()
{
	int ret = NumberOf1Between1AndN(21345); //21345->18821   //1345->821
	cout<<ret<<endl;

	ret = NumberOf1Between1AndN(1345); 
	cout<<ret<<endl;

	ret = NumberOf1Between1AndN(9); 
	cout<<ret<<endl;

	ret = NumberOf1Between1AndN(19); 
	cout<<ret<<endl;
}
int NumberOf1Between1AndN(int n)
{
	if(n<=0)
		return 0;
	char strN[50];
	sprintf(strN,"%d",n);
	return NumberOf1(strN);
}
int NumberOf1(const char* strN)
{
	if(!strN||*strN<'0'||*strN>'9'||*strN=='\0')
		return 0;
	int first = *strN - '0';  //获取整数的最高位
	unsigned int length = static_cast<unsigned int>(strlen(strN));
	if(length==1&&first==0)
		return 0;
	if(length==1&&first>0)
		return 1;  //0~9只有一个1
	//假设strN是21345
	int numFirstDigit = 0;
	//numFirstDigit是数字10000~19999中1出现的次数（最高位为1,10^4）
	if(first>1)
		numFirstDigit = PowerBase10(length-1); //10^4
	else if(first==1)
		numFirstDigit = atoi(strN+1) + 1;  //eg：数字为12345，那么1的个数就是2346

	int numOtherDigits = first*(length-1)*PowerBase10(length-2);
	//numOtherDigits是1346~21345除了第一位之外的数位中的数目
	//2*4*10^3 = 8000
	//first表示可以分几段，length-1表示剩下的位数，剩下的位数中随机选一位为1，其他的位数可以选0~9，全排列就是2*4*10^3
	//1346~11345  11346~21345
	int numRecursive = NumberOf1(strN+1);
	//numRecursive是1-1345中的数目

	return numFirstDigit + numOtherDigits + numRecursive;
}
int PowerBase10(unsigned int n)
{
	int result = 1;
	for(unsigned int i=0;i<n;++i)
	{
		result *= 10;
	}
	return result;
}
//18821
//821
//1
//12
