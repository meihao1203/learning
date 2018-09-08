#if 0
#include <iostream>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;
static unordered_map<int,int>  data;
static list<int>  LRU;
static int capacity;
int get(int key);
void put(int key,int value);   //确定要不要更新
int main()
{
	vector<int > ans;

	cin>>capacity;
	char pg;
	int key,value;
	while(cin>>pg)
	{
		if('p'==pg)
		{
			cin>>key>>value;
			put(key,value);
		}
		else 
		{
			cin>>key;
			int ret = get(key);
			ans.push_back(ret);
		}
	}
	for(auto elem:ans)
		cout<<elem<<endl;
	system("pause");
}
int get(int key)
{
	auto it = data.find(key);
	if(data.end()!=it)
	{
		return it->second;
	}
	return -1;
}
void put(int key,int value)
{
	auto it = data.find(key);
	//只需要更新
	if(it!=data.end())
	{//更新
		data[key] = value;
		for(auto iit=LRU.begin();iit!=LRU.end();++iit)
		{ 
			if(*iit==key)
			{
				LRU.erase(iit);
				LRU.push_front(key);
				return;
			}
		}
	}
	else if(data.size()<capacity)
	{//插入新值
		data[key] = value;
		LRU.push_front(key);
		return ;
	}
	else if(data.size()==capacity)  
	{//要替换
		int tmp = LRU.back();
		LRU.pop_back();
		LRU.push_front(key);
		data.erase(tmp);
		//插入新值
		data.insert(::make_pair(key,value));
		return;
	}
}
#endif