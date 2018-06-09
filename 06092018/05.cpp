//题目33：输入一个正整数数组，把数组里面所有数字拼接起来排成一个数，打印出能拼接处的所有数字中最小的一个。
//例如输入数组{3,32,321}，则定义出这三个数字能排成的最小数字321323。
//思路：把数组元素放到字符串数组里面，使用库函数qsort排序，排序规则就是任意两个字符串拼接在一起，那种拼接法
//最终得到的字符串小。如例子中的一样，321 32 2
//时间复杂度O(nlogn)
#if 0
#include<iostream>
using namespace std;
int compare(const void* left,const void* right);
void MinNumber(int* arr,int length);
void test(int* arr,int length);
int main()
{
	int arr[] = {3,32,321};
	test(arr,3);
	cout<<endl;

	int arr2[] = {123,312,31};
	test(arr2,3);
	cout<<endl;

	int* arr3 = NULL;
	test(arr3,1);
	cout<<endl;

	int arr4[] = {1,2,3,4};
	test(arr4,4);
	cout<<endl;

	int arr5[] = {1};
	test(arr5,1);
	cout<<endl;
	system("pause");
}
void test(int* arr,int length)
{
	MinNumber(arr,length);
}
void MinNumber(int* arr,int length)
{
	if(NULL==arr||length<=0)
	{
		cout<<"input error!"<<endl;
		return ;
	}
	int strSize = 10;
	char** twoArr = new char*[length];
	for(int idx=0;idx!=length;++idx)
	{
		twoArr[idx] = new char[strSize];
		sprintf(twoArr[idx],"%d",arr[idx]);
	}
	qsort(twoArr,length,sizeof(char*),compare);
	for(int idx=0;idx!=length;++idx)
	{
		cout<<twoArr[idx];
	}
	cout<<endl;
	for(int idx=0;idx!=length;++idx)
		delete []twoArr[idx];
	delete []twoArr;
}
int compare(const void* left,const void* right)
{
	char** pleft = (char**)(left);
	char** pright = (char**)(right);
	char* leftRight = new char[100];
	char* rightLeft = new char[100];
	strcpy(leftRight,*pleft);
	strcat(leftRight,*pright);
	strcpy(rightLeft,*pright);
	strcat(rightLeft,*pleft);
	int ret = strcmp(leftRight,rightLeft);
	delete leftRight;
	delete rightLeft;
	return ret;
}
#endif
//321323
//
//12331231
//
//input error!
//
//1234
//
//1
