#ifndef __AVL_H__
#define __AVL_H__
#include<iostream>
using namespace std;
typedef struct AVL_Node
{
	int data;
	struct AVL_Node* lchild;
	struct AVL_Node* rchild;
	int height;
}AvlNode,*pAvlNode;
int nodeHeight(AvlNode* node);
int max(int a,int b);  //获取结点左右子树最大高度，更新结点高度的时候要用到

AvlNode* AVL_Insert(pAvlNode& root,int key);  //平衡二叉树插入关键字key

static enum avl_delete{deleteError=-1,deleteSuccess} avl_delete_error;
AvlNode* AVL_Delete(pAvlNode& root,int key);  //平衡二叉树删除关键字key
AvlNode* AVL_NodePre(pAvlNode& node);  //找结点前驱
AvlNode* AVL_NodePost(pAvlNode& node);  //找结点后继

AvlNode* LL_Right_Rotate(pAvlNode& root);  //左子树的左子树插入关键字导致不平衡，顺时针旋转
AvlNode* RR_Left_Rotate(pAvlNode& root);  //右子树的右子树插入关键字导致不平衡，逆时针旋转
AvlNode* LR_Left_Right_Rotate(pAvlNode& root);  //左子树的右子树插入关键字导致不平衡，先根结点的左子树逆时针旋转，再根结点顺时针旋转
AvlNode* RL_Right_Left_Rotate(pAvlNode& root);  //右子树的左子树插入关键字导致不平衡，先根结点的右子树顺时针旋转，再根结点逆时针旋转

void preorderTraversal(const pAvlNode& root);  
#endif