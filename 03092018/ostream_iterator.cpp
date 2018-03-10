 ///
 /// @file    ostream_iterator.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-09 09:06:14
 ///
 
#include<iostream>
#include<vector>
#include<iterator>
using namespace std;
int main()
{
	int arr[] = {1,2,3,4,5,6};
	vector<int> ve(arr,arr+6);
	for(auto& elem:ve)
		cout<<elem<<"  ";
	cout<<endl;
	ostream_iterator<int,char> osi(cout," ");  // 创建输出流迭代器osi，将osi理解为容器
	copy(ve.begin(),ve.end(),osi);  // 将ve复制到流中，copy是泛型算法
	cout<<endl;
	return 0;
}
//1  2  3  4  5  6  
//1 2 3 4 5 6 
