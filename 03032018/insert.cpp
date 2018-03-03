///
/// @file    insert.cpp
/// @author  meihao1203(meihao19931203@outlook.com)
/// @date    2018-03-03 17:56:21
///

#include<iostream>
#include<vector>
using namespace std;
template<class container>
void display(container& v)
{
	class container::iterator it = v.begin();  // 这里的区别,必须加一个class
	for(;it!=v.end();++it)
	{
		cout<<*it<<"  ";
	}
	cout<<endl;
	//	for(auto& elem:v)
	//	{
	//		cout<<elem<<"  ";
	//	}
	//	cout<<endl;
}
int main()
{
	int arr[3] = {1,2,3};
	vector<int> ve(arr,arr+3);
	display(ve);
	vector<int>::iterator it;
	ve.insert(it=ve.end(),5);  // 在it的前面插入5
	display(ve);
	ve.insert(it=ve.begin(),3,6);  // 在it前插入3个6
	display(ve);
	int tmp[] = {7,8,9};
	ve.insert(it=ve.end(),tmp,tmp+3);  // 插入tmp到tmp+3之间的数据,[)
	display(ve);
	ve.erase(it=ve.end()-1);  // 删除it指向的元素
	display(ve);
	vector<int>::iterator first = ve.begin();
	vector<int>::iterator last = first+3;
	ve.erase(first,last);
	display(ve);
	cout<<"-------------------"<<endl;
	cout<<ve.capacity()<<"  "<<ve.size()<<endl;
	ve.clear();
	cout<<ve.capacity()<<"  "<<ve.size()<<endl;
	display(ve);
	return 0;
}
//1  2  3  
//1  2  3  5  
//6  6  6  1  2  3  5  
//6  6  6  1  2  3  5  7  8  9  
//6  6  6  1  2  3  5  7  8  
//1  2  3  5  7  8  
//-------------------
//14  6
//14  0
//
