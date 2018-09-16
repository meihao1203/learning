#if 0
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//bool func(int* arr,int cnts,int idx,int sum)
//{
//	if(idx==cnts)
//	{
//		if(sum%arr[0]==0&&
//			sum%arr[1]==arr[2])
//		return true;
//		return false;
//	}
//	for(int iidx=idx;iidx<cnts;++iidx)
//	{
//		sum += arr[iidx];
//		func(arr,cnts,iidx+1,sum);
//	}
//}
bool func(int* arr,int cnts)
{
	if(cnts==1)
	{
		if(arr[0]%arr[0]==0&&
			arr[0]%arr[1]==arr[2])
			return true;
		if(arr[1]%arr[0]==0&&
			arr[1]%arr[1]==arr[2])
			return true;
		if(arr[2]%arr[0]==0&&
			arr[2]%arr[1]==arr[2])
			return true;
		return false;
	}
	if(cnts==2)
	{

		if(arr[0]%arr[0]==0&&arr[1]%arr[0]==0 &&
			(arr[0]+arr[1])%arr[1]==arr[2])
			return true;
		if(arr[0]%arr[0]&&arr[2]%arr[0]==0 &&
			(arr[0]+arr[2])%arr[1]==arr[2])
			return true;
		if(arr[1]%arr[0]&&arr[2]%arr[0]==0&&
			(arr[1]+arr[2])%arr[1]==arr[2])
			return true;
		return false;
	}
	if(cnts==3)
	{
		if(arr[0]%arr[0]&&arr[1]%arr[0]&&arr[2]%arr[0]==0&&
			(arr[0]+arr[1]+arr[2])%arr[1]==arr[2])
			return true;
		return false;
	}
	return false;
}
int main()
{
	vector<string> result;
	int t;
	cin>>t;
	int arr[3];
	for(int idx=0;idx<t;++idx)
	{
		for(int jdx=0;jdx<3;++jdx)
		{
			int tmp;
			cin>>tmp;
			arr[jdx] = tmp;
		}
		bool flag = false;
		for(int cnts=1;cnts<=3;++cnts)
		{
			if(func(arr,cnts))
			{
				flag = true;
				result.push_back("YES");
				break;
			}	
		}
		if(false==flag)
		result.push_back("NO");
	}
	for(auto elem:result)
		cout<<elem<<endl;
	//system("pause");
}
#endif