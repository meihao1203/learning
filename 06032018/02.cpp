//递归求解n个数的和
#include<iostream>
using namespace std;
int add(int* arr,int n);
#if 0
int main()
{
	int arr[] = {2,2,3,4,5};
	int res = add(arr,5);
	cout<<res<<endl;
	system("pause");
}
#endif
int add(int* arr,int n)
{
	if(NULL==arr||n<0)
		return -1;
	return n==0?0:(arr[n-1]+add(arr,n-1));
}