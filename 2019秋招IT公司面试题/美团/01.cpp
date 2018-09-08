#include<iostream>
#include<set>
using namespace std;
static int total = 0;
static set<int> everyNode;
void travesal(int** arr,bool* visited,int nodes,int visit);
int main()
{
	int nodes;
	cin>>nodes;
	//开辟数组空间
	int** arr = new int*[nodes];  
	for(int idx=0;idx!=nodes;++idx)
	{
		arr[idx] = new int[nodes];
	}
	//读入数据
	for(int idx=0;idx<nodes-1;++idx)
	{
		int first,second;
		cin>>first>>second;
		arr[first-1][second-1] = 1;
	}
	bool* visited  = new bool[nodes];
	for(int idx=0;idx!=nodes;++idx)
	{
		visited[idx] = false;
	}
	travesal(arr,visited,nodes,0);
	cout<<total+1<<endl;
	system("pause");
}
void travesal(int** arr,bool* visited,int nodes,int visit)
{
	if(everyNode.size()==nodes)
		return ;
	visited[visit] = true;
	for(int idx=1;idx<nodes;++idx)
	{
		if(visited[idx]==false &&
			arr[visit][idx]==1)
		{
			everyNode.insert(idx);
			travesal(arr,visited,nodes,idx);
			++total;
		}
	}
}