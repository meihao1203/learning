#if 0
#include<iostream>
#include<vector>
using namespace std;
int maxheapSort(vector<int>&);  //最大堆
void adjust(vector<int>&,int,int);  //堆调整算法
void swap(int&,int&);
void outputMaxHeap(vector<int>&);
int main(int argc,char** argv)
{
	//读入数据
	vector<int> heapData;  //通过输入流读入数组存放在vector中
	int tmp;
	while(cin>>tmp)
	{
		heapData.push_back(tmp);
	}
	//建立最大堆
	maxheapSort(heapData);
	//输出结果
	outputMaxHeap(heapData);
	system("pause");
}
int maxheapSort(vector<int>& arr)
{
	int len = arr.size();  //获取要进行建堆的元素个数
	if(0==len)
		return -1;  //如果没有元素，返回-1，失败。
	for(int idx = len/2-1;idx>=0;--idx)  //从数组中最后一个元素的父结点开始向上调整为最大堆
	{
		adjust(arr,idx,len-1);
	}
}
void adjust(vector<int>& arr,int idx,int len)
{
	if(0==arr.size()||idx>=len||idx<0||len<=0)
		return ;  
	int tmp = arr[idx];  //暂存要调整的数据
	for(int index=idx*2+1;index<=len;index=index*2+1)  //从要调整的结点的最孩子开始比较
	{
		if(index+1<=len&&arr[index]<arr[index+1])
			++index;  //找到左右孩子中的最大值下标
		if(arr[index]>tmp)  //不满足，调整
		{
			arr[idx] = arr[index];
			idx = index;  //交换了值，可能引起下面子树不满足最大堆性质，继续向下调整
		}
		else 
		{
			break;
		}		
	}
	arr[idx] = tmp;
	return;
}
void swap(int& a,int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
void outputMaxHeap(vector<int>& arr)
{
	if(0==arr.size())
		return;
	int len = arr.size();
	for(int idx=len-1;idx>0;--idx)
	{
		swap(arr[0],arr[idx]);  //堆顶为最大值，交换到数组末尾
		adjust(arr,0,idx-1);  //重新调整1~idx+1个元素满足最大堆性质
	}
	//输出
	for(int idx=len-1;idx>=0;--idx)
	{
		cout<<arr[idx]<<" ";
	}
	cout<<endl;
}
#endif
/* output */
//12 43 43 20 1 39 17 49 590 18 33 0
//^Z
//590 49 43 43 39 33 20 18 17 12 1 0
//请按任意键继续. . .