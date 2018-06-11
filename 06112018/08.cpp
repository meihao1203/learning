//题目43：n个骰子的点数。把n个骰子仍在地上，所有骰子朝上一面的点数之和为s。
//输入n，打印出s的所有可能的值出现的概率。
//思路：递归；先把n个骰子分为两堆：第一堆只有一个，另外一个有n-1个。单独的那一个有可能出现1-6的点数。
//依次，后面的n-1个也可以分成两堆。把单独的那一个的数值和最开始那一个相加。。。依次递归，出口就是最后划分的那一堆骰子为0
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
void probability(int* proArr,int cnt,int remainCnt,int sum);   
//第一个参数是数组，用来存放每个数出现的概率，第二个数是骰子数，第三个是第二堆的骰子数，最后一个是前面一堆骰子的点数和
void printProbability(int cnt);
void test(int cnt);
int main()
{
	test(1);
	cout<<endl;

	test(2);
	cout<<endl;

	test(3);
	cout<<endl;
}
void test(int cnt)
{
	printProbability(cnt);
}
void printProbability(int cnt)
{
	if(cnt<=0)
		return ;
	int* proArr = new int[cnt*6];  //定义数组存放每种可能出现的点数和
	memset(proArr,0,sizeof(int)*cnt*6);
	for(int idx=1;idx<=6;++idx)
	{
		probability(proArr,cnt,cnt-1,idx);   //第一个骰子可能出现1~6的点数
		//当第一个骰子出现的数是idx的时候，递归求后面cnt-1个骰子可能出现的点数和
	}
	int maxSum = cnt * 6;
	int permutation = pow(6,cnt);  //所有点数的全排列，计算每个数出现的概率要用到
	for(int idx=cnt;idx<=maxSum;++idx)
	{
		cout<<"sum is "<<idx<<" appear "<<(double)proArr[idx - cnt]<<
			" times and probability is "<<((double)proArr[idx - cnt]/permutation)<<endl;
		//最小可能出现的和就是点数,假设2个骰子，最小和就是2，2-cnt=0,对应数组的第一个位置
	}
	delete []proArr;
}
void probability(int* proArr,int cnt,int remainCnt,int sum)
{
	if(NULL==proArr||cnt<=0)
		return ;
	else if(0==remainCnt)
	{
		++proArr[sum - cnt];
		return ;
	}
	//递归求剩下的骰子可能出现的和
	for(int idx=1;idx<=6;++idx)
	{
		probability(proArr,cnt,remainCnt-1,sum+idx);
	}
}
//sum is 1 appear 1 times and probability is 0.166667
//sum is 2 appear 1 times and probability is 0.166667
//sum is 3 appear 1 times and probability is 0.166667
//sum is 4 appear 1 times and probability is 0.166667
//sum is 5 appear 1 times and probability is 0.166667
//sum is 6 appear 1 times and probability is 0.166667
//
//sum is 2 appear 1 times and probability is 0.0277778
//sum is 3 appear 2 times and probability is 0.0555556
//sum is 4 appear 3 times and probability is 0.0833333
//sum is 5 appear 4 times and probability is 0.111111
//sum is 6 appear 5 times and probability is 0.138889
//sum is 7 appear 6 times and probability is 0.166667
//sum is 8 appear 5 times and probability is 0.138889
//sum is 9 appear 4 times and probability is 0.111111
//sum is 10 appear 3 times and probability is 0.0833333
//sum is 11 appear 2 times and probability is 0.0555556
//sum is 12 appear 1 times and probability is 0.0277778
//
//sum is 3 appear 1 times and probability is 0.00462963
//sum is 4 appear 3 times and probability is 0.0138889
//sum is 5 appear 6 times and probability is 0.0277778
//sum is 6 appear 10 times and probability is 0.0462963
//sum is 7 appear 15 times and probability is 0.0694444
//sum is 8 appear 21 times and probability is 0.0972222
//sum is 9 appear 25 times and probability is 0.115741
//sum is 10 appear 27 times and probability is 0.125
//sum is 11 appear 27 times and probability is 0.125
//sum is 12 appear 25 times and probability is 0.115741
//sum is 13 appear 21 times and probability is 0.0972222
//sum is 14 appear 15 times and probability is 0.0694444
//sum is 15 appear 10 times and probability is 0.0462963
//sum is 16 appear 6 times and probability is 0.0277778
//sum is 17 appear 3 times and probability is 0.0138889
//sum is 18 appear 1 times and probability is 0.00462963
