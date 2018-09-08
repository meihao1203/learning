#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<map>
using namespace std;
void func(multimap<int,vector<string> >& subWords,string input,set<string>& inputWords);
int main()
{
	//录入数据
	string input;
	cin>>input;
	int cnt;
	cin>>cnt;
	set<string> word;
	while(cnt)
	{
		string tmp;
		cin>>tmp;
		word.insert(tmp);
		--cnt;
	}
	//字符串中可以分为哪些单词
	set<string> inputWords;
	for(int idx=0;idx!=input.size();++idx)
	{
		string copyInput = input.substr(idx);
		for(int iidx=0;iidx<=copyInput.size();++iidx)
		{
			string tmp = copyInput.substr(0,iidx);
			if(word.find(tmp)!=word.end())
			{
				inputWords.insert(tmp);
			}
		}
	}
	//计算哪些结果可以拼凑出源字符串
	multimap<int,vector<string> > subWords;
	func(subWords,input,inputWords);
	//得到输入字符串的所有可以组合结果以及值，找出最大的
	//测试结果
	int max = 0;
	for(auto it = subWords.begin();it!=subWords.end();++it)
	{
		if(it->first>max)
			max = it->first;
	}
	auto it = subWords.equal_range(max);
	int maxSize = 0;
	multimap<int,vector<string> >::iterator ans;
	auto iit = it.first;
	for(;iit!=it.second;++iit)
	{
		if((iit->second)[0].size()>maxSize)
		{
			maxSize = (iit->second)[0].size();
			ans = iit;
		}
	}
	for(auto elem:iit->second)
		cout<<elem<<" ";
	cout<<endl;
	system("pause");
}
void func(multimap<int,vector<string> >& subWords,string input,set<string>& inputWords)
{
	static vector<string> rightWords;
	if(input.size()==0)
	{
		int cnt ;
		for(auto elem:rightWords)
		{
			cnt = (elem.size())*(elem.size());
		}
		subWords.insert(::make_pair(cnt,rightWords));
		rightWords.clear();
		return;
	}
	for(int idx=1;idx<=input.size();++idx)
	{
		string tmp = input.substr(0,idx);
		if(inputWords.find(tmp)!=inputWords.end())
		{
			rightWords.push_back(tmp);
			func(subWords,input.substr(idx),inputWords);
		}
	}
}