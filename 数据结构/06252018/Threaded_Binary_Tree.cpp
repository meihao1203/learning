#include<iostream>
using namespace std;
enum TBT{child=0,thread};
typedef struct tbt
{
	struct tbt* lchild;
	enum TBT ltag;
	char data;
	enum TBT rtag;
	struct tbt* rchild;
}TBTreeNode,*pTBTree;
int createThreadedBinaryTree(pTBTree& root);
//中序线索化+遍历
void inorderThreadingBinaryTree(const pTBTree& root,TBTreeNode*& pre); 
void inorderThreadedBinaryTreeTraversal(pTBTree root);
//前序线索化+遍历
void preorderThreadingBinaryTree(const pTBTree& root,TBTreeNode*&pre);
void preorderThreadedBinaryTreeTraversal(pTBTree root);

int main()
{
	TBTreeNode* root = nullptr;
	int ret = createThreadedBinaryTree(root);
	if(0==ret)
	{
		TBTreeNode* pre = nullptr;
		//inorderThreadingBinaryTree(root,pre);
		//cout<<"inorder traversal Threaded Binary Tree:"<<endl;
		//inorderThreadedBinaryTreeTraversal(root);
		//cout<<endl;

		pre = nullptr;
		preorderThreadingBinaryTree(root,pre);
		cout<<"preorder traversal Threaded Binary Tree:"<<endl;
		preorderThreadedBinaryTreeTraversal(root);
		cout<<endl;
	}
	system("pause");
}
int createThreadedBinaryTree(pTBTree& root)
{
	char data;
	if(cin>>data)
	{
		if('#'==data)
		{
			root = nullptr;
			return -1;
		}
		root = new TBTreeNode();
		root->data = data;
		createThreadedBinaryTree(root->lchild);
		createThreadedBinaryTree(root->rchild);
	}
	return 0;
}

void inorderThreadingBinaryTree(const pTBTree& root,TBTreeNode*& pre)
{
	if(nullptr==root)
		return ;
	inorderThreadingBinaryTree(root->lchild,pre);
	if(nullptr==root->lchild)
	{
		root->lchild = pre;
		root->ltag = thread;
	}
	if(nullptr!=pre&&nullptr==pre->rchild)
	{
		pre->rchild = root;
		pre->rtag = thread;
	}
	pre = root;
	inorderThreadingBinaryTree(root->rchild,pre);
}
void inorderThreadedBinaryTreeTraversal(pTBTree root)
{
	if(nullptr==root)
		return ;
	while(nullptr!=root)
	{
		while(nullptr!=root->lchild&&child==root->ltag)
		{
			root = root->lchild;
		}
		cout<<root->data<<" ";
		while(thread==root->rtag)
		{
			cout<<root->rchild->data<<" ";
			root = root->rchild;
		}
		root = root->rchild;
	}
}

void preorderThreadingBinaryTree(const pTBTree& root,TBTreeNode*&pre)
{
	if(nullptr==root)
		return ;
	/*  参考中序遍历
	cout<<root->data;
	preorderTraversal(root->lchild);
	preorderTraversal(root->rchild);
	*/
	// 访问顺序：根结点，左子树，右子树
	//pre永远指向当前访问结点root的前一个访问过的结点，初始为null
	if(nullptr==root->lchild)
	{
		root->lchild = pre;
		root->ltag = thread;
	}
	if(nullptr!=pre&&nullptr==pre->rchild)
	{//要线索化一个及结点的后继，按照后序遍历顺序，只能访问到root的时候才能线索化前一个结点pre的后继，前提pre要不是null,并且没有右子树
		pre->rchild = root;
		pre->rtag = thread;
	}
	pre = root;
	//区别于中序线索化二叉树，因为当前结点先访问到，同时给线索化了
	//所以下面访问左右子树就要判断一下是真的有左右子树而不是线索化的前驱后继
	if(child==root->ltag)
	{
		preorderThreadingBinaryTree(root->lchild,pre);
	}
	if(child==root->rtag)
	{
		preorderThreadingBinaryTree(root->rchild,pre);
	}
}
void preorderThreadedBinaryTreeTraversal(pTBTree root)
{
	if(nullptr==root)
		return ;
	while(nullptr!=root)
	{
		while(nullptr!=root->lchild&&
			child==root->ltag)
		{
			cout<<root->data<<" ";  //访问根结点
			root = root->lchild;  //继续访问左子树
		}
		//左子树的最左边结点
		cout<<root->data<<" ";
		//通过后继遍历下一个要访问的结点
		while(thread==root->rtag)  //当前结点有后继
		{
			cout<<root->rchild->data<<" ";  //输出后继
			root = root->rchild;  //更新根结点
		}
		//如果结点没有后继，那么就是有右子树
		//针对这样的情况，先判断当前结点有没有左子树，有就更新根结点先遍历左子树
		if(child==root->ltag)
			root = root->lchild;
		//没有就遍历右子树
		else 
			root = root->rchild;
	}
}
//ab##c##
//preorder traversal Threaded Binary Tree:
//a b c
//请按任意键继续. . .

//ABC###DE##F##
//preorder traversal Threaded Binary Tree:
//A B C D E F
//请按任意键继续. . .

//ABDH##I##EJ###CF##G##
//preorder traversal Threaded Binary Tree:
//A B D H I E J C F G
//请按任意键继续. . .