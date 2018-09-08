#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
#if 0
typedef struct infoMember
{
	int perm;
	string name;
	int onOrOffline;
}info,*pInfo;
void mysort(pInfo arr,int N);
int main()
{
	int N;
	cin>>N;
	info* arr = new info[N];
	int tmp = N;
	while(N)
	{
		int perm;
		string name;
		cin>>perm>>name;
		arr[N-1].name = name;
		arr[N-1].perm = perm;
		arr[N-1].onOrOffline = 0;
		--N;
	}
	N = tmp;
	int M;
	cin>>M;
	map<string,int> status;
	for(int idx=0;idx!=N;++idx)
	{
		status.insert(::make_pair(arr[idx].name,0));
	}
	while(M)
	{
		int change;
		string name;
		cin>>name>>change;
		status[name] = change;
		--M;
	}
	for(int idx=0;idx!=N;++idx)
	{
		auto it = status.find(arr[idx].name);
		arr[idx].onOrOffline = it->second;
	}
	mysort(arr,N);
	for(int idx=0;idx!=N;++idx)
	{
		cout<<arr[idx].name<<endl;
	}
	delete []arr;
	arr = NULL;
	system("pause");
}
void mysort(pInfo arr,int N)
{
	if(NULL==arr||N<=0)
		return ;
	sort(arr,arr+N,[](const info& a,const info& b){ return a.perm>b.perm; });
	sort(arr,arr+N,[](const info& a,const info& b){ return a.onOrOffline>b.onOrOffline; });
	for(int idx=0;idx!=N;++idx)
	{
		for(int iidx=idx+1;iidx!=N;++iidx)
		{
			if( arr[idx].onOrOffline==arr[iidx].onOrOffline &&
				arr[idx].perm==arr[iidx].perm &&
				arr[idx].name>arr[idx].name )
			{
				info tmp = arr[idx];
				arr[idx] = arr[iidx];
				arr[iidx] = tmp;
			}
		}
	}
}
#endif
//6
//0 lc
//2 zj1
//1 ly
//0 zmj
//1 zhq
//0 mly
//10
//lc 1
//ly 1
//zj1 1
//zj1 0
//mly 1
//zhq 1
//lc 0
//zmj 1
//zmj 0
//ly 0
//zhq
//mly
//zj1
//ly
//zmj
//lc