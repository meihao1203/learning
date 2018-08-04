//题目43(非递归解法，时间复杂度低)：
//思路：用两个数组来存储骰子点数的每一个总数出现的次数，有一个骰子的时候，
//第一个数组的值就是{0,1,1,1,1,1,1}后面的都是0；对应和0,1,2,3,4,5,6可能出现的次数，因为只有一个骰子，只能1次；和与数组下标对应
//这时候加一个数组，第二个数组对应的和就为前一个数组对应的和为n-1,n-2,n-3,n-4,n-5,n-6的能出现的次数的和，
//因为在这几种情况下都能通过另外一个骰子出现对应的数字达到和为n。
//第二个数组可能出现的和2,3,4,5,6,7,8,9,10,11,12；数组就是(前面两个0,0){1,2,3,4,5,6,5,4,3,2,1};
//和为7就等于上一个数组下标为6+5+4+3+2+1 = 1+1+1+1+1+1 = 6
#if 1
#include<iostream>
using namespace std;
#define maxDiceNum 6  //提高代码的扩展性，以后骰子的点数变为7或其他啊位数，就只要少量修改
void printProbabilityOfDice(int cnt);
void test(int cnt);
int main()
{
	test(1);
	cout<<endl;

	test(2);
	cout<<endl;

	test(3);
	cout<<endl;
	system("pause");
}
void test(int cnt)
{
	printProbabilityOfDice(cnt);
}
void printProbabilityOfDice(int cnt)
{
	if(cnt<=0)
		return;
	int* arr[2];
	arr[0] = new int[cnt*maxDiceNum+1];
	arr[1] = new int[cnt*maxDiceNum+1];
	//对数组初始化
	memset(arr[0],0,(cnt*maxDiceNum+1)*sizeof(int));
	memset(arr[1],0,(cnt*maxDiceNum+1)*sizeof(int));

	int arrNum = 0;  //两个数组，最开始从第一个开始，交替赋值
	//针对一个骰子情况，对第一个数组赋值
	for(int idx=1;idx<=maxDiceNum;++idx)
		arr[arrNum][idx] = 1;
	//开始交替计算和出现的次数
	for(int idx=2;idx<=cnt;++idx)
	{
		arrNum = (idx&1)^1;
		for(int iidx=0;iidx<idx;++iidx)
		{
			arr[arrNum][iidx] = 0;
		}
		for(int iiidx=idx;iiidx<=idx*maxDiceNum;++iiidx)
		{//当前骰子个数可能出现的和
			arr[arrNum][iiidx] = 0;  //上一次遍历存放的值重新赋0，因为要再次更新，前面保存的值作废
			for(int iiiidx=1; iiiidx<=maxDiceNum && iiiidx<iiidx ; ++iiiidx)  //iiiidx<iiidx确保n-(i~6)的值大于0
			{//iiiidx为当前骰子出现的数字，不可能出现0,当前骰子出现的数字和，要算出现的总的次数，就要加上上次出现iiidx-iiiidx的次数了
				arr[arrNum][iiidx] += arr[(arrNum+1)%2][iiidx-iiiidx];
			}
		}
	}
		//开始计算概率
		int totoalSumCnt = pow(maxDiceNum,cnt);
		for(int idx=cnt;idx<=cnt*maxDiceNum;++idx)
		{
			cout<<"sum is "<<idx<<" appear "<<arr[arrNum][idx]<<
				" times and probability is "<<(double)arr[arrNum][idx]/totoalSumCnt<<endl;
		}
		delete []arr[0];
		delete []arr[1];
}
#endif
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