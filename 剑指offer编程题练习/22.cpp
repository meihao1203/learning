//题目22：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是不是该栈的弹出顺序。
//假设所有数字均不相等,eg：1，2,3,4,5->4,5,3,2,1 true; 1,2,3,4,5->4,3,5,1,2 false
//思路：借助一个辅助数组，模拟压栈序列和弹栈序列
//把算法使用两个整数数组存放序列，如果第一个序列的数字和第二个序列数组相同则弹栈
//算法最后判断辅助栈是不是空，以及弹栈序列是不是遍历完
#include<iostream>
#include<stack>
using namespace std;
bool isPopOrder(int* pushOrder,int* popOrder,int length);
void test(int* pushOrder,int* popOrder,int length);
int main()
{
	int arrPush[] = {1,2,3,4,5};
	int arrPop[] = {4,5,3,2,1};
	test(arrPush,arrPop,5);
	cout<<endl;

	int arr2Pop[] = {4,3,5,1,2};
	test(arrPush,arr2Pop,5);
	cout<<endl;

	int arr3Push[] = {1};
	int arr3Pop[] = {1};
	test(arr3Push,arr3Pop,1);
	cout<<endl;

	int* arr4Push = NULL;
	int* arr4Pop = NULL;
	test(arr4Push,arr4Pop,5);
	cout<<endl;
}
void test(int* pushOrder,int* popOrder,int length)
{
	bool flag = isPopOrder(pushOrder,popOrder,length);
	cout<<flag<<endl;
}
bool isPopOrder(int* pushOrder,int* popOrder,int length)
{
	bool flag = false;
	if(NULL==pushOrder||NULL==popOrder||length<=0)
	{
		return flag;
	}
	int* tmpPushOrder = pushOrder;  //临时变量暂存数组首地址
	int* tmpPopOrder = popOrder;
	stack<int> tmpStack;
	while(tmpPopOrder-popOrder<length)  //出栈数组没有遍历完
	{
		//压栈顺序中找到和出栈顺序一样的数字
		while(tmpStack.empty()||tmpStack.top()!=*tmpPopOrder)
		{
			if(tmpPushOrder-pushOrder==length)
				break;
			tmpStack.push(*tmpPushOrder);  //如果压栈序列中tmpPushOrder不是出栈序列tmpPopOrder，就把这个数字压栈，
			++tmpPushOrder;  //压栈序列中找下一个
		}
		if(tmpStack.top()!=*tmpPopOrder)  //如果是break出的while循环，这里要判断
			break;
		tmpStack.pop();
		++tmpPopOrder;  //判断出栈序列中的下一个元素
	}
	if(tmpStack.empty()&&tmpPopOrder-popOrder==length)
	{
		flag = true;
	}
	return flag;
}
//1
//
//0
//
//1
//
//0
