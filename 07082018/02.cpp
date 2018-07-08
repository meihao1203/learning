//题目19：完成一个函数，输入一个二叉树，该函数输出它的镜像
//思路：镜像，就是从根结点开始，如果有左右子树存在，就交换着两个节点，每一层有相同双亲结点都交换
#include<iostream>
#include<string>
using namespace std;
#if 0
typedef struct BinaryTree
{
	char data;
	struct BinaryTree *lchild,*rchild;
}binaryTreeNode,*pBinaryTreeNode;
void createBinaryTree(pBinaryTreeNode& binary,string& str);  //建立二叉树
void inorderTraversal(const pBinaryTreeNode& binary);
void swap(binaryTreeNode*& node1,binaryTreeNode*& node2);
void mirrorBinaryTree(pBinaryTreeNode& binary);
void test();
void test2();
void test3();
int main()
{
	test();
	test2();  //空树
	test3();  //一个结点
	system("pause");
}
void test()
{
	string treeData = "ABD##E##CF###";
	pBinaryTreeNode tree = nullptr;
	createBinaryTree(tree,treeData);
	cout<<"原二叉树：";
	inorderTraversal(tree);
	cout<<endl;
	mirrorBinaryTree(tree);
	cout<<"镜像二叉树：";
	inorderTraversal(tree);
	cout<<endl;
};
void test2()
{
	string treeData = "";
	pBinaryTreeNode tree = nullptr;
	createBinaryTree(tree,treeData);
	cout<<"原二叉树：";
	inorderTraversal(tree);
	cout<<endl;
	mirrorBinaryTree(tree);
	cout<<"镜像二叉树：";
	inorderTraversal(tree);
	cout<<endl;
}
void test3()
{
	string treeData = "A##";
	pBinaryTreeNode tree = nullptr;
	createBinaryTree(tree,treeData);
	cout<<"原二叉树：";
	inorderTraversal(tree);
	cout<<endl;
	mirrorBinaryTree(tree);
	cout<<"镜像二叉树：";
	inorderTraversal(tree);
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
void inorderTraversal(const pBinaryTreeNode& binary)
{
	if(nullptr==binary)
		return ;
	inorderTraversal(binary->lchild);
	cout<<binary->data<<" ";
	inorderTraversal(binary->rchild);
}
void swap(binaryTreeNode*& node1,binaryTreeNode*& node2)
{
	binaryTreeNode* tmp;
	tmp = node1;
	node1 = node2;
	node2 = tmp;
}
void mirrorBinaryTree(pBinaryTreeNode& binary)
{
	if(nullptr==binary)
		return ;
	if(binary->lchild!=nullptr || binary->rchild!=nullptr)
	{//交换
		swap(binary->lchild,binary->rchild);  
		//swap1(binary->lchild->data,binary->rchild->data);  //不能直接换数据，遇到有一个为空的子树就GG
	}
	mirrorBinaryTree(binary->lchild);
	mirrorBinaryTree(binary->rchild);
}
#endif
//原二叉树：D B E A F C
//镜像二叉树：C F A E B D
//原二叉树：
//镜像二叉树：
//原二叉树：A
//镜像二叉树：A
//请按任意键继续. . .