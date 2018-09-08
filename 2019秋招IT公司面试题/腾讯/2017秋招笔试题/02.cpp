//游戏里面有很多各式各样的任务，其中有一种任务玩家只能做一次，这类任务一共有1024个，任务ID范围[1,1024]。请用32个unsigned int类型来记录这
//1024个任务是否已经完成。初始状态都是未完成。 输入两个参数，都是任务ID，需要设置第一个ID的任务为已经完成；并检查第二个ID的任务是否已经完成。
//输出一个参数，如果第二个ID的任务已经完成输出1，如果未完成输出0。如果第一或第二个ID不在[1,1024]范围，则输出-1。
//输入描述:
//
//输入包括一行,两个整数表示人物ID.
//
//输出描述:
//
//输出是否完成
//
//输入例子1:
//
//1024 1024
//
//输出例子1:
//
//1
#if 0
#include<iostream>
using namespace std;
unsigned int isCompleted(unsigned int a,unsigned int b);
static int flag = 0;
int main(int argc,char** argv)
{
	int num1,num2;
	cin>>num1>>num2;
	int res = isCompleted(num1,num2);
	if(flag == -1)
		cout<<flag;
	else cout<<res;
	//system("pause");
}
unsigned int isCompleted(unsigned int a,unsigned int b)
{
	if(a<1||a>1024||b<1||b>1024)
	{
		flag = -1;
		return 0;
	}
	unsigned int arr[32] = {};
	// a-1 0~1023
	arr[(a-1)/32] = 1<<((a-1)%32);
	if( arr[(b-1)/32] == 1<<(b-1)%32 )
		return 1;
	else
		return 0;
}
#endif


//#include <iostream>
//#include <algorithm>
//int main() 
//{
//    using namespace std;
//    unsigned int n, m;
//    while (cin >> n >> m) 
//    {
//        if (n < 1 || n > 1024 || m < 1 || m > 1024) 
//            cout << -1 << endl;
//        else 
//        {
//            if (n == m) 
//                cout << 1 << endl;
//            else
//                cout << 0 << endl;
//        }
//    }
//    return 0;
//}