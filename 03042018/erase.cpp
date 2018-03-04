 ///
 /// @file    erase.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-04 11:24:06
 ///
 

#include<iostream>
#include<map>
using namespace std;
template<class container>
void disp(container& m)
{
	for(auto& elem:m)
		cout<<elem.first<<","<<elem.second<<endl;
}
int main()
{
	pair<int,string> sz[3] = 
	{
		pair<int,string>(1,"A"),
		pair<int,string>(2,"B"),
		pair<int,string>(1,"C")
	};
	map<int,string> map1(sz,sz+3);
	cout<<"map1 before erase:"<<endl;
	disp(map1);
	int cnt =  map1.erase(1);
	cout<<"map1 after erase:"<<endl;
	disp(map1);
	cout<<"erase "<<cnt<<" elems"<<endl;
	multimap<int,string> mmap1(sz,sz+3);
	cout<<"mmap1 before erase:"<<endl;
	disp(mmap1);
	cnt = mmap1.erase(1);
	cout<<"mmap1 after erase:"<<endl;
	disp(mmap1);
	cout<<"erase "<<cnt<<" elems"<<endl;
	return 0;
}
//map1 before erase:
//1,A
//2,B
//map1 after erase:
//2,B
//erase 1 elems
//mmap1 before erase:
//1,A
//1,C
//2,B
//mmap1 after erase:
//2,B
//erase 2 elems
