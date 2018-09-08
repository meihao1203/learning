#include<iostream>
#include<string.h>
using namespace std;
#define MAX 0x7fffffff
void solve(int**arr,int** res,int start,int end,const int& N,const int& M,int steps,int& dis,int& min);
int main()
{
	int N,M;
	cin>>N>>M;
	int** arr = new int*[N];
	for(int idx=0;idx!=N;++idx)
	{
		arr[idx] = new int[N];
	}
	int tmp = 0;
	for(int idx=0;idx!=N;++idx)
	{
		for(int iidx=0;iidx!=N;++iidx)
		{
			cin>>tmp;
			arr[idx][iidx] = tmp;
		}
	}
	//结果数组
	int** res = new int*[N];
	for(int idx=0;idx!=N;++idx)
	{
		res[idx] = new int[N];
	}
	for(int idx=0;idx!=N;++idx)
	{
		for(int iidx=0;iidx!=N;++iidx)
		{
			res[idx][iidx] = MAX;
		}
	}
	//开始处理
	for(int idx=0;idx!=N;++idx)
	{
		for(int iidx=0;iidx!=N;++iidx)
		{
			int step = 0,dis = 0,min = MAX;
			solve(arr,res,idx,iidx,N,M,step,dis,min);
			res[idx][iidx] = min;
		}
	}
	//输出结果
	for(int idx=0;idx!=N;++idx)
	{
		for(int iidx=0;iidx!=N;++iidx)
		{
			cout<<res[idx][iidx]<<" ";
		}
		cout<<endl;
	}
	//释放空间
	system("pause");
}
void solve(int**arr,int** res,int start,int end,const int& N,const int& M,int steps,int& dis,int& min)
{
	if(NULL==arr||NULL==res)
		return ;
	if(steps==M)
	{
		if(start==end&&min>dis)
			min = dis;
		return;
	}
	int tmpdis;
	for(int idx=0;idx!=N;++idx)
	{
		if(start==idx)
			continue;
		tmpdis = dis + arr[start][idx];
		solve(arr,res,idx,end,N,M,steps+1,tmpdis,min);
	}
}
//3 2
//0 2 3
//2 0 1
//3 1 0
//4 4 3
//4 2 5
//3 5 2
//请按任意键继续. . .