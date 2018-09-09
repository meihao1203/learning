#pragma pack(4)
#include<iostream>
using namespace std;
struct node
{
	int num;
	char name[7];
	short age;
	char sex;
};
int main()
{
	node s;
	cout<<sizeof(s)<<endl;
	system("pause");
}