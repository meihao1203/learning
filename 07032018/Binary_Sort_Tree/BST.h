#ifndef __BST_H__
#define __BST_H__
#include<iostream>
using namespace std;
typedef struct Binary_Sort_Tree
{
	int data;
	struct Binary_Sort_Tree* lchild,*rchild;
}bstNode,*pBstNode;

void BST_Insert(pBstNode& root,int data);  //二叉排序树中插入结点
bstNode* BST_Search(pBstNode root,int key);  //二叉排序树中查找关键字key

int deleteNode(bstNode*& node);  //删除节点node,形参为待删除节点的地址本身
int BST_Delete(pBstNode& root,int key);   //二叉树删除关键字key  //成功返回


/*  二叉搜索树的三种遍历  */
void preorderTraversal_BST(const pBstNode& root);
void inorderTraversal_BST(const pBstNode& root);
void postorderTraversal_BST(const pBstNode& root);
 



#endif