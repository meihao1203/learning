 ///
 /// @file    ostream_iterator.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-07-19 15:38:40
 ///
 
#include<iostream>
#include<vector>
#include<iterator>
using namespace std;
int main()
{
	int arr[] = {1,2,3,4,5};
	vector<int> ve(arr,arr+5);
	ostream_iterator<int,char> osi(cout," ");
	copy(ve.begin(),ve.end(),osi);
	cout<<endl;
}
//1 2 3 4 5
