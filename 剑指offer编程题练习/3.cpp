#include<iostream>
using namespace std;
//找一个二维矩阵中是否存在一个值
bool find(int (*matrix)[4],int rows,int columns,int number);
//int main()
//{
//	int arr[4][4] = {
//		{1,2,8,9},
//		{2,4,9,12},
//		{4,7,10,13},
//		{6,8,11,15}
//	};
//	bool flag = find(arr,4,4,7);
//	cout<<flag<<endl;
//	system("pause");
//}
bool find(int (*matrix)[4],int rows,int columns,int number)
{
	bool flag = false;
	if(matrix != NULL&&rows>0&&columns>0)
	{
		int row = 0;
		int column = columns-1;
		while(row<rows&&column>=0)
		{
			if(matrix[row][column]==number)
			{
				//cout<<"row="<<row<<" column="<<column<<endl;
				flag = true;
				return flag;
			}
			else if(matrix[row][column]>number)
				column--;
			else 
				row++;
		}
	}
	return flag;
}