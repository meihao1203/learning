 ///
 /// @file    type.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-04 14:25:00
 ///
 

#include<iostream>
#include<map>
using namespace std;
template<class container>
void print_container(container& v)
{
	for(auto& elem:v)
		cout<<elem.first<<","<<elem.second<<endl;
}
int main()
{
	//STL为所有容器定义了类型
	//这里的value_type就相当于pair<int,string>
	map<int,string>::value_type arr[4] = 
	{
		map<int,string>::value_type(1,"kunming"),
		map<int,string>::value_type(3,"nanning"),
		map<int,string>::value_type(2,"guiyang"),
		map<int,string>::value_type(3,"haikou")
	};
	map<int,string> map1(arr,arr+4);
	print_container(map1);
	map<int,string>::size_type size = map1.size();
	cout<<"map1.size="<<size<<endl;
	map<int,string>::key_type cnt = map1.erase(3);
	cout<<"map1 after erase key 3"<<endl;
	print_container(map1);
	cout<<"erase count="<<cnt<<endl;
	cout<<"----华丽的分割线----"<<endl;
	multimap<int,string> mmap1(arr,arr+4);
	print_container(mmap1);
	multimap<int,string>::size_type msize = mmap1.size();
	cout<<"mmap1.size="<<msize<<endl;
	multimap<int,string>::key_type mcnt = mmap1.erase(3);
	cout<<"mmap1 after erase key 3"<<endl;
	print_container(mmap1);
	cout<<"erase count="<<mcnt<<endl;
	return 0;
}
//1,kunming
//2,guiyang
//3,nanning
//map1.size=3
//map1 after erase key 3
//1,kunming
//2,guiyang
//erase count=1
//----华丽的分割线----
//1,kunming
//2,guiyang
//3,nanning
//3,haikou
//mmap1.size=4
//mmap1 after erase key 3
//1,kunming
//2,guiyang
//erase count=2
