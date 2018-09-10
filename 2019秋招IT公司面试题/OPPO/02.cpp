#if 0
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(int argc,char** argv)
{
	vector<int> N;
	//读入标准输入到数组N中
	int cnts;
	cin>>cnts;
	while(cnts)
	{
		int tmp;
		cin>>tmp;
		N.push_back(tmp);
		--cnts;
	}
	//从N中任意取出两个数求和得到数组A
	vector<int> A;
	for(int idx=0;idx<N.size()-1;++idx)
	{
		for(int iidx=idx+1;iidx<N.size();++iidx)
		{
			A.push_back(N[idx]+N[iidx]);
		}
	}
	//从N中任意取出两个数组并求差的绝对值，构成数组B
	vector<int> B;
	for(int idx=0;idx<N.size()-1;++idx)
	{
		for(int iidx=idx+1;iidx<N.size();++iidx)
		{
			B.push_back( abs(N[idx]-N[iidx]) );
		}
	}
	//从A和B中任意取出两个数，其差的绝对值构成数组D
	// 先AB组合成元素D1
	vector<int> D1(A);
	for(auto elem:B)
		D1.push_back(elem);
	vector<int> D;
	for(int idx=0;idx<D1.size()-1;++idx)
	{
		for(int iidx=idx+1;iidx<D1.size();++iidx)
		{
			D.push_back( abs(D1[idx]-D1[iidx]) );
		}
	}
	//D中的元素从小到大排序
	sort(D.begin(),D.end());
	int d1 = D[0],d2 = D[D.size()-1],s = D.size();
	cout<<d1+d2+s<<endl;
	system("pause");
}
#endif
//5
//101
//102
//103
//104
//105
//398
//请按任意键继续. . .