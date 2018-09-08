#if 0
#include <iostream>
#include<map>
#include<set>
#include<string>
using namespace std;
int getDataInt(string tmp)
{
	return atoi(tmp.c_str());
}
int main() 
{
	int inputCnt;
	cin>>inputCnt;
	int time;
	cin>>time;
	multimap<int,int> InDian;
	multimap<int,int> OutDian;
	while(inputCnt)
	{
		int key,timeIn,timeOut;
		cin>>key>>timeIn>>timeOut;
		InDian.insert(::make_pair(timeIn,key));
		OutDian.insert(::make_pair(timeOut,key));
		--inputCnt;
	}
	auto it1 = InDian.upper_bound(time);  //>
	auto it2 = OutDian.lower_bound(time);  //>=
	set<int>  ans1;
	for(auto begIt = InDian.begin();begIt!=it1;++begIt)
	{
		ans1.insert(begIt->second);
	}
	set<int>  ans2;
	for(auto begIt = it2;begIt!=OutDian.end();++begIt)
	{
		ans2.insert(begIt->second);
	}
	//½á¹û
	set<int> res;
	for(auto it=ans1.begin();it!=ans1.end();++it)
	{
		auto iit = ans2.find(*it);
		if(ans2.end()!=iit)
			res.insert(*it);
	}
	if(0==res.size())
		cout<<"null"<<endl;
	else
	{
		for(auto elem:res)
		cout<<elem<<endl;

	}
	//system("pause");
}
#endif