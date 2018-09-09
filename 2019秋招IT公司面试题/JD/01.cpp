#if 0
#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;
void func();
static vector<string> result;
int main()
{
	int T;
	cin>>T;
	while(T)
	{
		func();
		--T;
	}
	for(auto elem:result)
		cout<<elem<<endl;
	system("pause");
}
void func()
{
	int N,M;
	cin>>N>>M;
	vector<set<int> > edge(N,set<int>());
	//set<int> tmp();
	for(int idx=0;idx<M;++idx)
	{
		int a,b;
		cin>>a>>b;
		edge[a-1].insert(b-1);
	}
	int cnts = 0;
	int begin = 0;
	while(edge[begin].size()!=0)
	{
		if(edge[begin].size()==(N-1))
		{
			result.push_back("NO");
			return;
		}
		++cnts;
		begin = *(edge[begin].begin());
	}
	if(cnts==(N-1))
		result.push_back("NO");
	else
		result.push_back("YES");
}
#endif