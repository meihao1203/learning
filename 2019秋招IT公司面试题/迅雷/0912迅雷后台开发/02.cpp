#include<iostream>
#include<vector>
using namespace std;
static int  maxValue = 0;
bool isTure(vector<int>& vec)
{
	int sum = 0;
	for(int idx=0;idx<17;++idx)
	{
		int num = 7;
		int pos = idx;
		sum = 0;
		while(num>0&&pos<17)
		{
			sum += vec[pos];
			--num;
			++pos;
		}
		if(sum<0)
			continue;
		else
			return false;
	}
	return true;
}
void func(vector<int>& vec,int A,int B,int idx,int total)
{
	if(idx==total)
	{
		if(isTure(vec))
		{
			int max = 0;
			for(int index=0;index<17;++index)
				max += vec[index];
			if(maxValue<max)
				maxValue = max;
		}
		return ;
	}
	if(idx>total)
		return;
	vec[idx] = A;
	func(vec,A,B,idx+1,total);
	vec[idx] = B;
	func(vec,A,B,idx+1,total);
}

int main()
{
	int A,B;
	cin>>A>>B;
	vector<int> vec(20);
	func(vec,A,B,0,17);
	cout<<maxValue<<endl;
	//system("pause");
}