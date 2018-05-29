 ///
 /// @file    sizeof.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-29 11:10:40
 ///
 
#include<iostream>
using namespace std;
int getSize(int data[])
{
	return sizeof(data);
}
int main()
{
	int data1[] = {1,2,3,4,5};
	int size1 = sizeof(data1);
	int* data2 = data1;
	int size2 = sizeof(data2);
	int size3 = getSize(data1);
	cout<<size1<<" "<<size2<<" "<<size3<<endl;
}
//20 8 8
