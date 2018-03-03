 ///
 /// @file    map.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-03 21:22:04
 ///
 
//模板类pair<class T1,class T2>
#include<iostream>
#include<map>
using namespace std;
int main()
{
	pair<const string,string> p1("hello","world");
	cout<<p1.first<<" "<<p1.second<<endl;
	map<string,string> map1;
	map1["11"] = "aa";  // key--value
	map1["22"] = "bb";
	map1["33"] = "cc";
	map1["33"] = "dd";
	for(auto& elem:map1)
		cout<<elem.first<<"--"<<elem.second<<endl;
}
//hello world
//11--aa
//22--bb
//33--dd
