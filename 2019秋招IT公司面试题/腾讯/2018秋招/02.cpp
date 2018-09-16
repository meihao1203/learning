#include<iostream>
#include<array>
using namespace std;
int main()
{
	array<char,2> a = {'a','b'};
	cout<<sizeof(array<char,2>)<<endl;
	for(auto elem:a)
		cout<<elem<<endl;

	system("pause");
}