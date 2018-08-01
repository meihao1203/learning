//二叉树
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
#if 0
typedef struct BinaryTreeNode  //二叉树结点数据结构
{
	char data;  
	struct BinaryTreeNode* lchild;
	struct BinaryTreeNode* rchild;
}BTNode,*pBTNode;
//创建一个二叉树
int createBinaryTree(pBTNode& root);
//二叉树的三种遍历
void preorderTraversal(const pBTNode& root);  //前序遍历,根左右
void inorderTraversal(const pBTNode& root);  //中序遍历，左根右
void postorderTraversal(const pBTNode& root);  //后序遍历，左右根
int main()
{
	do{
		BTNode* root;  //给定一个根结点指针
		createBinaryTree(root);
		cout<<"preorder traversal:"<<endl;
		preorderTraversal(root);
		cout<<endl<<endl;

		cout<<"inorder traversal:"<<endl;
		inorderTraversal(root);
		cout<<endl<<endl;;

		cout<<"postorder traversal:"<<endl;
		postorderTraversal(root);
		cout<<endl<<endl;;
	}while(cout<<"continue?(Y/N):",fflush(stdin),getchar()=='Y');
	system("pause");
}
int createBinaryTree(pBTNode& root)
{
	char data;
	//scanf("%c",&data);  //回车不会读进去
	if(cin>>data)  //不能是while, 不然递归一直再while循环，直到流错误
	{
		if('#'==data)  //如果输入数据字符为‘#’表示根结点为空
			root = NULL;
		else if('\n'!=data)
		{
			root = new BTNode();
			root->data = data;
			createBinaryTree(root->lchild);  //递归建立左子树
			createBinaryTree(root->rchild);  //递归建立右子树
		}
	}
	return 0;
}
void preorderTraversal(const pBTNode& root)
{
	if(NULL==root)
		return ; 
	cout<<root->data<<" ";  //前序遍历输出根结点数据
	preorderTraversal(root->lchild);  //前序遍历左子树
	preorderTraversal(root->rchild);  //前序遍历右子树
}
void inorderTraversal(const pBTNode& root)
{
	if(NULL==root)
		return ;
	inorderTraversal(root->lchild);  //中序遍历左子树
	cout<<root->data<<" ";  //中序遍历输出根结点数据
	inorderTraversal(root->rchild);  //中序遍历右子树
}
void postorderTraversal(const pBTNode& root)
{
	if(NULL==root)
		return ;
	postorderTraversal(root->lchild);  //后序遍历左子树
	postorderTraversal(root->rchild);  //后序遍历右子树
	cout<<root->data<<" ";  //后序遍历输出根结点数据
}
#endif
//AB##C##
//preorder traversal:
//A B C
//
//inorder traversal:
//B A C
//
//postorder traversal:
//B C A
//
//continue?(Y/N):Y
//ABC###DE##F##
//preorder traversal:
//A B C D E F
//
//inorder traversal:
//C B A E D F
//
//postorder traversal:
//C B E F D A
//
//continue?(Y/N):N