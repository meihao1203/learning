#if 0
#include<iostream>
#include<vector>
using namespace std;
static int apartments = 0;
void func(int **arr,int n,int idx,int jdx);
int main()
{
	int cnt;
	cin>>cnt;
	int** arr = new int*[cnt];
	for(int idx=0;idx<cnt;++idx)
	{
		arr[idx] = new int[cnt]();
	}
	for(int idx=0;idx<cnt;++idx)
	{
		for(int jdx=0;jdx<cnt;++jdx)
		{
			int tmp;
			cin>>tmp;
			arr[idx][jdx] = tmp;
		}
	}

	for(int idx=0;idx<cnt;++idx)
	{
		for(int jdx=0;jdx<cnt;++jdx)
		{
			if(arr[idx][jdx]==1)
			{
				++apartments;
				func(arr,cnt,idx,jdx);  //相邻的位置有1都可以清零了
			}
			
		}
	}
	cout<<apartments<<endl;
	//system("pause");
}
void func(int **arr,int n,int idx,int jdx)
{
	if(idx>=n||jdx>=n)
		return;
	if(0==arr[idx][jdx])
		return;
	arr[idx][jdx] = 0;
	func(arr,n,idx+1,jdx);  //左边清零
	func(arr,n,idx,jdx+1);  //下边清零
}
#endif