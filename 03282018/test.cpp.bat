 ///
 /// @file    test.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-28 09:14:27
 ///
 
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> tmp;
	cout<<tmp.size()<<"  "<<tmp.capacity()<<endl;
	tmp.push_back(1);
	cout<<tmp.size()<<"  "<<tmp.capacity()<<endl;
	tmp.push_back(1);
	cout<<tmp.size()<<"  "<<tmp.capacity()<<endl;
	tmp.push_back(1);
	cout<<tmp.size()<<"  "<<tmp.capacity()<<endl;
	int* arr = new int[2];
	arr[0]=1,arr[1]=2;
	int* elem = &arr[0];
	cout<<*elem<<endl;
	cout<<elem<<endl;
	cout<<elem+1<<endl;
	return 0;
}

