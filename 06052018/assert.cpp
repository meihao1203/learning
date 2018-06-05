 ///
 /// @file    assert.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-06-05 17:09:08
 ///
 
#include<assert.h>
#include<iostream>
#include<functional>
using namespace std;
int main()
{
	bool flag = true;
	assert(flag);
	cout<<"------"<<endl;
	flag = false;
	assert(flag);
	return 0;
}
//------
//a.out: assert.cpp:16: int main(): Assertion `flag' failed.
//Aborted (core dumped)
