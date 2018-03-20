 ///
 /// @file    reverse_iterator.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-20 15:20:20
 ///
 
#include<iostream>
#include<iterator>
#include<vector>
using namespace std;
int main()
{
	int arr[] = {1,3,5,7,9};
	vector<int> ob(arr,arr+5);
	ostream_iterator<int,char> osi(cout," ");  //创建输出流迭代器
	vector<int>::reverse_iterator rit;  //创建反向迭代器
	copy(rit=ob.rbegin(),ob.rend(),osi);  //重载了输出操作=
	cout<<endl;
	copy(ob.rbegin(),ob.rend(),osi);
	cout<<endl;
	return 0;
}
//9 7 5 3 1 
//9 7 5 3 1 
