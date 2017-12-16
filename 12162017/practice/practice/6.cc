#include<iostream>
#include<stdlib.h>
using namespace std;			
#pragma pack(2)
class BU
{
	int number;   //4
	union UBffer   //13  min(2,13)  4+13=17
	{
		char buffer[13];
		int number;
	}ubuf;

	void foo(){}

	typedef char *(*f)(void*);

	enum{hdd, ssd, blueray} disk;  //4 min(2,4)  18+4=22
}bu;
int main()
{
	cout<<sizeof(bu)<<endl;  //22
	system("pause");
	return 0;
}