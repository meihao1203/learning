//题目20：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
//思路：注意边界条件和结束条件
//每次都是矩阵的对角开始打印，(0,0)-(1,1)-(2,2)
//设置遍历起始条件，和终止条件
int printMatrix(int **arr,int rows,int columns);   //动态定义的二维数组才能这样传值
//int printMatrix(int (*arr)[4],int rows,int columns);  //普通数组这样传值
void test(int **arr,int rows,int columns);
int printTwoMatrix(int **arr,int rows,int columns);
#include<iostream>
using namespace std;
int main()
{
	int** arr = new int*[3];
	arr[0] = new int[3];
	arr[1] = new int[3];
	arr[2] = new int[3];
	int total = 0;
	for(int idx=0;idx<3;++idx)
	{
		for(int iidx=0;iidx<3;++iidx)
		{
			++total;
			*(*(arr + idx) + iidx) = total ;  //也可以这样写
		}
	}

	int** arr1 = new int*[1];
	arr1[0] = new int[2];
	arr1[0][0] = 1;
	arr1[0][1] = 2;

	int** arr2 = new int*[2];
	arr2[0] = new int[1];
	arr2[1] = new int[1];
	arr2[0][0] = 1;
	arr2[1][0] = 2; 


	int** arr3 = new int*[1];
	arr3[0] = new int[1];
	arr3[0][0] = 1;


	int** arr4 = new int*[2];
	arr4[0] = new int[2];
	arr4[1] = new int[2];
	arr4[0][0] = 1;
	arr4[0][1] = 2;
	arr4[1][0] = 3;
	arr4[1][1] = 4;


	int** arr5 = new int*[4];
	arr5[0] = new int[4];
	arr5[1] = new int[4];
	arr5[2] = new int[4];
	arr5[3] = new int[4];
	arr5[0][0] = 1;
	arr5[0][1] = 2;
	arr5[0][2] = 3;
	arr5[0][3] = 4;
	arr5[1][0] = 5;
	arr5[1][1] = 6;
	arr5[1][2] = 7;
	arr5[1][3] = 8;
	arr5[2][0] = 9;
	arr5[2][1] = 10;
	arr5[2][2] = 11;
	arr5[2][3] = 12;
	arr5[3][0] = 13;
	arr5[3][1] = 14;
	arr5[3][2] = 15;
	arr5[3][3] = 16;

	test(arr,3,3);
	cout<<endl;
	test(arr1,1,2);  // 第一次调试这里打印1,2,1；
	// 还是分析问题错了，不能直接来就进for循环，要先判断一下是不是还有打印的必要了,就比如这里的1*2的数组
	cout<<endl;
	test(arr2,2,1);
	cout<<endl;
	test(arr3,1,1);
	cout<<endl;
	test(arr4,2,2);
	cout<<endl;
	test(arr5,4,4);
}
int printMatrix(int **arr,int rows,int columns)
{
	if(NULL==arr||rows<=0||columns<=0)
		return -1;
	int start = 0;  //定义打印的起点，都是矩阵的左上角
	while(rows>start*2&&columns>start*2)
	{
		int endx = rows - 1 - start;  //定义结束点，都是矩阵的右下角
		int endy = columns - 1 - start;
		//打印从左到右  //这里不用判定了，进来肯定是要进这个循环的
		for(int idx = start;idx<=endy;++idx)
		{
			cout<<arr[start][idx]<<"\t";
		}
		//打印从上到下  //判断矩阵是不是多行的
		if(endx>start)
		{
			for(int idx=start+1;idx<=endx;++idx)
			{
				cout<<arr[idx][endy]<<"\t";
			}
		}
		//打印从右到左  //不光要多行，还要多列，不然没有打印的必要 比如1*2的矩阵
		if(endx>start&&endy>start)
		{
			for(int idx=endy-1;idx>=start;--idx)
			{
				cout<<arr[endx][idx]<<"\t";
			}
		}
		//打印从下到上  //多列多行
		if(endx>start&&endy>start)
		{
			for(int idx=endx-1;idx>start;--idx)
			{
				cout<<arr[idx][start]<<"\t";
			}
		}
		++start;
	}
	cout<<endl;
	return 0;
}
void test(int **arr,int rows,int columns)
{
	printTwoMatrix(arr,rows,columns);
	printMatrix(arr,rows,columns);
}
int printTwoMatrix(int **arr,int rows,int columns)
{
	for(int idx=0;idx<rows;++idx)
	{
		for(int iidx=0;iidx<columns;++iidx)
		{
			//cout<<arr[idx][iidx]<<"\t";
			cout<<*(*(arr + idx) + iidx) <<"\t";
		}
		cout<<endl;
	}
	return 0;
}
