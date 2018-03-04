///
/// @file    class_type.cpp
/// @author  meihao1203(meihao19931203@outlook.com)
/// @date    2018-03-04 16:10:07
///


#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
class myString
{
	public:
		myString();
		myString(const myString&);
		myString(const char*);
		//后面用到sort排序算法,sort排序要对元素进行交换,防止浅拷贝重复释放,所以这里重写
		//没有这个就会报重复释放内粗的错误
		myString& operator=(const myString&);
		~myString();
	private:
		char* _pString;
		friend ostream& operator<<(ostream&,const myString&);
	//	friend bool operator>(const myString&,const myString&);
		friend bool operator<(const myString&,const myString&);
		friend bool operator==(const myString&,const myString&);
};
myString::myString()
{
	_pString = new char[1];
	_pString[0] = '\0';
}
myString::myString(const myString& rhs)
{
	_pString = new char[strlen(rhs._pString)+1];
	strcpy(_pString,rhs._pString);
}
myString::myString(const char* str)
{
	_pString = new char[strlen(str)+1];
	strcpy(_pString,str);
}
myString& myString::operator=(const myString& rhs)
{
	if(this!=&rhs)
	{
		delete _pString;
		_pString = new char[strlen(rhs._pString)+1];
		strcpy(_pString,rhs._pString);
	}
	return (*this);
}
myString::~myString()
{
	delete []_pString;
	_pString = NULL;
}

ostream& operator<<(ostream& os,const myString& rhs)
{
	os<<rhs._pString;
}
//bool operator>(const myString& lhs,const myString& rhs)
//{
//	return strcmp(lhs._pString,rhs._pString)>0;
//}
bool operator<(const myString& lhs,const myString& rhs)
{
	return strcmp(lhs._pString,rhs._pString)<0;
}
bool operator==(const myString& lhs,const myString& rhs)
{
	return strcmp(lhs._pString,rhs._pString)==0;
}
void  printObject(myString& rhs)
{
	cout<<rhs<<"  ";
}
int main()
{
	//1. vector和deque支持随机访问, 将本函数中的vector类型替换成deque类型后，结果一样
	//测试自定义数据类型CMyString做为vector元素的用法
	vector<myString> obv;
	obv.push_back("A");
	obv.push_back("B");
	obv.push_back("C");
	obv.push_back(myString("A"));
	obv.push_back(myString("B"));
	obv.push_back(myString("C"));
	//调用 for_each()泛型算法来遍历vector容器的每个元素
	for_each(obv.begin(),obv.end(),printObject);
	cout<<endl;
	cout<<"vector sort:"<<endl;
	//调用泛型算法对vector容器元素进行排序
	//vector容器本身并没有提供sort排序算法
	//sort排序，就要对自定义类类型重载比较运算符
	sort(obv.begin(),obv.end());
	//sort只要重载<就可以了
	for_each(obv.begin(),obv.end(),printObject);
	cout<<endl;

	//find查找元素,返回一个迭代器,如果没找到,会返回obv.end()
	//find要用到==运算符,所以要在myString类里面重载==运算符
	cout<<"删除第一个B元素"<<endl;
	vector<myString>::iterator it = find(obv.begin(),obv.end(),myString("B"));
	if(it!=obv.end())
	{
		obv.erase(it);
	}
	for_each(obv.begin(),obv.end(),printObject);
	cout<<endl;
	
	cout<<"删除第一个C之后的所有元素"<<endl;
	vector<myString>::iterator it1 = find(obv.begin(),obv.end(),myString("C"));
	if(it!=obv.end())
	{
		obv.erase(it1,obv.end());
	}
	for_each(obv.begin(),obv.end(),printObject);
	cout<<endl;
	return 0;
}
//A  B  C  A  B  C  
//vector sort:
//A  A  B  B  C  C  
//删除第一个B元素
//A  A  B  C  C  
//删除第一个C之后的所有元素
//A  A  B  
