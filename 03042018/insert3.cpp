 ///
 /// @file    insert3.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-04 10:48:01
 ///
 
#include<iostream>
#include<map>
using namespace std;
int main()
{
	pair<int,string> sz[4]={
		pair<int,string>(7,"honghe"),
		pair<int,string>(3,"wenshan"),					
		pair<int,string>(5,"baoshan"),
		pair<int,string>(1,"lijiang")
	};
	pair<int,string> insarr[3] = 
	{
		pair<int,string>(8,"kunming"),
		pair<int,string>(6,"qujing"),
		pair<int,string>(5,"dali")
	};
	map<int,string> map1(sz,sz+4);
	map1.insert(insarr,insarr+3);
	for(auto& elem:map1)
		cout<<elem.first<<","<<elem.second<<endl;
	multimap<int,string> mmap1(sz,sz+4);
	mmap1.insert(insarr,insarr+3);
	cout<<"----------------------"<<endl;
	for(auto& elem:mmap1)
		cout<<elem.first<<","<<elem.second<<endl;
	cout<<endl;
	return 0;
}
//1,lijiang
//3,wenshan
//5,baoshan
//6,qujing
//7,honghe
//8,kunming
//----------------------
//1,lijiang
//3,wenshan
//5,baoshan
//5,dali
//6,qujing
//7,honghe
//8,kunming
//
