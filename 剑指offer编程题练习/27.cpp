//题目27：输入一棵二叉搜索树，将该二叉树转换成一个排序的双向链表。
//要求不能创建任何新的结点，只能调整树中结点指针的指向。
//思路：BST中序遍历得到的结果就是从小到大的序列，在中序遍历的过程中修改链接关系就可以得到一个双向链表
//左指针指向序列中前一个结点，右指针指向后一个节点，所以在遍历的过程中需要一个指针来记录上一个访问的结点
//初始值设为null,如果结点的右指针不为空就不用修改了。上一个访问的结点的右指针为空就执行当前访问结点，
//正好是后一个节点
#include<iostream>
using namespace std;
typedef struct BinaryTree
{
	int data;
	struct BinaryTree *lchild,*rchild;
}binaryTreeNode,*pBinaryTreeNode;
void createBinaryTree(pBinaryTreeNode& binary,int*& arrPtr,int length);
void inorderTraversal(const pBinaryTreeNode& binary);
pBinaryTreeNode BstToDoubleList(pBinaryTreeNode& binary);
void bstToDoubleList(pBinaryTreeNode& binary,binaryTreeNode*& pre);
void test();
void test2();
void test3();
void test4();
void test5();
int main()
{
	test();
	cout<<endl;
	test2();
	cout<<endl;
	test3();
	cout<<endl;
	test4();
	cout<<endl;
	test5();
}

void test()
{
	int arr[15] = {10,6,4,-1,-1,8,-1,-1,14,12,-1,-1,16,-1,-1};
	pBinaryTreeNode root = nullptr;
	int* arrPtr = arr;
	createBinaryTree(root,arrPtr,11);
	cout<<"中序遍历：";
	inorderTraversal(root);
	cout<<endl;
	binaryTreeNode* head = BstToDoubleList(root);
	if(nullptr==head)
		return ;
	cout<<"双向链表正向遍历：";
	while(head->rchild!=nullptr)
	{
		cout<<head->data<<" ";
		head = head->rchild;
	}
	cout<<head->data<<" ";
	cout<<endl;
	cout<<"双向链表反向遍历：";
	while(head->lchild!=nullptr)
	{
		cout<<head->data<<" ";
		head = head->lchild;
	}
	cout<<head->data<<" ";
	cout<<endl;
}
void test2()
{
	int arr[12] = {3,2,1,-1,-1,-1,4,-1,5,-1,-1};
	pBinaryTreeNode root = nullptr;
	int* arrPtr = arr;
	createBinaryTree(root,arrPtr,12);
	cout<<"中序遍历：";
	inorderTraversal(root);
	cout<<endl;
	binaryTreeNode* head = BstToDoubleList(root);
	if(nullptr==head)
		return ;
	cout<<"双向链表正向遍历：";
	while(head->rchild!=nullptr)
	{
		cout<<head->data<<" ";
		head = head->rchild;
	}
	cout<<head->data<<" ";
	cout<<endl;
	cout<<"双向链表反向遍历：";
	while(head->lchild!=nullptr)
	{
		cout<<head->data<<" ";
		head = head->lchild;
	}
	cout<<head->data<<" ";
	cout<<endl;
}
void test3()
{
	int arr[7] = {3,2,1,-1,-1,-1,-1};
	pBinaryTreeNode root = nullptr;
	int* arrPtr = arr;
	createBinaryTree(root,arrPtr,7);
	cout<<"中序遍历：";
	inorderTraversal(root);
	cout<<endl;
	binaryTreeNode* head = BstToDoubleList(root);
	if(nullptr==head)
		return ;
	cout<<"双向链表正向遍历：";
	while(head->rchild!=nullptr)
	{
		cout<<head->data<<" ";
		head = head->rchild;
	}
	cout<<head->data<<" ";
	cout<<endl;
	cout<<"双向链表反向遍历：";
	while(head->lchild!=nullptr)
	{
		cout<<head->data<<" ";
		head = head->lchild;
	}
	cout<<head->data<<" ";
	cout<<endl;
}
void test4()
{
	int arr[3] = {10,-1,-1};
	pBinaryTreeNode root = nullptr;
	int* arrPtr = arr;
	createBinaryTree(root,arrPtr,3);
	cout<<"中序遍历：";
	inorderTraversal(root);
	cout<<endl;
	binaryTreeNode* head = BstToDoubleList(root);
	if(nullptr==head)
		return ;
	cout<<"双向链表正向遍历：";
	while(head->rchild!=nullptr)
	{
		cout<<head->data<<" ";
		head = head->rchild;
	}
	cout<<head->data<<" ";
	cout<<endl;
	cout<<"双向链表反向遍历：";
	while(head->lchild!=nullptr)
	{
		cout<<head->data<<" ";
		head = head->lchild;
	}
	cout<<head->data<<" ";
	cout<<endl;
}
void test5()
{
	int* arr = nullptr;
	pBinaryTreeNode root = nullptr;
	int* arrPtr = arr;
	createBinaryTree(root,arrPtr,3);
	cout<<"中序遍历：";
	inorderTraversal(root);
	cout<<endl;
	binaryTreeNode* head = BstToDoubleList(root);
	if(nullptr==head)
		return ;
	cout<<"双向链表正向遍历：";
	while(head->rchild!=nullptr)
	{
		cout<<head->data<<" ";
		head = head->rchild;
	}
	cout<<head->data<<" ";
	cout<<endl;
	cout<<"双向链表反向遍历：";
	while(head->lchild!=nullptr)
	{
		cout<<head->data<<" ";
		head = head->lchild;
	}
	cout<<head->data<<" ";
	cout<<endl;
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
void inorderTraversal(const pBinaryTreeNode& binary)
{
	if(nullptr==binary)
		return;
	inorderTraversal(binary->lchild);
	cout<<binary->data<<" ";
	inorderTraversal(binary->rchild);
}
pBinaryTreeNode BstToDoubleList(pBinaryTreeNode& binary)
{
	if(nullptr==binary)
		return nullptr;
	binaryTreeNode* pre = nullptr;
	bstToDoubleList(binary,pre);
	binaryTreeNode* head = pre;
	while(head->lchild!=nullptr)  //就该BST成双向链表后，pre指向最后一个结点，从右至左找到头结点
		head = head->lchild;
	return head;
}
void bstToDoubleList(pBinaryTreeNode& binary,binaryTreeNode*& pre)
{
	if(binary==nullptr)
		return;
	pBinaryTreeNode pcur = binary;   //如果这里放在中间的话，递归遍历右子树的最左结点，将会修改根结点的右指针指向右子树的最左结点
	//这样回溯到访问根结点右子树根结点的时候链接关系已经改变，所以要先定义变量存放这个跟结点的右子树根结点，确保根结点的左右子树遍历
	//修改链接指针后能正确返回
	bstToDoubleList(pcur->lchild,pre);
	//访问结点修改为更新指针
	pcur->lchild = pre;
	if(nullptr!=pre) 
		pre->rchild = pcur;
	pre = pcur;  //更新记录上一次访问的指针，因为下面要访问递归遍历访问binary->rchild了
	bstToDoubleList(pcur->rchild,pre);   //这里出问题了，前面修改了指针
}
//中序遍历：4 6 8 10 12 14 16
//双向链表正向遍历：4 6 8 10 12 14 16
//双向链表反向遍历：16 14 12 10 8 6 4
//
//中序遍历：1 2 3 4 5
//双向链表正向遍历：1 2 3 4 5
//双向链表反向遍历：5 4 3 2 1
//
//中序遍历：1 2 3
//双向链表正向遍历：1 2 3
//双向链表反向遍历：3 2 1
//
//中序遍历：10
//双向链表正向遍历：10
//双向链表反向遍历：10
//
//中序遍历：
//请按任意键继续. . .
