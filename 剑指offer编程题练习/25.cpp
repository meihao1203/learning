//面试题25：输入一棵二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。从根结点开始
//往下一直到叶节点所经过的结点形成一条路径。路径是从根结点到也叶子结点
//思路：类似二叉树的前序遍历，从根结点开始向下遍历，这个过程中保存遍历路径上的值，如果和给定的值相同并且到达叶子结点，就输出路径
//回溯过程中要减去对应的结点的值并从路径中删除
#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define BinaryTreeNode_ValueType int
typedef struct BinaryTree
{
	int data;
	struct BinaryTree *lchild,*rchild;
}binaryTreeNode,*pBinaryTreeNode;
void createBinaryTree(pBinaryTreeNode& binary,int*& arrPtr,int length);
void fingPath(const pBinaryTreeNode& root,vector<BinaryTreeNode_ValueType>& path,int& currentSum,int expectedSum);
void preorderTraversal(const pBinaryTreeNode& root);
void test();
int main()
{
	test();
}
void createBinaryTree(pBinaryTreeNode& binary,int*& arrPtr,int length)
{
	if(arrPtr==nullptr || length<=0)
		return ;
	if(*arrPtr==-1)
	{
		binary = nullptr;
		++arrPtr;
		return ;
	}
	binary = new binaryTreeNode();
	binary ->data = *arrPtr;
	++arrPtr;
	createBinaryTree(binary->lchild,arrPtr,length);
	createBinaryTree(binary->rchild,arrPtr,length);
}
void test()
{
	//string tree1data = "10";
	int arr[11] = {10,5,4,-1,-1,7,-1,-1,12,-1,-1};
	pBinaryTreeNode root = nullptr;
	int* arrPtr = arr;
	createBinaryTree(root,arrPtr,11);
	cout<<"前序遍历：";
	preorderTraversal(root);
	cout<<endl;
	vector<BinaryTreeNode_ValueType> path;
	int currentSum = 0;
	fingPath(root,path,currentSum,22);
	cout<<endl;
}
void preorderTraversal(const pBinaryTreeNode& root)
{
	if(nullptr==root)
		return ;
	cout<<root->data<<" ";
	preorderTraversal(root->lchild);
	preorderTraversal(root->rchild);
}
void fingPath(const pBinaryTreeNode& root,vector<BinaryTreeNode_ValueType>& path,int& currentSum,int expectedSum)
{
	if(nullptr==root)
		return ;
	path.push_back(root->data);
	currentSum += root->data;
	bool isLeaf = (root->lchild==nullptr && root->rchild==nullptr);
	if(currentSum==expectedSum && isLeaf)  //找到满足大小的路径，并且已经到了叶子结点
	{
		for(auto& elem:path)
			cout<<elem<<" ";
		cout<<"sum = "<<currentSum<<endl;
	}
	fingPath(root->lchild,path,currentSum,expectedSum);
	fingPath(root->rchild,path,currentSum,expectedSum);
	//左右子树遍历完了，回溯
	currentSum -= root->data;
	path.pop_back();
}
//前序遍历：10 5 4 7 12
//10 5 7 sum = 22
//10 12 sum = 22
//
//请按任意键继续. . .
