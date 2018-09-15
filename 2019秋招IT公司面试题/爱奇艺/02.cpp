#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
typedef struct NODE
{
	int a;
	int b;
}node;
void insetArea(set<int>& point,int a,int b)
{
	for(int idx=a+1;idx!=b;++idx)
		point.insert(idx);
}
int main()
{
	int cnts;
	cin>>cnts;
	node* arr = new node[cnts];
	for(int idx=0;idx<cnts;++idx)
	{
		int a,b;
		cin>>a>>b;
		if(a>b)
			::swap(a,b);
		node tmp;
		tmp.a = a;
		tmp.b = b;
		arr[idx] = tmp;
	}
	sort(arr,arr+cnts,[](node a,node b){return a.b<b.b;});
	int res = 1;
	int end = arr[0].b;
	for(int idx=1;idx<cnts;++idx)
	{
		if(arr[idx].a>=end)
		{
			++res;
			end = arr[idx].b;
		}
	}
	cout<<res<<endl;
	//system("pause");
}