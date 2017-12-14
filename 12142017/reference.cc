 ///
 /// @file    reference.cc
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-14 09:14:20
 ///
 
#include<iostream>
using namespace std;
int arr[5] = {0,1,2,3,4};
int& func()  //引用作为函数返回值
{
	return arr[0];
}
int* func1()
{
	int x = 4;
	return &x;   //警告，局部变量的地址被返回
}
int& func2()
{
	int x = 5;
	return x;  //警告，局部变量的引用被返回
}
//不要返回堆空间对象的引用
int& func3()
{
	int *px = new int(10);
	return *px;
}
int main(void)
{
	int a = 3;
	func() = 10;
	cout<<"arr[0]="<<arr[0]<<endl;   //arr[0]=10

	cout<<"func1()="<<func1()<<endl; //func1()=0
	//cout<<"*func1()="<<*(func1())<<endl;  //段错误
	//cout<<"func2()="<<func2()<<endl;        //段错误,内存被释放

	cout<<"func3()="<<func3()<<endl; //10
	delete(&(func3()));   //释放开辟的堆栈空间

	cout<<"1+func3()="<<1+func3()<<endl;   //已经释放了又来操作，内存泄露(memory leak)
	//11
	return 0;
}
