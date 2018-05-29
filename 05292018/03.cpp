#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int arr[3] = {3,2,4};
	vector<int> ve(arr,arr+3);
	for(auto& elem:ve)
		cout<<elem<<" ";
	cout<<endl;
	system("pause");
}
