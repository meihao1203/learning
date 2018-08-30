//模拟一个小范围的败者树多路归并
//假设数据源来自5个数组，且这些数组都要是有序的（降序的）
#include<iostream>
#include<vector>
#include<limits>
#include<string.h>
using namespace std;
static const int DataSourceNumber = 5;  //数据源有五个数组
//定义数据源，一共5个，假设每个数组有两个元素
int arr[DataSourceNumber][2] = {
	{10,9},{9,8},{11,7},{8,6},{8,7}
};
//定义非叶子结点数组，非叶子结点的值表示该结点记录的是哪一个数组来源的值
int treeNode[DataSourceNumber];

//定义叶子结点数组，对应的数组小标表示是那个数据源，值表示数据源中的数据
int node[DataSourceNumber];

//定义数据源的偏移指向数据，因为每次从数据源中读取了一个数据，对应的索引就要偏移到下一位
int Iterator[DataSourceNumber] = {0};  //初始化全为0，因为每个数源都是要从第0个数据开始取

//定义获取叶子结点的值的函数
int get(int index)
{
	return node[index];
}

//定义设置叶子结点的值的函数
void set(int index)
{
	if(Iterator[index] == 2)
	{
		node[index] = numeric_limits<int>::min();
		return ;
	}
	node[index] = arr[index][Iterator[index]] ; //结点node[index]的值就是index个数据源的第Iterator[index]个值，
	//之后要设置Iterator[index]偏移到下一个,这样下次才能取出下一个值设置对应的node结点
	Iterator[index] += 1;
}
void adjust(int index)  //败者树从node结点index开始向上调整
{
	//找到index对应的父结点
	int father = (index + DataSourceNumber)>>1;
	while(father>0)  
	{
		if( get(treeNode[father])>get(index) )  //和父结点比较，败者的索引更新父结点
		{
			int tmp = treeNode[father];
			treeNode[father] = index;
			index = tmp;  //向上继续比较，更新index
		}
		father /= 2;
	}
	treeNode[0] = index;  //最终胜者
}
//设置摆着树的初始化工作
void init()
{//败者树要找出最小的指定个数的数，先用数据源数组中首个元素最大的数据源索引来初始化非叶子结点
	//然后开始调整
	memset(Iterator,0,sizeof(Iterator));   //
	//1、设置node
	for(int idx=0;idx!=DataSourceNumber;++idx)
	{
		set(idx);
	}
	int MAX = 0;  //初始最大元素来自数组源0
	for(int idx=0;idx!=DataSourceNumber;++idx)
	{
		if(node[idx]>node[MAX])
			MAX = idx;
	}
	//2、初始化treeNode
	for(int idx=0;idx!=DataSourceNumber;++idx)
	{
		treeNode[idx] = MAX;
	}
	//3、开始从最后一个非叶子结点调整
	for(int idx=DataSourceNumber-1;idx>=0;--idx)
	{
		adjust(idx);
	}
}
vector<int> merge(int cnt)  //要输出cnt多少个值
{
	vector<int> ans;
	while(cnt)
	{
		ans.push_back(node[treeNode[0]]);  //败者树的0号节点存放的就是当前最小的node值索引
		set(treeNode[0]);  //输出一个，要更新对应的叶子结点的值
		adjust(treeNode[0]);  //调整
		--cnt;
	}
	return ans;
}
int main()
{
	init();
	vector<int> ret = merge(5);
	for(auto elem:ret)
		cout<<elem<<" ";
	cout<<endl;


	init();
	vector<int> ret2 = merge(10);
	for(auto elem:ret2)
		cout<<elem<<" ";
	cout<<endl;
	//system("pause");
}
//11 10 9 9 8 
//11 10 9 9 8 8 8 7 7 6 
