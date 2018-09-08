#if 0
#include <iostream>
using namespace std;
int main() 
{
	long long int data;
	cin>>data;
	int idx = 0;
	while(data)
	{
		++idx;
		data = data>>1;
	}
	cout<<idx<<endl;
//	system("pause");
}
#endif