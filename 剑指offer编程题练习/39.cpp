//题目39：输入一棵二叉树的根结点，求该树的深度。从根结点到叶节点依次经过的结点（含根，叶节点）形成树的
//一条路径，最长路径的长度为树的深度
//思路：前序遍历，根结点的深度就等于左右子树的最高高度+1，叶子结点左右子树为null，高度就是1
#if 0
#include<iostream>
using namespace std;
typedef struct BinaryTree
{
	int data;
	struct BinaryTree *lchild,*rchild;
}binaryTreeNode,*pBinaryTreeNode;
void createBinaryTree(pBinaryTreeNode& binary,int*& arrPtr,int length);
int binaryTreeDepth(const pBinaryTreeNode& binary);
void test();  //正常多个结点的树
void test2();  //空树
void test3();  //单只树,两个节点
void test4();  //一个结点
int main()
{
	test();
	cout<<endl;
	test2();
	cout<<endl;
	test3();
	cout<<endl;
	test4();
	system("pause");
}
void test()
{
	int arr[15] = {1,2,4,-1,-1,5,7,-1,-1,-1,3,-1,6,-1,-1};
	pBinaryTreeNode root = nullptr;
	int* arrPtr = arr;
	createBinaryTree(root,arrPtr,15);
	int depth = binaryTreeDepth(root);
	cout<<depth<<endl;
}
void test2()
{
	int arr[11] = {1,2,4,-1,-1,5,-1,-1,3,-1,-1};
	pBinaryTreeNode root = nullptr;
	int* arrPtr = arr;
	createBinaryTree(root,arrPtr,11);
	int depth = binaryTreeDepth(root);
	cout<<depth<<endl;
}
void test3()
{
	int arr[5] = {1,2,-1,-1,-1};
	pBinaryTreeNode root = nullptr;
	int* arrPtr = arr;
	createBinaryTree(root,arrPtr,5);
	int depth = binaryTreeDepth(root);
	cout<<depth<<endl;
}
void test4()
{
	int arr[13] = {1,2,3,-1,-1,-1,4,5,-1,-1,6,-1,-1};
	pBinaryTreeNode root = nullptr;
	int* arrPtr = arr;
	createBinaryTree(root,arrPtr,13);
	int depth = binaryTreeDepth(root);
	cout<<depth<<endl;
}
void createBinaryTree(pBinaryTreeNode& binary,int*& arrPtr,int length)
{
	if(arrPtr==nullptr || length<=0)
		return ;
	if(*arrPtr==-1)
	{
		binary = nullptr;
		++arrPtr;
		--length;
		return ;
	}
	binary = new binaryTreeNode();
	binary ->data = *arrPtr;
	++arrPtr;
	--length;
	createBinaryTree(binary->lchild,arrPtr,length);
	createBinaryTree(binary->rchild,arrPtr,length);
}
int binaryTreeDepth(const pBinaryTreeNode& binary)
{
	if(nullptr==binary)
		return 0;  // 树为空，深度自然就是0
	int leftDepth = binaryTreeDepth(binary->lchild);
	int rightDepth = binaryTreeDepth(binary->rchild);
	if(leftDepth==0)
		return rightDepth+1;
	else if(rightDepth==0)
		return leftDepth+1;
	else 
		return ( leftDepth<rightDepth?(leftDepth+1):(rightDepth+1) );
}
#endif 
//4
//
//0
//
//2
//
//1
//请按任意键继续. . .