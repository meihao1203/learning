//µÚÆßÕÂ£¬ÃæÊÔ°¸Àı1
#include<iostream>
using namespace std;
class A
{
public:
	A():n2(0),n1(n2+2){};
	void Print()
	{
		cout<<"n1: "<<n1<<",n2: "<<n2<<endl;
	}
private:
	int n1;
	int n2;
};
int main(int argc,char** argv)
{
	A a;
	a.Print();
	system("pause");
}
//n1: -858993458,n2: 0
