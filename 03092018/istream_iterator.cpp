 ///
 /// @file    istream_iterator.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-09 09:26:23
 ///
 
#include<iostream>
#include<iterator>
#include<vector>
using namespace std;
int main()
{
	vector<int> ve;
	istream_iterator<int> isi(cin);
	copy(isi,istream_iterator<int,char>(),back_inserter(ve));  // 将输入流插入到ve中,以一个非整形变量来结束输入
	for(auto& elem:ve)
		cout<<elem<<"  ";
	cout<<endl;
	return 0;
}
//1 2 3 4 5 6 a
//1  2  3  4  5  6 
