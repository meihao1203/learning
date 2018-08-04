//输入数字n,按顺序打印出从1到最大的n位十进制数。
//比如输入3，打印1、2、3^999
//陷阱:这个数很大，大到long int都无法保存
#if 0
#include<iostream>
#include<string.h>
using namespace std;
int printMaxNum(int n);
bool increaseCarry(char* num);  //字符串表示的数加1是否进位，O(1)时间复杂度内得到是否打印到最大数了
void print(char* num);  //打印数字
void test(int n);
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
int printMaxNum(int n)
{
	if(n<=0)
		return -1;
	char* num = new char[n+1];
	memset(num,'0',n+1);   //这里注意啊 ，动态数组 ，不能sizeof啊
	num[n] = '\0';  //***字符串结尾符
	while(!increaseCarry(num))  //如果数从末尾开始+1没有进位，打印，否则表示打印到最大数了，结束循环
	{
		print(num);
	}
	delete num;
	return 0;
}
bool increaseCarry(char* num)
{
	int carryFlag = 0;  //+1可能产生的进位标志
	bool owerFlow = false;  //溢出标志位
	int total = 0;
	int len = strlen(num);
	for(int idx = len-1;idx>=0;--idx)
	{
		total = num[idx] - '0' + carryFlag;  //末尾转换成十进制数字
		if(len-1==idx)
			total++;  //末尾加一操作
		if(total>=10)  //进位
		{
			if(0==idx)//进位发生在最高位
			{
				owerFlow = true;
				return owerFlow;
			}
			total -= 10;
			num[idx] = total + '0';
			carryFlag = 1;
		}
		else 
		{
			num[idx] = total + '0';
			break;
		}
	}
	return owerFlow;
}
void print(char* num)
{
	int len = strlen(num);
	for(int idx = 0 ;idx!=len;++idx)
	{
		if(num[idx]=='0')
			continue;
		printf("%s\t",num+idx);  
		break;
	}
}
void test(int n)
{
	printMaxNum(n);
}
#endif