 ///
 /// @file    istream_iterator.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-07-19 15:45:39
 ///
 
#include<iostream>
#include<iterator>
#include<vector>
using namespace std;
int main()
{
	istream_iterator<int,char> isi(cin);
	vector<int> ve;
	copy(isi,istream_iterator<int>(),back_inserter(ve));
	for(auto& elem: ve)
		cout<<elem<<" ";
	cout<<endl;
}
//12345a
//12345 
