#include<iostream>
#include<stdlib.h>
using namespace std;
int main4(void)
{
	int *p = NULL;
	int a[] = {1,2,3,4};

	p = a;
	*p = a[0];
	p = &a[0];
	//p = &a;   //&a 是数组指针 int[4]*
    int (*p1)[4];
	p1 = &a;
	cout<<a<<"  "<<&a<<endl;  //00AFF950  00AFF950,
	cout<<(*p1)[1]<<endl;   //2
	//cout<<*p1[0]<<endl;   //1
	//cout<<(*p1)[2]<<endl;   //3
	system("pause");
	return 0;
}