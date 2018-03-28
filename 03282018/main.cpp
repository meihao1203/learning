 ///
 /// @file    main.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-28 09:40:53
 ///
 
#include<iostream>
#include"vector.cpp"
using namespace std;
int main()
{
	vector<int> v1;
	cout<<v1.size()<<"  "<<v1.capacity()<<endl;
	v1.push_back(3);
	cout<<v1.size()<<"  "<<v1.capacity()<<endl;
	v1.push_back(3);
	cout<<v1.size()<<"  "<<v1.capacity()<<endl;
	v1.push_back(3);
	cout<<v1.size()<<"  "<<v1.capacity()<<endl;
	v1.pop_back();
	cout<<v1.size()<<"  "<<v1.capacity()<<endl;
	v1.pop_back();
	cout<<v1.size()<<"  "<<v1.capacity()<<endl;
	//cout<<v1[0]<<endl;
	v1[0] = 2;
	//cout<<v1[0]<<endl;
	return 0;
}
