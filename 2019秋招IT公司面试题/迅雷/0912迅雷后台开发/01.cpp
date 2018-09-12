#if 0 
#include<iostream>
#include<algorithm>
using namespace std;
static int cnt = 0;
bool isPrime(int a,int b)
{
	if(a==0||b==0)
		return false;
	while(a)
	{
		int tmp = b%a;
		b = a;
		a = tmp;
	}
	if(b==1)
		return true;
	return false;
}
bool isEveryPrime(int a,int b,int c)
{
	return isPrime(a,b)&isPrime(a,c)&isPrime(b,c);
}
bool isGougu(int a,int b,int c)
{
	int arr[3] = {a,b,c};
	sort(arr,arr+3);
	if((arr[0]*arr[0]+arr[1]*arr[1])==arr[2]*arr[2])
		return true;
	return false;
}
int main()
{
	int N;
	cin>>N;
	for(int a=1;a<=N;++a)
	{
		for(int b=a;b<=N;++b)
		{
			for(int c=b;c<=N;++c)
			{
				if(isGougu(a,b,c)&&isEveryPrime(a,b,c))
					++cnt;
			}
		}
	}
	cout<<cnt<<endl;
	//system("pause");
}
#endif