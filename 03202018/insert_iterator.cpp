 ///
 /// @file    insert_iterator.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-20 15:40:06
 ///
 
#include<iostream>
#include<iterator>
#include<vector>
#include<list>
using namespace std;
template<class container>
void print(container c)
{
	class container::const_iterator it;
	for(it=c.begin();it!=c.end();++it)
		cout<<*it<<"  ";
	cout<<endl;
}
int main()
{
	vector<int> verSrc = {1,2,3};
	list<int> listDest;
	copy(verSrc.begin(),verSrc.end(),back_insert_iterator<list<int> >(listDest));
//尾插法，把verSrc中的内容插入到listDest
	print(listDest);
	list<int> listDest1;
	copy(verSrc.begin(),verSrc.end(),front_insert_iterator<list<int> >(listDest1));
//头插法，把verSrc中的内容插入到listDest1
	print(listDest1);
	copy(verSrc.begin(),verSrc.end(),insert_iterator<list<int> >(listDest1,++listDest1.begin()));
//指定位置插入
   print(listDest1);
   return 0;
}
//1  2  3  
//3  2  1  
//3  1  2  3  2  1  
