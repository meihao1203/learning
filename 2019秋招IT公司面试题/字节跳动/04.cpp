#include<iostream>
using namespace std;
bool func(int* arr,int idx);
int main()
{
	int cnts;
	cin>>cnts;
	int* arr = new int[cnts];
	for(int idx = 0;idx!=cnts;++idx)
	{
		int tmp;
		cin>>tmp;
		arr[idx] = tmp;
	}
	cout<<func(arr,cnts)<<endl;
	system("pause");
}
bool func(int* arr,int idx)
{
	if(idx==1)
	{
		if(arr[0]<=0x7F)
		{
			return true;
		}
		return false;
	}
	if(idx==2)
	{
		if(arr[0]&0xE0==0xC0)
		{
			if(arr[1]&0xC0==0x80)
				return true;
			return false;
		}
		else 
			return false;
	}
	if(idx==3)
	{
		if(arr[0]&0xE0==0xC0)
		{
			for(int i = 1;i<=idx;++i)
			{
				if(arr[i]&0xC0==0x80)
					return true;
				return false;
			}
		}
		else 
			return false;
	}
	if(idx==4)
	{
		if(arr[0]&0xF8==0xF0)
		{
			for(int i = 1;i<=idx;++i)
			{
				if(arr[i]&0xC0==0x80)
					return true;
				return false;
			}
		}
		else 
			return false;
	}
	if(idx==5)
	{
		if(arr[0]&0xFC==0xF8)
		{
			for(int i = 1;i<=idx;++i)
			{
				if(arr[i]&0xC0==0x80)
					return true;
				return false;
			}
		}
		else 
			return false;
	}
	if(idx==6)
	{
		if(arr[0]&0xFE==0xFC)
		{
			for(int i = 1;i<=idx;++i)
			{
				if(arr[i]&0xC0==0x80)
					return true;
				return false;
			}
		}
		else 
			return false;
	}
	return false;
}