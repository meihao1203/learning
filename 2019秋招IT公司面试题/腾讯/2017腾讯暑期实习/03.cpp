//小Q今天在上厕所时想到了这个问题：有n个数，两两组成二元组，相差最小的有多少对呢？相差最大呢？
//
//输入描述:
//
// 输入包含多组测试数据。
//
// 对于每组测试数据：
//
// N - 本组测试数据有n个数
//
// a1,a2...an - 需要计算的数据
//
// 保证:
//
// 1<=N<=100000,0<=ai<=INT_MAX.
//  
//输出描述:
//
//对于每组数据，输出两个数，第一个数表示差最小的对数，第二个数表示差最大的对数。
//
//输入例子1:
//
//6
//45 12 45 32 5 6
//
//输出例子1:
//
//1 2
#if 0
#include<iostream>
#include<limits>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
void calculate(vector<int>& data,queue<int>& result);
int myabs(int a,int b)
{
	int tmp = a - b;
	if(tmp<0)
		return -tmp;
	return tmp;
}
int main()
{
	int cnts;
	vector<int> data;
	data.reserve(100000);
	queue<int> result;
	while(cin>>cnts)
	{
		int number;
		while(cnts)
		{
			cin>>number;
			data.push_back(number);
			--cnts;
		}
		calculate(data,result);
		data.clear();
	}
	while(!result.empty())  //emplace
	{
		cout<<result.front()<<" ";
		result.pop();
		cout<<result.front()<<endl;
		result.pop();
	}
	//system("pause");
}
void calculate(vector<int>& data,queue<int>& result)
{
	int cntMax = 0;
	int cntMin = 0;
	//for(int idx=0;idx!=data.size();++idx)  //复杂度太高，运行超时
	//{
	//	for(int iidx=idx+1;iidx!=data.size();++iidx)
	//	{
	//		if(myabs(data[idx],data[iidx]) > max)
	//		{
	//			cntMax = 1;
	//			max = myabs(data[idx],data[iidx]);
	//		}
	//		else if(max == myabs(data[idx],data[iidx]))
	//		{
	//			++cntMax;
	//		}
	//		if(myabs(data[idx],data[iidx]) < min)
	//		{
	//			cntMin = 1;
	//			min = myabs(data[idx],data[iidx]);
	//		}
	//		else if(min == myabs(data[idx],data[iidx]))
	//		{
	//			++cntMin;
	//		}
	//	}
	//}
	//result.push(cntMin);
	//result.push(cntMax);  
	sort(data.begin(),data.end(),[](const int& a,const int&b){return a<b;});
	if(data[0]==data[data.size()-1])  //所有数相同，最大最小差都是0；
	{
		cntMax = cntMin = (data.size()*(data.size()-1))/2;
		result.push(cntMin);
		result.push(cntMax); 
		return ;
	}
	//用map来优化统计
	map<int,int> dataStatistic;
	for(int idx=0;idx!=data.size();++idx)
	{
		auto it = dataStatistic.find(data[idx]);
		if(it == dataStatistic.end())  //map中没有
		{
			dataStatistic.insert(::make_pair(data[idx],1));
		}
		else 
		{
			it->second += 1;
		}
	}
	int max = numeric_limits<int>::min();
	int min = numeric_limits<int>::max();
	if(dataStatistic.size()<data.size())  //有重复数字
	{
		auto it = dataStatistic.begin();
		//计算最小差值对
		for(it;it!=dataStatistic.end();++it)
		{
			if(it->second>1)
			{
				cntMin += ((it->second)*(it->second-1))/2;
			}
		}
	}
	else
	{  //已经排好序了
		for(int idx=1;idx!=data.size();++idx)  
		{
				if(myabs(data[idx],data[idx-1]) < min)
				{
					cntMin = 1;
					min = myabs(data[idx],data[idx-1]);
				}
				else if(min == myabs(data[idx],data[idx-1]))
				{
					++cntMin;
				}
		}
	}
	//计算最大差值对
	int val1 = ( dataStatistic.find(data[data.size()-1]) )->second;
	int val2 = ( dataStatistic.find(data[0]) )->second;
	cntMax = (val1*val2);
	result.push(cntMin);
	result.push(cntMax);  
	return ;
}
#endif