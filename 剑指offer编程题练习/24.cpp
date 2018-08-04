//题目24：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则返回true，否则返回false。
//假设输入的数组的任意两个数字都互不相同
//思路：二叉搜索树，左子树小于根结点，右子树大于根结点，后序遍历，最后一个结点可以区分出左右子树根结点，
//判断，如果右子树结点中有小于根结点的，返回false;左右子树又是一棵树，又可以采采用递归接着遍历
#include<iostream>
using namespace std;
#if 1
bool isPostTraversal(int* arr,int length);
void test();
int main()
{
	test();
	system("pause");
}
bool isPostTraversal(int* arr,int length)
{
	if(nullptr==arr)
		return false;
	int treeRootNode = arr[length-1];
	int leftIdx = 0;
	//找左子树结点
	for(;leftIdx!=length-1;++leftIdx)
	{
		if(arr[leftIdx]>treeRootNode)
			break;
	}
	//找右子树结点
	int rightIdx = leftIdx;
	for(;rightIdx!=length-1;++rightIdx)
	{
		if(arr[rightIdx]<treeRootNode)
			return false;  //右子树所有结点都大于根结点
	}
	//递归判断左右子树是不是也满足BST
	bool left = true;
	if(leftIdx>0)  //有左子树
		left = isPostTraversal(arr,leftIdx);  //递归子函数，只要有一个函数不满足BST，都会return false,从而最终函数返回false。
	bool right = true;
	if(rightIdx<length-1)  //有右子树
		right = isPostTraversal(arr+leftIdx,length-leftIdx);
	return left && right;
}
void test()
{
	int arr[] = {5,7,6,9,11,10,8};
	cout<<isPostTraversal(arr,7)<<endl;
	int arr2[] = {7,4,6,5};
	cout<<isPostTraversal(arr2,4)<<endl;
	int* arr3 = nullptr;
	cout<<isPostTraversal(arr3,4)<<endl;
	int arr4[] = {5,4,6,8,7};
	cout<<isPostTraversal(arr4,5)<<endl;
}
#endif
//1
//0
//0
//1
//请按任意键继续. . .