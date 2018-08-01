#include<iostream>
#include<queue>
using namespace std;
typedef struct BinaryTree
{
	char data;
	struct BinaryTree* lchild;
	struct BinaryTree* rchild;
}binaryTreeNode,*pBinaryTree;

int createBinaryTree(pBinaryTree& root);
void levelOrder(const pBinaryTree& root);

int main()
{
	binaryTreeNode* root = NULL;
	createBinaryTree(root);
	levelOrder(root);
	cout<<endl;
	system("pause");
}
int createBinaryTree(pBinaryTree& root)
{
	char data;
	if(cin>>data)  //这里永远不能写while
	{
		if('#'==data)
			root = NULL;
		else 
		{
			root = new binaryTreeNode();
			root->data = data;
			createBinaryTree(root->lchild);
			createBinaryTree(root->rchild);
		}
	}
	return 0;
}
//void levelOrder(const pBinaryTree& root)   //用数据结构队列queue实现
//{
//	if(NULL==root)
//		return ;
//	queue<pBinaryTree> tmp;
//	tmp.push(root);
//	while(!tmp.empty())
//	{
//		cout<<tmp.front()->data<<" ";
//		if(NULL!=tmp.front()->lchild)
//			tmp.push(tmp.front()->lchild);
//		if(NULL!=tmp.front()->rchild)
//			tmp.push(tmp.front()->rchild);
//		delete tmp.front();
//		tmp.pop();
//	}
//	return;
//}
typedef struct List
{
	binaryTreeNode* btNodeAddr;
	struct List* next;
}btListNode,*btList;
void levelOrder(const pBinaryTree& root)  //用链表来时先，数组不知道预先开辟多少空间
{
	if(NULL==root)
		return ;
	btListNode* rootNode = new btListNode();
	rootNode->btNodeAddr = root;  //初始化链表指向二叉树根结点
	rootNode->next = NULL;
	btList headNode = rootNode,tailNode = rootNode;
	while(NULL!=headNode)
	{
		cout<<headNode->btNodeAddr->data<<" ";
		if(NULL!=headNode->btNodeAddr->lchild)
		{
			btListNode* newNode = new btListNode();
			newNode->btNodeAddr = headNode->btNodeAddr->lchild;
			newNode->next = NULL;
			tailNode->next = newNode;
			tailNode = newNode;
		}
		if(NULL!=headNode->btNodeAddr->rchild)
		{
			btListNode* newNode = new btListNode();
			newNode->btNodeAddr = headNode->btNodeAddr->rchild;
			newNode->next = NULL;
			tailNode->next = newNode;
			tailNode = newNode;
		}
		//删除链表第一个结点
		btListNode* tmp = headNode;
		headNode = headNode->next;
		delete tmp;
	}
}

//AB##C##
//^Z
//A B C
//请按任意键继续. . .

//ABC###DE##F##
//A B D C E F
//请按任意键继续. . .