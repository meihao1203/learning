//题目41扩展：输入一个正数s，打印出所有和为s的连续正数序列(至少含有两个数)。
//例如输入15,1+2+3+4+5=4+5+6=7+8=15,打印结果就为这三个连续序列。
//思路：参考40题的思路，连续的整数序列，假设最初两个数是1和2，用两个变量记录，如果1+2<给定的数，记录大数的变量+1，
//加到相同就输出，然后记录大数变量继续+1。如果加完大于给定的数，就增加记录小数的变量。
//终止条件就是指示小数的变量>给定的数+1除以2。因为最少序列有两个数且连续
#include<iostream>
using namespace std;
void findContinueSequence(int num);
void printSequence(int first,int second);
void test(int num);
int main()
{
	test(15);
	cout<<endl;

	test(7);
	cout<<endl;
}
void test(int num)
{
	findContinueSequence(num);
}
void printSequence(int first,int second)
{
	if(first>second||first<0||second<0)
		return ;
	for(int idx=first;idx<=second;++idx)
		cout<<idx<<" ";
	cout<<endl;
}
void findContinueSequence(int num)
{
	if(num<3)
		return ;
	int first = 1,second = 2;
	int sum = first + second;
	int index = (num+1)/2;
	while(first<index)  //先开始一直增加second,直到大于给定的数num,然后再去减去一个最小值，直到相等或条件不满足
	{
		if(sum==num)
			printSequence(first,second);
		while(sum>num&&first<index) //加到sum>num
		{
			sum -= first;  //先减去一个最小值
			++first;
			if(sum==num)
				printSequence(first,second);
		}
		++second;
		sum += second;
	}
	return ;
}
//1 2 3 4 5
//4 5 6
//7 8
//
//3 4
