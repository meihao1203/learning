#include"BST.h"
bstNode* BST_Search(pBstNode root,int key)  //二叉排序树中查找关键字key
{
	if(nullptr==root)
		return nullptr;
	if(root->data==key)
	{
		return root;
	}
	else if(key>root->data)  //大于根结点，右子树中继续查找
	{
		BST_Search(root->rchild,key);  
	}
	else if(key<root->data)  //小于根结点，做左子树中继续查找
	{
		BST_Search(root->lchild,key);
	}
}  

void BST_Insert(pBstNode& root,int data)  //二叉排序树中插入结点
{
	if(nullptr==root)
	{
		root = new bstNode();
		root->lchild = root->rchild = nullptr;
		root->data = data;
		return ;
	}
	//遍历二叉排序树，找到待插入节点数据的位置
	bstNode* parentNode = nullptr;  //parentNode永远指向data待插入位置的父结点
	bstNode* curNode = root;
	while(nullptr!=curNode)
	{
		parentNode = curNode;
		if(data>curNode->data)
			curNode = curNode->rchild;  //应该插入到右子树
		else if(data<=curNode->data)   
			curNode = curNode->lchild;  //应该插入到左子树
	}
	//找到插入位置
	if(data>parentNode->data)
	{
		bstNode* newNode = new bstNode();
		newNode->data = data;
		newNode->lchild = nullptr;
		newNode->rchild = nullptr;
		parentNode->rchild = newNode;  //插入到右子树
		return ;
	}
	else
	{
		bstNode* newNode = new bstNode();
		newNode->data = data;
		newNode->lchild = nullptr;
		newNode->rchild = nullptr;
		parentNode->lchild = newNode;  //插入到左子树
		return ;
	}
}

int deleteNode(bstNode*& node)
{//二叉搜索树删除，node的前驱替换
	if(nullptr==node)
		return -1;
	bstNode* delNode = node;  //暂存要删除节点
	//1、只有一个结点
	if(nullptr==node->lchild && nullptr==node->rchild)
	{
		node = nullptr;  //前面这些情况为什么能直接改nullptr?
		//下面递归传值的时候传的是root->lchild或者root->rchild,所能是对父结点的左右指针修改。
		//而不是类似这种node1(lchild,data,adrnode2)->node2(lchild,data,lchild2),然后传node2，把node2=nullptr,这样到时候遍历根结点就会根据一个野指针adrnode2访问到脏数据 
		delete delNode;
		return 0;
	}
	//2、只有左孩子，重接左孩子就好
	else if (nullptr==node->rchild)
	{
		node = node->lchild;
		delete delNode;
		return 0;
	}
	//3、只有右孩子
	else if(nullptr==node->lchild)
	{
		node = node->rchild;
		delete delNode;
		return 0;
	}
	//4、左右孩子都有
	else if(nullptr!=node->lchild && nullptr!=node->rchild)
	{//找前驱
		bstNode* parent = delNode;  //记录父结点
		delNode = delNode->lchild;
		//待删除节点delNode没有右子树，前驱就是delNode
		if(nullptr==delNode->rchild)
		{
			node->data = delNode->data;
			parent->lchild = delNode->lchild;
			return 0;
		}
		//有右子树，前驱是右子树的最右结点
		while(nullptr!=delNode->rchild)
		{
			parent = delNode;
			delNode = delNode->rchild;
		}
		//找到前驱，开始替换,只要替换结点数据即可，左右孩子关系不能更改
		node->data = delNode->data;
		//判断前驱是不是要用其他结点替换
		parent->rchild = delNode->lchild;
		return 0;
	}
	return 0;
}
int BST_Delete(pBstNode& root,int key)  //二叉树删除关键字key
{
	if(nullptr==root)
		return -1;
	if(key==root->data)
	{
		return deleteNode(root);
	}
	else if(key>root->data)
		return BST_Delete(root->rchild,key);  //右子树中查找删除
	else if(key<root->data)
		return BST_Delete(root->lchild,key);
}

/*  二叉搜索树的三种遍历  */
void preorderTraversal_BST(const pBstNode& root)
{
	if(nullptr==root)
		return;
	cout<<root->data<<" ";
	preorderTraversal_BST(root->lchild);
	preorderTraversal_BST(root->rchild);
}
void inorderTraversal_BST(const pBstNode& root)
{
	if(nullptr==root)
		return;
	inorderTraversal_BST(root->lchild);
	cout<<root->data<<" ";
	inorderTraversal_BST(root->rchild);
}
void postorderTraversal_BST(const pBstNode& root)
{
	if(nullptr==root)
		return;
	inorderTraversal_BST(root->lchild);
	inorderTraversal_BST(root->rchild);
	cout<<root->data<<" ";
}