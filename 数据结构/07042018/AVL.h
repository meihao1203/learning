#ifndef __AVL_H__
#define __AVL_H__

typedef struct AVLTreeNode
{
	int key;
	int height;  //结点高度，用来计算当前结点为根结点的子树是不是平衡的
	struct AVLTreeNode* lchild;
	struct AVLTreeNode* rchild;
}AvlNode,*pavlNode;

//height,当根结点为空，height=0,一个结点=1,根结点等价数的层数
int AvlTreeHeight(AvlNode* root);

//求最大值
int max(int a,int b);

pavlNode LL_Right_Rotate(pavlNode& root);

pavlNode LR_Left_Right_Rotate(pavlNode& root);

pavlNode RL_Right_Left_Rotate(pavlNode& root);

pavlNode AvlTreeInsertNode(pavlNode& root,int key);

AvlNode* AvlTreeNodePre(pavlNode root,int key);  //找子树前驱，也就是最右结点，最大值结点

AvlNode* AvlTreeNodePost(pavlNode root,int key);  //找子树后继，也就是最左结点，最小值结点

static enum errorFlag{delFalse=0,delTrue} AvlTreeDeleteNodeErrorFlag;
pavlNode AvlTreeDeleteNode(pavlNode& root,int key);

AvlNode* AvlTreeNodePre(pavlNode root,int key);

AvlNode* AvlTreeNodePost(pavlNode root,int key);

void preorderTraversalAVL(const pavlNode& root);

void inorderTraversalAVL(const pavlNode& root);

void AvlTreeDestroy(pavlNode& root);
#endif