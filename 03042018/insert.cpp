 ///
 /// @file    insert.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-04 09:21:01
 ///
 

#include<iostream>
#include<set>
#include<map>
#include<string>
using namespace std;
int main()
{
	pair<int,string> arr[2] = 
	{
		pair<int,string>(1,"A"),
		pair<int,string>(2,"B")
	};
	// 创建待插入元素
	pair<int,string> t1(3,"C");
	map<int,string> map1(arr,arr+2);
	for(auto& elem:map1)
		cout<<elem.first<<","<<elem.second<<endl;
	// map不允许关键字相同，所以有插入成功和不成功的说法
	// 成功bool=1,失败bool=0
	// 插入不管成功与否，map中都会存在要插入的pair，所以返回值会返回这个要插入的pair在map中的位置
	// insert的第一个返回类型是一个对应的迭代器指针map<int,string>::iterator
	pair<map<int,string>::iterator,bool> ret = map1.insert(t1);
	cout<<"insert bool="<<ret.second<<endl;
	cout<<ret.first->first<<","<<ret.first->second<<endl;
	cout<<(*ret.first).first<<","<<(*ret.first).second<<endl;
	cout<<"after map insert"<<endl;
	for(auto& elem:map1)
		cout<<elem.first<<","<<elem.second<<endl;

	// multimap插入
	cout<<"multimap"<<endl;
	multimap<int,string> mmap1(arr,arr+2);
	multimap<int,string>::iterator it = mmap1.begin();
	cout<<it->first<<","<<it->second<<endl;
	// multimap允许关键字相同的pair存在，所以不存在插入失败的说法
	// 永远返回插入元素所在multimap中的位置
	it = mmap1.insert(t1);
	cout<<it->first<<","<<it->second<<endl;
	cout<<"after multimap insert"<<endl;
	for(auto& elem:mmap1)
		cout<<elem.first<<","<<elem.second<<endl;
	return 0;
}
//1,A
//2,B
//insert bool=1
//3,C
//3,C
//after map insert
//1,A
//2,B
//3,C
//multimap
//1,A
//3,C
//after multimap insert
//1,A
//2,B
//3,C
