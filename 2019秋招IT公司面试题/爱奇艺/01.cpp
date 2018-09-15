#if 0
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int N,M,P;
	cin>>N>>M>>P;
	int* arr = new int[N];
	for(int idx=0;idx<N;++idx)
	{
		int tmp;
		cin>>tmp;
		arr[idx] = tmp;
	}
	for(int idx=0;idx<M;++idx)
	{
		char access;
		int num;
		cin>>access>>num;
		if('A'==access)
		{
			arr[num-1] += 1;
		}
		if('B'==access)
		{
			arr[num-1] -= 1;
		}
	}
	int numP = arr[P-1];
	sort(arr,arr+N,[](int a,int b){return a>b;});

	for(int idx=0,level=1;idx<M;++idx)
	{
		if(numP==arr[0])
		{
			cout<<1<<endl;
			break;
		}
		if(arr[idx]==arr[idx-1])
		{
			if(numP==arr[idx])
			{
				cout<<level<<endl;
				break;
			}		
		}
		if(arr[idx]!=arr[idx-1])
		{
			level = idx+1;
			if(numP==arr[idx])
			{
				cout<<level<<endl;
				break;
			}		
		}	
	}
	//system("pause");
}
#endif