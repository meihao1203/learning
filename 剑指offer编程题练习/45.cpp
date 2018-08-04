//题目45：圆圈中最后剩下的数字。0,1，...，n-1这n个数字排成一个圆圈，从数字0开始每次从这个圆圈里
//删除第m个数字。求出这个圆圈里剩下的最后一个数字。
//eg：{0,1,2,3,4}->每次删除第三个数字->{2,0,4,1}->3
//思路：这就是一个约瑟夫(Josephuse)环问题，可以模拟出一个链表，然后进行删除。如果可以用标准模板库，直接使用list
//只不过要记得最后到达迭代器末尾要重新修改指向头。
//n个数字每次删除第m个数字。时间复杂度O(mn)，空间复杂度O(m)
#if 0
#include<iostream>
#include<list>
using namespace std;
//第一种做法
#if 0
int lastReamining(unsigned int n,unsigned int m)
{
	if(n<1||m<1)
		return -1;
	list<int> numbers;
	for(int idx=0;idx<n;++idx)
		numbers.push_back(idx);
	list<int>::iterator current = numbers.begin();
	while(numbers.size()>1)
	{
		for(int i=1;i<m;++i)
		{
			++current;
			if(current==numbers.end())
				current==numbers.begin();
		}
		list<int>::iterator next = ++current;
		if(next==numbers.end())
			next = numbers.begin();
		--current;
		numbers.erase(current);
		current = next;
	}
	return *(current);
}
#endif
// P248有推导公式
//f(n,m)表示1~n的元素里面一次删除第m个元素，最后剩的那一个元素
//当n=1时：f(n,m) = 0;  n>1时：f(n,m) = [f(n-1,m) + m]%n。
int LastRemaining(int n,int m)
{  //时间复杂度O(n),空间复杂度O(1)
	if(n<1||m<1)
		return -1;
	int last = 0;  //从0开始遍历删除，n - 1 = 1,即最开始f(n-1,m) = 0;
	for(int i=2;i<=n;++i)  //循环，不是递归，所以到着来求最终解
		//最后剩下两个元素，然后删除第m个，剩下一个。
	{
		last = (last + m) % i;
	}
	return last;
}
int main()
{
	cout<<LastRemaining(5,3)<<endl;
	cout<<LastRemaining(5,2)<<endl;
	cout<<LastRemaining(6,7)<<endl;
	cout<<LastRemaining(6,6)<<endl;
	cout<<LastRemaining(0,0)<<endl;
	system("pause");
}
#endif
//3
//2
//4
//3
//-1