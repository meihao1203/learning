#if 0
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<string.h>
using namespace std;
int func(string str)
{
	int pos = str.find_first_of("#");
	string first = str.substr(0,pos);
	string second = str.substr(pos+1,string::npos);
	int a = atoi(first.c_str());
	if(a>10)
		strlwr(const_cast<char*>(second.c_str()));
	int sum = 0;
	for(int idx = second.size()-1,iidx=0;idx>=0;--idx)
	{
		if(second[idx]>='a')
			sum += (second[idx]-'a'+10)*pow(a,iidx);
		else
			sum += (second[idx]-'0')*pow(a,iidx);
		++iidx;
	}
	return sum;
}

int main()
{
	vector<pair<string,int> > input;
	string tmp;
	while(cin>>tmp,tmp!="END")
	{
		int ret = func(tmp);
		input.push_back(::make_pair(tmp,ret));
	}
	vector<string> output;
	bool flag = false;
	for(int idx=0;idx<input.size();++idx)
	{
		flag = false;
		for(int jdx=0;jdx<input.size();++jdx)
		{
			if(idx==jdx)
				continue;
			if(input[idx].second==input[jdx].second)
			{
				flag = true;
				break;
			}	
		}
		if(false==flag)
			output.push_back(input[idx].first);

	}
	if(0==output.size())
		cout<<"None"<<endl;
	for(auto elem:output)
		cout<<elem<<endl;
	//system("pause");
}
#endif