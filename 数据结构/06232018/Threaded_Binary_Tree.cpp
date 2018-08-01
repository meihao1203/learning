#include<iostream>
using namespace std;
enum TBT{child=0,thread};  //线索二叉树结点的指针是指向孩子还是前驱后继
typedef struct tbt
{
	struct tbt* lchild;
	enum TBT ltag;
	char data;
	enum TBT rtag;
	struct tbt* rchild;
}TBTreeNode,*pTBTree;
int createThreadedBinaryTree(pTBTree& root);
void inorderThreadingBinaryTree(const pTBTree& root);  //中序线索化二叉树
//在中序遍历的同时就线索化二叉树
void inorderThreadingBinaryTreeTraversal(pTBTree root); //中序线索化二叉树遍历
int main()
{
	TBTreeNode* root = nullptr;
	int ret = createThreadedBinaryTree(root);
	{
		if(0==ret)
		{
			inorderThreadingBinaryTree(root);
			cout<<endl;
			inorderThreadingBinaryTreeTraversal(root);
			cout<<endl;
		}
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
		else 
		{//用data数据来初始化root结点，然后递归建立左子树和右子树
			root = new TBTreeNode();  //创建结点的时候就把结点全部赋值为空
			root->data = data;
			createThreadedBinaryTree(root->lchild);
			createThreadedBinaryTree(root->rchild);
		}
	}
	return 0;
}

static TBTreeNode* pre = nullptr;  //定义一个指针指向中序遍历当前访问结点的前一个访问结点
//线索化结点的后继要用到,因为中序遍历顺序：左子树,根结点，右子树
//前驱可以用刚刚访问过的结点直接赋值，后继还没有访问，这时候当前结点就是上一个访问结点pre的后继
//当然，前提条件是pre的右子树为空
//pre初始值为nullptr,因为从根结点开始访问，前一个访问结点就只能是空了
void inorderThreadingBinaryTree(const pTBTree& root)
{
	if(nullptr==root)
		return ;
	/*  参考中序遍历
	inorderTraversal(root->lchild);
	cout<<root->data<<" ";
	inorderTraversal(root->rchild);
	*/
	inorderThreadingBinaryTree(root->lchild);   //中序遍历左子树
	//判断结点指针域可不可以线索化
	if(nullptr==root->lchild)  //如果左子树为空，就可以把指针域拿来线索化，指向前驱
	{
		root->lchild = pre;
		root->ltag = thread;
	}
	if(nullptr!=pre&&nullptr==pre->rchild)  //如果当前访问的根结点不为空，并且前面访问的结点pre右子树为空，线索化前一个结点的后继
	{
		pre->rchild = root;
		pre->rtag = thread;
	}
	//访问根结点就变成修改前一个访问结点指针pre
	pre = root;  //之后要访问右子树，当前结点自然就是pre
	inorderThreadingBinaryTree(root->rchild);  //中序遍历右子树
}
void inorderThreadingBinaryTreeTraversal(pTBTree root)
{
	if(nullptr==root)
		return;
	while(nullptr!=root)
	{
		while(nullptr!=root->lchild&&child==root->ltag)  //两个条件，区别中序遍历第一个结点的前驱是nullptr
		{//搜寻从根结点开始的左子树的最后一个节点
			root = root->lchild;
		}
		cout<<root->data<<" ";  //输出根结点
		while(thread==root->rtag)  //该结点有后继,意味着没有右子树
		{
			cout<<root->rchild->data<<" ";  //直接输出后继，也就是中序遍历当前结点下一个要访问的结点的值
			root = root->rchild;  //根结点回溯到后继
		}
		//该结点有右子树，root->rtag==child,左子树已经遍历完了，这里进入右子树
		root = root->rchild;   //重复上面的操作
	}
}