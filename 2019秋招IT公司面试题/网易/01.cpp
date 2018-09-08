#include<iostream>
using namespace std;
#if 0
void tax(int cnt);
float taxCore(float total);
int main(int argc,char** argv)
{
	int cnt;
	cin>>cnt;
	tax(cnt);
	//system("pause");
}
void tax(int cnt)
{
	if(cnt<=0)
		return ;
	int* arr = new int[cnt]();
	for(int idx=0;idx!=cnt;++idx)
	{
		cin>>arr[idx];
	}
	for(int idx=0;idx!=cnt;++idx)
	{
		float tmp = taxCore(arr[idx]);
		if( (static_cast<int>(tmp*10) % 10) >=5 )
		{
			arr[idx] = static_cast<int>(tmp) + 1;
		}
		else
			arr[idx] = static_cast<int>(tmp);
	}
	for(int idx=0;idx!=cnt;++idx)
	{
		cout<<arr[idx]<<endl;
	}
	delete arr;
	arr = NULL;
	return ;
}
float taxCore(float total)
{
	if(total<0)
		return -1;
	total -= 5000;
	if(total>80000)
	{
		
		total = (total - 80000) * 0.45 + 
			(80000 - 55000) * 0.35 + 
			(55000 - 35000) * 0.30 + 
			(35000 - 25000) * 0.25 +
			(25000 - 12000) * 0.20 +
			(12000 - 3000) * 0.10 + 
			3000 * 0.03;
		return total;
	}
	else if(total>55000)
	{
		total = (total - 55000) * 0.35 +
			(55000 - 35000) * 0.30 + 
			(35000 - 25000) * 0.25 +
			(25000 - 12000) * 0.20 +
			(12000 - 3000) * 0.10 + 
			3000 * 0.03;
		return total;
	}
	else if(total>35000)
	{
		total = (total - 35000) * 0.30 +
			(35000 - 25000) * 0.25 +
			(25000 - 12000) * 0.20 +
			(12000 - 3000) * 0.10 + 
			3000 * 0.03;
		return total;
	}
	else if(total>25000)
	{
		total = (total - 25000) * 0.25 +
			(12000 - 3000) * 0.10 + 
			3000 * 0.03;
		return total;
	}
	else if(total>12000)
	{
		total = (total - 12000) * 0.20 +
			(12000 - 3000) * 0.10 + 
			3000 * 0.03;
		return total;
	}
	else if(total>3000)
	{
		total = (total - 3000) * 0.10 +
			3000 * 0.03;
		return total;
	}
	else 
		return 0;
}
#endif