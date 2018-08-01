#include<iostream>
#include<stack>
using namespace std;
#if 1
typedef struct BinaryTree
{
	char data;
	struct BinaryTree* lchild;
	struct BinaryTree* rchild;
}binaryTreeNode,*pBinaryTree;
int createBinaryTree(pBinaryTree& root);
//非递归实现前序遍历，利用栈来模拟递归过程
void preorderTraversalNonRecursion(pBinaryTree root);  
//非递归实现中序遍历，利用栈来模拟递归过程
void inorderTraversalNonRecursion(pBinaryTree root);
//非递归实现后序遍历,利用栈来模拟递归过程
void postorderTraversalNonRecursion(pBinaryTree root);
int main()
{
	pBinaryTree root = nullptr;
	int ret = createBinaryTree(root);
	if(0==ret)
	{
		cout<<"preorder traversal non-recursion:"<<endl;
		preorderTraversalNonRecursion(root);
		cout<<endl<<endl;;
		cout<<"inorder traversal non-recursion:"<<endl;
		inorderTraversalNonRecursion(root);
		cout<<endl<<endl;;
		cout<<"postorder traversal non-recursion:"<<endl;
		postorderTraversalNonRecursion(root);
		cout<<endl;
	}

	cout<<endl;
	system("pause");
}
int createBinaryTree(pBinaryTree& root)
{
	char data;
	if(cin>>data)
	{
		if('#'==data)  //输入#表示该结点为空
		{
			root = NULL;  
			return -1;  //只要当输入是#才会返回-1，表示空树
		}		
		//建立根结点
		binaryTreeNode* node = new binaryTreeNode();
		node->data = data;
		root = node;
		//递归去建立左子树
		createBinaryTree(root->lchild);
		//递归去建立右子树
		createBinaryTree(root->rchild);
	}
	return 0;   //最终递归返回的是0；
}

void preorderTraversalNonRecursion(pBinaryTree root)
{//访问节点顺序是：根结点，左子树，右子树;针对左右子树，又是按照根左右的顺序访问，所有这个过程中要记录根结点
	if(nullptr==root)
		return;
	stack<binaryTreeNode*> rootNode;  //遍历过程中记录根结点
	while(!rootNode.empty()||
		nullptr!=root)
	{
		while(nullptr!=root)
		{
			cout<<root->data<<" ";  //输出根结点
			//遍历左子树
			rootNode.push(root);  //记录左子树的根结点，前序遍历回溯访问右子树的时候要用到
			root = root->lchild;
		}//一直遍历到最左边的最后一个结点，肯定左子树为空了，出while循环，这时候就要回溯访问右子树了
		if(!rootNode.empty())
		{
			root = rootNode.top();  //栈中取出最近入栈的根结点
			root = root->rchild;  //根结点指向右子树
			rootNode.pop();  //最近压栈的根结点弹栈
			//右子树也是一棵二叉树，又回到第二个while循环，前序遍历，根左右的方法访问右子树
		}

	}
}
void inorderTraversalNonRecursion(pBinaryTree root)
{//左子树，根结点，右子树
	if(nullptr==root)
		return ;
	stack<binaryTreeNode*> rootNode;
	while(nullptr!=root||
		!rootNode.empty())
	{
		while(nullptr!=root)
		{
			rootNode.push(root);  //栈中保存根结点，先去访问左子树
			root = root->lchild;
		}//左子树遍历完毕
		cout<<rootNode.top()->data<<" ";  //访问根结点
		root = rootNode.top()->rchild;  //访问右子树
		rootNode.pop();  //出栈最近保存的结点
	}
}

typedef struct Traversal
{
	binaryTreeNode* rootAddr;   //二叉树结点地址
	bool accessToken;  //访问标记
}traversalInfo,*pTraversal;

//简化操作
void stackPush(stack<traversalInfo>& rootNodeInfo,binaryTreeNode* &rootAddr,bool&& flag)
{
	traversalInfo tmp;
	tmp.rootAddr = rootAddr;
	tmp.accessToken = flag;  //第一次访问,第二次访问修改为true，输出信息
	rootNodeInfo.push(tmp);
}
void postorderTraversalNonRecursion(pBinaryTree root)
{//后序遍历，左子树，右子树，根结点
	//遍历完左子树后要回溯到根结点去遍历右子树，所以需要一个标记来记录根结点，如果是第二次遍历到就直接输出值
	if(nullptr==root)
		return ;
	stack<traversalInfo> rootNodeInfo;
	while(nullptr!=root)   //二叉树根结点最后才会访问
	{
		//遍历左子树
		stackPush(rootNodeInfo,root,false);
		//traversalInfo tmp;
		//tmp.rootAddr = root;
		//tmp.accessToken = false;  //第一次访问,第二次访问修改为true，输出信息
		//rootNodeInfo.push(tmp);  //遍历右子树沿途的根结点入栈

		root = root->lchild;
	}//开始回溯遍历右子树
	while(!rootNodeInfo.empty())
	{
		root = rootNodeInfo.top().rootAddr;  //取出最近访问的根结点
		//遍历右子树
		while(nullptr!=root->rchild&&
			!rootNodeInfo.top().accessToken)  //右子树不空，并且根结点只存在第一次访问
		{
			rootNodeInfo.top().accessToken = true;  //根结点第二次访问，修改为true，下次回溯访问到就要输出
			//右子树根结点进栈
			root = root->rchild;
			stackPush(rootNodeInfo,root,false);
			//traversalInfo tmp;
			//tmp.rootAddr = root;
			//tmp.accessToken = false;
			//rootNodeInfo.push(tmp);

			//右子树的左子树不空，接着遍历左子树
			while(nullptr!=root->lchild)  
			{
				root = root->lchild;
				stackPush(rootNodeInfo,root,false);
				/*traversalInfo tmp;
				tmp.rootAddr = root;
				tmp.accessToken = false;
				rootNodeInfo.push(tmp);*/
			}//右子树的左子树遍历完毕，回溯遍历右子树的右子树。
		}
		//输出结点信息
		//执行下面语句只有两种情况，1、对应二叉树最左边结点没有右子树，包括右子树的最左边结点
		//2、回溯再次访问到根结点，即第3个while循环的第二个条件!rootNodeIndo.top().accessToken不满足
		cout<<rootNodeInfo.top().rootAddr->data<<" ";
		rootNodeInfo.pop();  //出栈
	}
}
#endif
/* 测试用例一 */
//AB##C##
//preorder traversal non-recursion:
//A B C
//
//inorder traversal non-recursion:
//B A C
//
//postorder traversal non-recursion:
//B C A
//
//请按任意键继续. . .


/* 测试用例二 */
//ABC###DE##F##
//preorder traversal non-recursion:
//A B C D E F
//
//inorder traversal non-recursion:
//C B A E D F
//
//postorder traversal non-recursion:
//C B E F D A
//
//请按任意键继续. . .