#if 1
#include<iostream>
using namespace std;
#define max 100001
static int times = 0;
void func(int* arr,int L,int R,int t);
int main()
{
	int n,k,t;
	cin>>n>>k>>t;
	int arr[max] = {};
	for(int idx=0;idx!=n;++idx)
	{
		int tmp;
		cin>>tmp;
		arr[idx] = tmp;
	}
	//计算
	for(int L=1;L<=n;++L)
	{
		for(int R = L;R<=n;++R)
		{
			if((R-L+1)==k)  //满足条件一
			{
				func(arr,L-1,R-1,t);  //计算是否出现t次
				break;
			}
			if((R-L+1)>k)
				break;
		}
	}
	cout<<times<<endl;
	//system("pause");
}
void func(int* arr,int L,int R,int t)
{
	for(int idx=L;idx<=R;++idx)
	{
		int cnt = 0,value = arr[idx];
		for(int jdx=L;jdx<=R;++jdx)
		{
			if(value==arr[jdx])
				cnt++;
			if(t==cnt)
				break;
		}
		if(t==cnt)
		{
			++times;
			break;
		}
	}
	return ;
}
#endif