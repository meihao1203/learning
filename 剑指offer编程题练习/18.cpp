//题目18：输入两棵二叉树A和B，判断B是不是A的子结构。
//思路：采用前序遍历访问给定的树，对每次访问的结点都和二叉树B去匹配，如果是子树就返回true，递归就很简单了
#include<iostream>
#include<string>
using namespace std;
typedef struct BinaryTree
{
	char data;
	struct BinaryTree *lchild,*rchild;
}binaryTreeNode,*pBinaryTreeNode;
void createBinaryTree(pBinaryTreeNode& binary,string& str);  //建立二叉树
bool judgeIsSubTree(const pBinaryTreeNode& binaryTree1,const pBinaryTreeNode& binaryTree2);
bool isSubTree(const pBinaryTreeNode& tree1,const pBinaryTreeNode& tree2);
void test();
void test2();
void test3();  //B为空
void test4();  //A为空
void test5();  //AB都为空
int main()
{
	test();
	test2();
	test3();
	test4();
	test5();
}
void test()
{
	string tree1data = "889##24##7##7##";
	string tree2data = "89##2##";
	cout<<"tree1="<<tree1data<<" tree2="<<tree2data<<endl;
	binaryTreeNode* tree1 = nullptr;
	binaryTreeNode* tree2 = nullptr;
	createBinaryTree(tree1,tree1data);
	createBinaryTree(tree2,tree2data);
	cout<<judgeIsSubTree(tree1,tree2)<<endl;
}
void test2()
{
	string tree1data = "889##34##7##7##";
	string tree2data = "89##2##";
	cout<<"tree1="<<tree1data<<" tree2="<<tree2data<<endl;
	binaryTreeNode* tree1 = nullptr;
	binaryTreeNode* tree2 = nullptr;
	createBinaryTree(tree1,tree1data);
	createBinaryTree(tree2,tree2data);
	cout<<judgeIsSubTree(tree1,tree2)<<endl;
}
void test3()
{
	string tree1data = "889##34##7##7##";
	string tree2data = "";
	cout<<"tree1="<<tree1data<<" tree2="<<tree2data<<endl;
	binaryTreeNode* tree1 = nullptr;
	binaryTreeNode* tree2 = nullptr;
	createBinaryTree(tree1,tree1data);
	createBinaryTree(tree2,tree2data);
	cout<<judgeIsSubTree(tree1,tree2)<<endl;
}
void test4()
{
	string tree1data = "";
	string tree2data = "89##2##";
	cout<<"tree1="<<tree1data<<" tree2="<<tree2data<<endl;
	binaryTreeNode* tree1 = nullptr;
	binaryTreeNode* tree2 = nullptr;
	createBinaryTree(tree1,tree1data);
	createBinaryTree(tree2,tree2data);
	cout<<judgeIsSubTree(tree1,tree2)<<endl;
}
void test5()
{
	string tree1data = "";
	string tree2data = "";
	cout<<"tree1="<<tree1data<<" tree2="<<tree2data<<endl;
	binaryTreeNode* tree1 = nullptr;
	binaryTreeNode* tree2 = nullptr;
	createBinaryTree(tree1,tree1data);
	createBinaryTree(tree2,tree2data);
	cout<<judgeIsSubTree(tree1,tree2)<<endl;
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
bool judgeIsSubTree(const pBinaryTreeNode& binaryTree1,const pBinaryTreeNode& binaryTree2)
{  //前序遍历
	bool flag = false;
	if(nullptr==binaryTree2)
	{  //要匹配的子树是空，肯定就是子结构了
		flag = true;
		return flag;
	}
	if(nullptr!=binaryTree1)
	{
		if(binaryTree1->data == binaryTree2->data)
		{ //根结点值相同，进一步考虑是不是子结构
			flag = isSubTree(binaryTree1,binaryTree2);
		}
		if(false==flag)  //如果没匹配到，接着在左子树里找
			flag = judgeIsSubTree(binaryTree1->lchild,binaryTree2);
		if(false==flag)  //左子树也没匹配到，结合在右子树里找
			flag = judgeIsSubTree(binaryTree1->rchild,binaryTree2);
	}
	return flag;
}
bool isSubTree(const pBinaryTreeNode& tree1,const pBinaryTreeNode& tree2)
{
	if(nullptr==tree2)
		return true;
	if(nullptr==tree1)
		return false;
	if(tree1->data!=tree2->data)
		return false;
	//如果相等，就要判断子树结点
	return isSubTree(tree1->lchild,tree2->lchild) && isSubTree(tree1->rchild,tree2->rchild);
}
//tree1=889##24##7##7## tree2=89##2##
//1
//tree1=889##34##7##7## tree2=89##2##
//0
//tree1=889##34##7##7## tree2=
//1
//tree1= tree2=89##2##
//0
//请按任意键继续. . .
