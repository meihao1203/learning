 ///
 /// @file    test.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-14 20:33:45
 ///
 
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> ob;
	ob.push_back(1);
	ob.push_back(2);
	for(auto& elem:ob)
		cout<<elem<<endl;
}
