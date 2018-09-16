#if 0
#include<iostream>
#include<vector>
using namespace std;
int maxCommonDivisor(int a,int b)
{
	if(a<b)
		::swap(a,b);
	while(b>0)
	{
		int tmp = a%b;
		a = b;
		b = tmp;
	}
	return a;
}
int mincommonMultiple(int a,int b)
{
	int tmp = (a*b)/maxCommonDivisor(a,b);
	return tmp;
}
bool LCM(int n,int m)
{
	vector<int> first;
	vector<int> second;
	for(int idx=n+1;idx<=m;++idx)
	{
		first.push_back(idx);
	}
	for(int idx=1;idx<=m;++idx)
	{
		second.push_back(idx);
	}
	//找first的最大公约数
	int firstMax = 1;
	for(int idx=0;idx<first.size();++idx)
	{
		for(int jdx=idx+1;jdx<first.size();++jdx)
		{
			int tmp = maxCommonDivisor(first[idx],first[jdx]);
			if(0!=tmp)
			firstMax *= tmp;
			//if(tmp>firstMax)
			//	firstMax = tmp;
		}
	}
	int secondMax = 1;
	for(int idx=0;idx<second.size();++idx)
	{
		for(int jdx=idx+1;jdx<second.size();++jdx)
		{
			int tmp = maxCommonDivisor(second[idx],second[jdx]);
			if(tmp==idx+1&&tmp!=0)
			secondMax *= tmp;
			//if(tmp>secondMax)
			//	secondMax = tmp;
		}
	}
	//判断
	int firstMulti = 1;
	for(auto elem:first)
		firstMulti *= elem;
	int secondMulti = 1;
	for(auto elem:second)
		secondMulti *= elem;
	if(firstMulti/firstMax == secondMulti/secondMax)
		return true;
	return false;
}
int main()
{
	int n;
	cin>>n;
	int res;
	for(int idx=n+1;idx<=10e6;++idx)
	{
		if(LCM(n,idx))
		{
			res = idx;
			break;
		}
	}
	cout<<res<<endl;
	system("pause");
}
#endif