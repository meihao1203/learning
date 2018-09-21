#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> result;
	int years;
	cin>>years;
	result.reserve(1024);
	result.push_back(0);
	for(int idx=0;idx<years;++idx)
	{
		int newPush = 0;
		for(auto& elem: result)
		{
			++elem;
			if(elem>=4)
				++newPush;
		}
		while(newPush)
		{
			--newPush;
			result.push_back(0);  //ษ๚ะกลฃ
		}
	}
	int total = result.size();
	int newCows = 0;
	for(auto elem:result)
	{
		if(elem<=4)
			++newCows;
	}
	int oldCows = 0;
	for(auto elem:result)
	{
		if(elem>4)
			++oldCows;
	}
	cout<<"total = "<<total<<", newCows = "<<newCows<<", oldCows = "<<oldCows<<endl;
	system("pause");
}