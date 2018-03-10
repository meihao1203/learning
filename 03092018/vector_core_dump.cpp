 ///
 /// @file    vector_core_dump.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-09 11:20:54
 ///
 
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<string> ve;
	ve.push_back("mei");
//	ve.push_back("hao");
//	ve.push_back("hello");
	vector<string>::iterator it = ve.begin();
	int i = 0;
	//迭代器失效
	for(;it!=ve.end();++it)
	{
		cout<<"ve's vapacity:"<<ve.capacity();
		cout<<"  ve's size:"<<ve.size();
		cout<<"  elem is:"<<*it<<endl;
		if(0==i)
		{
			ve.push_back("world");  // 这里的push_如果导致容器扩容，it指针将会失效
			//coredump
			cout<<"push value!"<<endl;
			i++;
		}
	}
	return 0;
}
//这里的扩容不是在原有空间的基础上容量增加，而是从新申请一个更大的空间，
//然后把旧空间的内容拷贝到新申请的空间，释放原来的空间，
//所以迭代器遍历的时候扩容，迭代器++就找不到我们要找的内容，直接段错误

//ve's vapacity:4  ve's size:3  elem is:mei
//push value!
//ve's vapacity:4  ve's size:4  elem is:hao
//ve's vapacity:4  ve's size:4  elem is:hello
//ve's vapacity:4  ve's size:4  elem is:world

//ve's vapacity:1  ve's size:1  elem is:mei
//push value!
//Segmentation fault (core dumped)
