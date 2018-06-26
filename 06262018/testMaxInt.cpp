#include<iostream>
using namespace std;
int main()
{
	unsigned int x = 0xFFFFFFFF;
	cout<<x<<endl;
	int x2 = 0x7FFFFFFF;
	cout<<x2<<endl;
	int x3 = 0xFFFFFFFF;
	cout<<x3<<endl;

	short int a = 0xFF;
	cout<<a<<endl;
	unsigned short int b = 0x7F;
	cout<<b<<endl;
	signed short int c = 0x80;
	cout<<c<<endl;
	signed short int d = 0xFF;
	cout<<d<<endl;
}
//4294967295
//2147483647
//-1
//255
//127
//128
//255
