//题目：从上往下打印二叉树,同一层的结点按照从左到右的顺序打印。
//思路：这其实就是一个层序遍历
#include<iostream>
#include<string>
#include<queue>
using namespace std;
typedef struct BinaryTree
{
	char data;
	struct BinaryTree *lchild,*rchild;
}binaryTreeNode,*pBinaryTreeNode;
void createBinaryTree(pBinaryTreeNode& binary,string& str);  //建立二叉树
void preorderTraversal(const pBinaryTreeNode& binary);
void inorderTraversal(const pBinaryTreeNode& binary);
void levelTraversal(const pBinaryTreeNode& binary);
void test();
int main()
{
	test();
	system("pause");
}
void test()
{
	string treeData = "ABD##E##CF###";
	pBinaryTreeNode tree = nullptr;
	createBinaryTree(tree,treeData);
	cout<<"原二叉树前序遍历：";
	preorderTraversal(tree);
	cout<<endl;
	cout<<"原二叉树中序遍历：";
	inorderTraversal(tree);
	cout<<endl;
	cout<<"层序遍历：";
	levelTraversal(tree);
	cout<<endl;
}
void createBinaryTree(pBinaryTreeNode& binary,string& str)
{
	int idx = 0;
	if(str[idx]!='\0')
	{
		if('#'==str[idx])
		{
			binary = nullptr;
			str = str.substr(idx+1);  //读取了一个输入，修改str
			return ;
		}
		else
		{
			binary = new binaryTreeNode();
			binary->data = str[idx];
			//建立好根结点后递归建立左右子树
			str = str.substr(idx+1);  //读取了一个输入，修改str
			createBinaryTree(binary->lchild,str);
			createBinaryTree(binary->rchild,str);
		}
	}
}
void preorderTraversal(const pBinaryTreeNode& binary)
{
	if(nullptr==binary)
		return ;
	cout<<binary->data<<" ";
	preorderTraversal(binary->lchild);
	preorderTraversal(binary->rchild);
}
void inorderTraversal(const pBinaryTreeNode& binary)
{
	if(nullptr==binary)
		return ;
	inorderTraversal(binary->lchild);
	cout<<binary->data<<" ";
	inorderTraversal(binary->rchild);
}
void levelTraversal(const pBinaryTreeNode& binary)
{
	if(nullptr==binary)
		return;
	queue<pBinaryTreeNode> node;
	node.push(::move(binary));
	while(!node.empty())
	{
		if(node.front()->lchild!=nullptr)
			node.push(::move(node.front()->lchild));
		if(node.front()->rchild!=nullptr)
			node.push(::move(node.front()->rchild));
		cout<<node.front()->data<<" ";
		node.pop();
	}
	return;
}
//原二叉树前序遍历：A B D E C F
//原二叉树中序遍历：D B E A F C
//层序遍历：A B C D E F
//请按任意键继续. . .
