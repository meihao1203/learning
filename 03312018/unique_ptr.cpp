 ///
 /// @file    unique_ptr.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-31 09:51:59
 ///
 
#include<iostream>
#include<vector>
#include<memory>
using namespace std;
unique_ptr<int> getValue()
{
	unique_ptr<int> tmp(new int(666));
	return tmp;
}
int main()
{
	//unique_ptr无法进行复制或赋值,表达的是对象语义
	unique_ptr<int> up1(new int(1));
	//unique_ptr<int> up2(up1);  // error,无法调用拷贝构造函数复制
	//unique_ptr<int> up3 = up1;  // error,无法调用赋值构造函数复制
	cout<<"addr up1="<<up1.get()<<"  *up1="<<*up1<<endl;

	unique_ptr<int> up2 = getValue();  // 调用的是移动构造函数
	cout<<"addr up2="<<up2.get()<<"  *up2="<<*up2<<endl;
	unique_ptr<int> up3 = move(up2);
	//cout<<"addr up2="<<up2.get()<<"  *up2="<<*up2<<endl;  // core dump,up2已经被转移成移动语义了。
	cout<<"addr up3="<<up3.get()<<"  *up3="<<*up3<<endl;

	unique_ptr<int> up4(new int(2));
	cout<<"addr up4="<<up4.get()<<"  *up4="<<*up4<<endl;
	vector<unique_ptr<int>> v;
	v.push_back(move(up4));  // 这里必须是移动语义，不然报错
	cout<<"addr up4="<<up4.get()<<"  *up4="<<*up4<<endl;

	return 0;
}
//addr up1=0x22ebc20  *up1=1
//addr up2=0x22ec050  *up2=666
//addr up3=0x22ec050  *up3=666
//addr up4=0x22ec070  *up4=2
//Segmentation fault (core dumped)
