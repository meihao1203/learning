 ///
 /// @file    for_each.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-09 10:17:23
 ///
 
//对于for_each而言，如果是vector<int> ob;这样的，此时调用for_each(ob.begin(), ob.end(), func);函数的时候，
//func函数的参数是int(或vector<int>::value_type)
//如果是map<int, string> obM;这样的，此时调用for_each(obM.begin(), obM.end(), func);函数的时候，
//func函数的参数是pair<int, string>这种数据类型的。
//总结：对于for_each的第三个参数而言，写函数的时候，函数的参数就是其中的迭代器指向的类型。
//对于vector<CMyString> 则是CMyString
//对于map<CMyString, string>则是由CMyString和string组成的，所以是pair<CMyString, string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef vector<int>::value_type vvt;
void print(vvt& elem)
{
	cout<<elem<<" ";
}
int main()
{
	int arr[] = {1,2,3,4,5,6};
	vector<int> ve(arr,arr+6);
	for_each(ve.begin(),ve.end(),print);
	cout<<endl;
	return 0;
}
//1 2 3 4 5 6 
