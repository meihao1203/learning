 ///
 /// @file    resize.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-03 18:28:50
 ///
 
#include<iostream>
#include<vector>
using namespace std;
template<class container>
void print(container& v)
{
	cout<<"capacity="<<v.capacity()<<"  size="<<v.size()<<endl;
}
int main()
{
	vector<int> ve = {1,2,3};  // C++11新特性
	print(ve);
	ve.resize(10);  // 更改空间大小10，没有数值的空间赋0
	print(ve);
	for(auto& elem:ve)
		cout<<elem<<"  ";
	cout<<endl;
	ve.resize(100);
	print(ve);
	ve.clear();
	print(ve);
	ve.push_back(4);
	ve.push_back(5);
	ve.push_back(6);
	print(ve);
	ve.resize(2); 
	print(ve);
	for(auto& elem:ve)
		 cout<<elem<<"  ";
	cout<<endl;
	//vector<int>(ve).swap(ve);  // 用ve里面的有效数值初始化一个临时vector,swap交换指针,这时候ve的指针就交换了指向临时变量的空间，达到了删除没有存放数值的空间
	//删除没有存放数据的单元，释放空间
	//表示创建一个临时的vector<int>(vec) 这个临时的vec会去拷贝vec中的元素，然后再交换，这样vec的大小就变成3了，执行完后释放临时的vec
	ve.shrink_to_fit();  // 等价上面
	print(ve);
	cout<<"-------------"<<endl;
	vector<int> ve2;
	print(ve2);
	ve2.reserve(10);  // 开辟空间，区别resize更改空间大小
	print(ve2);
	ve2.push_back(1);
	print(ve2);
	return 0;
}
//capacity=3  size=3
//capacity=10  size=10
//1  2  3  0  0  0  0  0  0  0  
//capacity=100  size=100
//capacity=100  size=0
//capacity=100  size=3
//capacity=100  size=2
//4  5  
//capacity=2  size=2
//-------------
//capacity=0  size=0
//capacity=10  size=0
//capacity=10  size=1
