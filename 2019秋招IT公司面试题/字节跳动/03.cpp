#if 0
#include<iostream>
#include<string.h>
#include<string>
#include<sstream>
#include<set>
#include<map>
using namespace std;
void func(set<int>&ans,int* arr,int idx);
int main()
{
	int N;
	int M;
	cin>>N>>M;
	int* arr = new int[M+1];
	memset(arr,0,(M+1)*sizeof(int));
	int a,b;
	for(int idx=0;idx<M;++idx)
	{
		cin>>a>>b;
		arr[b] = a;
	}
	map<int,set<int> > ans;
	for(int idx=1;idx<=N;++idx)
	{
		func(ans[idx],arr,idx);
	}
	int cnts = 0;
	for(auto it = ans.begin();it!=ans.end();++it)
	{
		if((it->second).size()==(N-1))
			++cnts;
	}
	cout<<cnts;
	//system("pause");
}
void func(set<int>&ans,int* arr,int idx)
{
	if(arr[idx]==0)
		return;
	int tmp = idx;
	while(arr[idx]!=tmp&& (ans.find(arr[idx]))==ans.end() )
	{
		ans.insert(arr[idx]);
		idx = arr[idx];
	}
}
#endif 