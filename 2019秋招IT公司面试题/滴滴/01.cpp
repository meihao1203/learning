#include<iostream>
#include<string>
#include<string.h>
#include<set>
#include<vector>
#include<sstream>
using namespace std;
set<char> first;
set<char> second;
int min(int a,int b,int c)
{
	return a>b?(a>c?a:c):(b>c?b:c);
}
int edit(string source,string target)
{
	int len1 = source.size();
	int len2 = target.size();
	int** arr = new int*[len1+1];
	for(int idx=0;idx<len1+1;++idx)
		arr[idx] = new int[len2+1];
	for(int idx=0;idx<len1+1;++idx)
		arr[idx][0] = idx*3;
	for(int idx=0;idx<len1+1;++idx)
		arr[0][idx] = idx*3;
	for(int idx=1;idx<len1+1;++idx)
	{
		for(int jdx=1;jdx<len2+1;++jdx)
		{
			int tmp;
			if(idx==jdx)  //要修改
			{
				if(source[idx] == target[jdx])
					tmp = 0;
				else
				{
					if(first.find(target[jdx])!=first.end()&&first.find(source[idx])!=first.end())  //分组内
						tmp = 1;
					else if(second.find(target[jdx])!=second.end()&&second.find(source[idx])!=second.end())
						tmp = 1;
					else 
						tmp = 2;
				}	
			}
			arr[idx][jdx] = min(arr[idx-1][jdx]+3,arr[idx][jdx-1]+3,arr[idx][jdx]+tmp);
		}
	}
	return arr[len1][len2];
}
typedef struct NODE
{
	string word;
	int weight;
}node;
int main()
{
	string source;
	vector<string> target;
	cin>>source;
	string tmp;
	while(cin>>tmp)
	{
		target.push_back(tmp);
	}
	istringstream iss("q w e r t a s d f g z x c v ");
	char ch;
	while(iss>>ch)
		first.insert(ch);
	istringstream iss("y u i o p h j k l b n m");
	while(iss>>ch)
		second.insert(ch);
	vector<node> reuslt;
	for(int idx=0;idx<target.size();++idx)
	{
		int ret = edit(source,target[idx]);
		node tmp;
		tmp.word = target[idx];
		tmp.weight = ret;
		reuslt.push_back(tmp);
	}
	system("pause");
}