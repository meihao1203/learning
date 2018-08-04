//输入数字n,按顺序打印出从1到最大的n位十进制数。
//比如输入3，打印1、2、3^999
//陷阱:这个数很大，大到long int都无法保存
// 第二种解法，递归
#include<iostream>
#include<string.h>
using namespace std;
int printMaxNum(int n);
int printMaxNumRecursion(char* num,int len,int idx);  //len是结束条件，从0(第一位开始打印)，idx是索引
//原理：len = 1，循环10次， 1~9
//len = 2; 先num[0] = 0;开始，递归，idx=0，num[idx+1]=0,1,2,~9,结束条件是idx = len-1,最后待打印的就是00,01,02~09,打印的时候去掉开头的0
void print(char* num);  //打印数字
void test(int n);
#if 1
int main()
{
	test(1);
	cout<<endl;
	test(0);
	cout<<endl;
	test(3);
	cout<<endl;
	system("pause");
}
#endif
int printMaxNum(int n)
{
	if(n<=0)
		return -1;
	char* num = new char[n+1];
	memset(num,'0',n);
	num[n] = '\0';
	for(int idx = 0;idx<10;++idx)
	{
		num[0] = idx + '0';  //最先从第一个字符串表示的数字为0开始打印
		printMaxNumRecursion(num,n,0);  //第一个数字为0，递归全排列打印所有情况
	}
	delete num;
	return 0;
}
int printMaxNumRecursion(char* num,int len,int idx)
{
	if(idx==len-1)//递归出口
	{//字符串表示的数组已经遍历到最后一个
		print(num);
		return 0;
	}
	for(int iidx=0;iidx<10;++iidx)
	{
		num[idx+1] = iidx + '0';  //idx后面一个可以出现的情况，0~9; 从0开始，再递归查看后一个可以出现的情况
		printMaxNumRecursion(num,len,idx+1);
		//eg: n = 3->000,001,002~009,010,011,……
	}
}
void print(char* num)
{
	if(NULL==num)
		return ;
	int i=0;
	while(num[i]=='0')
		++i;
	if(num[i]=='\0')
		return ;  //最开始第一个0不打印
	printf("%s\t",num+i);
}
void test(int n)
{
	printMaxNum(n);
}