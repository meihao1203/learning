#include<iostream>
using namespace std;
int main()
{
	int a[2][3] = {
		{1,2,3},
		{4,5,6},
	};
	int b[3] = {7,8,9};
	cout<<a<<endl;
	cout<<a[0]<<endl;
	cout<<a+1<<endl;   //int[3]*
	cout<<*(a+1)<<endl;
	cout<<a[1]<<endl;
	cout<<*(a+1)+1<<endl;
	cout<<*(*(a+1)+1)<<endl;
	cout<<b<<endl;
	cout<<b[0]<<endl;
	system("pause");
}
//00C5FE4C
//00C5FE4C
//00C5FE58
//00C5FE58
//00C5FE58
//00C5FE5C
//5
//00C5FE38
//7
//请按任意键继续. . .