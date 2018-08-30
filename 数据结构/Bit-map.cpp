//利用Bit-map，要求能够表示的最大值为10,000,000
//思路，一个整形能表示32位，10000000/32得到要多少个整形
//由于不可能刚好能被32整除，所以要多加一个整形来表示10000000
#if 0
#include<iostream>
using namespace std;
#define BITWORD 32
#define SHIFT 5  //一个数左移5位就相当于除以32
#define MASK 0x1F  //掩码，确定一个数要表示在一个32位的哪一位上，左移0~31
#define N 10000000
int a[1+N/BITWORD];   //申请一个最小的能表示10000000的数组
void set(int count)  //设置表示数count的对应位为1，count>=0
{
	a[count>>SHIFT] |= ( 1<<( count & MASK ) );  
	//count>>SHIFT得到count要存放在数组中哪一个int中，count&MASK
	//得到在该int中，哪一位要置1。MASK = 0x1F。
	//最后|=加上要置为1的位
}
void clr(int count)  //将表示count的位置0
{
	a[count>>SHIFT] &= ~( 1<<( count & MASK ) );
}
bool test(int count)  //返回表示count的对应位的状态
{
	return !!(a[count>>SHIFT] & ( 1<<( count & MASK ) ));
}

int main()
{
	set(10);
	set(20);
	cout<<test(10)<<" "<<test(20)<<" "<<test(30)<<endl;
	clr(10);
	clr(11);
	cout<<test(10)<<" "<<test(20)<<" "<<test(30)<<endl;
	cout<<test(11)<<endl;
	system("pause");
}
#endif
//1 1 0
//0 1 0
//0
//请按任意键继续. . .