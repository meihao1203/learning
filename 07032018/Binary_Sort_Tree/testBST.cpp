#include"BST.h"
void test()
{
	int a[10] = {62,88,58,47,35,73,51,99,37,93};
	pBstNode root = nullptr;  //建立二叉搜索树
	for(int idx=0;idx!=10;++idx)
	{
		BST_Insert(root,a[idx]);
	}
	for(int idx=0;idx!=10;++idx)
	{
		bstNode* ret = BST_Search(root,a[idx]);
		if(nullptr!=ret)
			cout<<ret->data<<" ";
	}
	cout<<endl;
	cout<<"二叉排序树的三种遍历："<<endl;
	cout<<"前序遍历：";
	preorderTraversal_BST(root);
	cout<<endl;
	cout<<"中序遍历：";
	inorderTraversal_BST(root);
	cout<<endl;
	cout<<"后序遍历：";
	postorderTraversal_BST(root);
	cout<<endl<<endl;

	for(int idx=0;idx!=10;++idx)
	{
		cout<<"删除"<<a[idx]<<endl;
		int ret = BST_Delete(root,a[idx]);
		if(-1==ret)
			cout<<"BST_Delete "<<a[idx]<<" fail!"<<endl;
		cout<<"前序遍历：";
		preorderTraversal_BST(root);
		cout<<endl;
		cout<<"中序遍历：";
		inorderTraversal_BST(root);
		cout<<endl;
		cout<<"后序遍历：";
		postorderTraversal_BST(root);
		cout<<endl;
	}
	cout<<endl;
}
int main()
{
	test();
}
//62 88 58 47 35 73 51 99 37 93 
//二叉排序树的三种遍历：
//前序遍历：62 58 47 35 37 51 88 73 99 93 
//中序遍历：35 37 47 51 58 62 73 88 93 99 
//后序遍历：35 37 47 51 58 73 88 93 99 62 
//
//删除62
//前序遍历：58 47 35 37 51 88 73 99 93 
//中序遍历：35 37 47 51 58 73 88 93 99 
//后序遍历：35 37 47 51 73 88 93 99 58 
//删除88
//前序遍历：58 47 35 37 51 73 99 93 
//中序遍历：35 37 47 51 58 73 93 99 
//后序遍历：35 37 47 51 73 93 99 58 
//删除58
//前序遍历：51 47 35 37 73 99 93 
//中序遍历：35 37 47 51 73 93 99 
//后序遍历：35 37 47 73 93 99 51 
//删除47
//前序遍历：51 35 37 73 99 93 
//中序遍历：35 37 51 73 93 99 
//后序遍历：35 37 73 93 99 51 
//删除35
//前序遍历：51 37 73 99 93 
//中序遍历：37 51 73 93 99 
//后序遍历：37 73 93 99 51 
//删除73
//前序遍历：51 37 99 93 
//中序遍历：37 51 93 99 
//后序遍历：37 93 99 51 
//删除51
//前序遍历：37 99 93 
//中序遍历：37 93 99 
//后序遍历：93 99 37 
//删除99
//前序遍历：37 93 
//中序遍历：37 93 
//后序遍历：93 37 
//删除37
//前序遍历：93 
//中序遍历：93 
//后序遍历：93 
//删除93
//前序遍历：
//中序遍历：
//后序遍历：
//
