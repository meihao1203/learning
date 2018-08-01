#include"AVL.h"
#include<iostream>
using namespace std;

//height,当根结点为空，height=0,一个结点=1,根结点等价数的层数
int AvlTreeHeight(AvlNode* root)
{
	return (nullptr==root)? 0 : (root->height);
}
//求最大值
int max(int a,int b)
{
	return a>b?a:b;
}
//LL 左子树插入或删除结点导致左子树不平衡，要右旋转，返回旋转调整后的树根结点
pavlNode LL_Right_Rotate(pavlNode& root)
{
	if(nullptr==root)
		return nullptr;
	//定义一个指针指向root的左子树
	AvlNode* left = root->lchild;
	root->lchild = left->rchild;
	left->rchild = root;
	//此时根结点变为left
	//调整树的每个结点的高度

	root->height = max(AvlTreeHeight(root->lchild),AvlTreeHeight(root->rchild)) + 1;  //加一是自身节点
	left->height = max(AvlTreeHeight(left->lchild),root->height) + 1;

	return left;  //新的根结点
}
//RR 右子树插入或删除结点导致右子树不平衡，要左旋转，返回调整后的树根结点
pavlNode RR_Left_Rotate(pavlNode& root)
{
	if(nullptr==root)
		return nullptr;
	AvlNode* right = root->rchild;
	root->rchild = right->lchild;
	right->lchild = root;

	root->height = max(AvlTreeHeight(root->lchild),AvlTreeHeight(root->rchild)) + 1;
	right->height = max(AvlTreeHeight(right->rchild),root->height) + 1;
	
	return right;
}
//LR 左子树的右子树插入或删除结点导致不平衡，也就是左子树和左子树的右子树平衡因子一正一负
//先左子树的右子树左旋转，然后左子树右旋转
pavlNode LR_Left_Right_Rotate(pavlNode& root)
{
	root->lchild = RR_Left_Rotate(root->lchild);  //获得旋转后的根结点，前面一定要补货最后旋转玩后的root->lchild
	return LL_Right_Rotate(root);
}
//RL 右子树的左子树插入或删除结点导致不平衡，也就是右子树和右子树的左子树平衡因子一负一正
//先右子树的左子树右旋转，然后右子树坐旋转
pavlNode RL_Right_Left_Rotate(pavlNode& root)
{
	root->rchild = LL_Right_Rotate(root->rchild);
	return RR_Left_Rotate(root);
}

//AVL树插入一个结点
//思路：如果树为空，直接插入，最后计算树的高度并返回根结点地址
//不空，采用递归，新结点只能插入到树的最后，插入完后计算新结点的高度，
//递归层层返回，每返回一层就计算当前根结点的左右子树高度差，也就是上一次递归返回的时候就算的，发现不平衡（高度>1）
//说明从当前结点开始的子树即不平衡了，立即旋转调整，判断是在当前子树的左边还是右边插入的，采取合适的旋转策略
pavlNode AvlTreeInsertNode(pavlNode& root,int key)
{
	if(nullptr==root)
	{
		root = new AvlNode();
		if(nullptr==root)
		{
			cout<<"new 开辟AvlNode空间失败"<<endl;
			return nullptr;
		}
		root->height = 0;   //初始为0，函数最后会计算更新
		root->key = key;
		root->lchild = root->rchild = nullptr;
	}
	else if(key<root->key)  //比根结点小，左子树寻找
	{
		root->lchild = AvlTreeInsertNode(root->lchild,key);  //递归寻找
		//递归返回，判断子树还是不是平衡的了
		//因为只在左子树插入的，只会增加左子树的高度,对右子树没有影响
		if(2 == AvlTreeHeight(root->lchild) - AvlTreeHeight(root->rchild))  //模拟递归的层层嵌套，从在叶子结点插入新结点的位置回溯，这里不用加取绝对值运算的，不会出现负数
		{
			//LL，左子树的左子树插入引起不平衡  BF 2 1 LL
			if(key<root->lchild->key)
				root = LL_Right_Rotate(root);  //旋转调整，返回新的根结点
			else  //BF 2 -1   没有Bf 2 0的情况
				root = LR_Left_Right_Rotate(root);  
		}
	}
	else if(key>=root->key)  //大于根结点，在右子树插入
	{
		root->rchild = AvlTreeInsertNode(root->rchild,key);
		if(2==AvlTreeHeight(root->rchild) - AvlTreeHeight(root->lchild))
		{
			//RR BF -2 -1
			if(key>root->rchild->key)
				root = RR_Left_Rotate(root);
			else //RL BF -2 1
				root = RL_Right_Left_Rotate(root);
		}
	}
	//else if(key==root->key)
	//{
	//	cout<<"该关键字存在，禁止插入"<<endl;
	//	return root;
	//}
	root->height = max(AvlTreeHeight(root->lchild),AvlTreeHeight(root->rchild)) + 1;  //最后这里才能计算更新height,因为递归返回的时候回旋转跳转子树
	return root;
}


//思路：和插入操作一样，递归寻找要删除的结点，
//如果关键字有左右子树，根据左右子树的高度，选择高度高的一遍的相应结点替换要删除的关键字，
//比如左子树高，就选左子树的最右结点，也就是关键字的前驱
//右子树高，就选右子树的最左结点，也就是关键字的后继
//替换之后再在对应的子树里面删除刚用来替换的结点
//如果左右子树不是存在，则选择不为空的一个直接替换
//删除完最后还要更新高度
pavlNode AvlTreeDeleteNode(pavlNode& root,int key)
{
	AvlTreeDeleteNodeErrorFlag = delFalse;
	if(nullptr==root)
	{
		AvlTreeDeleteNodeErrorFlag = delTrue;   //如果是最后一个结点删除，也会返回nullptr，所以加一个错误标志
		return nullptr;
	}
	if(key<root->key)
	{
		root->lchild = AvlTreeDeleteNode(root->lchild,key);
		//如果左子树删除导不平衡,左子树删除可能导致和右子树不平衡
		//如果不平衡，是右子树的右子树太高导致的还是右子树的左子树左子树导致的
		if(2==AvlTreeHeight(root->rchild) - AvlTreeHeight(root->lchild))
		{//在左子树删掉的，只能右子树高于左子树2
		 //动态调整root->rchild
		 //判断右子树的左右子树高度，决定是RL还是RR
			if( AvlTreeHeight(root->rchild->lchild) <= AvlTreeHeight(root->rchild->rchild) )
			{//RR,右边高->平衡因子负 先左旋转 root=-2,root->rchild->lchild = -1  一负负，RR_Left_Rotate  或者BF -2 0
				root = RR_Left_Rotate(root);  
			}
			else
			{//RL  root=-2,root->rchild->lchild = 1  只有这种情况才是RL
				root = RL_Right_Left_Rotate(root);
			}
		}
	}
	else if(key>root->key)
	{
		root->rchild = AvlTreeDeleteNode(root->rchild,key);
		if(2==AvlTreeHeight(root->lchild) - AvlTreeHeight(root->rchild))
		{
			if( AvlTreeHeight(root->lchild->lchild) >= AvlTreeHeight(root->lchild->rchild) )
			{//LL  BF 2 1 BF 2 0
				root = LL_Right_Rotate(root);
			}
			else 
			{//LR  BF 2 -1
				root = LR_Left_Right_Rotate(root);
			}
		}
	}
	else if(key==root->key)
	{//找到，删除
		if(root->lchild!=nullptr && root->rchild!=nullptr)
		{//左右子树都不空，只能选当前结点的前驱或者后继来替换，然后删了这个前驱或后继
		 //为了保持平衡，一般选当前要删除结点的左右子树中较高的一方
			if(AvlTreeHeight(root->lchild) > AvlTreeHeight(root->rchild))
			{//左子树中找前驱
				AvlNode* delNode = AvlTreeNodePre(root->lchild,key);
				root->key = delNode->key;  //修改替换数值
				//左子树中删除delNode
				root->lchild = AvlTreeDeleteNode(root->lchild,delNode->key);
			}
			else 
			{
				AvlNode* delNode = AvlTreeNodePost(root->rchild,key);
				root->key = delNode->key;
				root->rchild = AvlTreeDeleteNode(root->rchild,delNode->key);
			}
		}
		else //删除结点至少有一边没有孩子
		{
			AvlNode* tmp = root;
			root = nullptr==root->lchild ? root->rchild : root->lchild;
			delete tmp;
			tmp = nullptr;
		}
	}
	//更新结点高度
	if(nullptr!=root) //删除只有一个结点的特殊情况
	{
		root->height = ( max( AvlTreeHeight(root->lchild) , AvlTreeHeight(root->rchild) ) ) + 1;
	}
	return root;
}

AvlNode* AvlTreeNodePre(pavlNode root,int key)
{
	if(nullptr==root)
		return nullptr;
	while(nullptr!=root->rchild)
		root = root->rchild;
	return root;
}
AvlNode* AvlTreeNodePost(pavlNode root,int key)
{
	if(nullptr==root)
		return nullptr;
	while(nullptr!=root->lchild)
		root = root->lchild;
	return root;
}
void preorderTraversalAVL(const pavlNode& root)
{
	if(nullptr==root)
		return ;
	cout<<root->key<<"（"<<root->height<<"）"<<" ";
	preorderTraversalAVL(root->lchild);
	preorderTraversalAVL(root->rchild);
}
void inorderTraversalAVL(const pavlNode& root)
{
	if(nullptr==root)
		return ;
	inorderTraversalAVL(root->lchild);
	cout<<root->key<<"（"<<root->height<<"）"<<" ";
	inorderTraversalAVL(root->rchild);
}

void AvlTreeDestroy(pavlNode& root)
{
	if(nullptr==root)
		return ;
	if(nullptr!=root->lchild)
		AvlTreeDestroy(root->lchild);
	if(nullptr!=root->rchild)
		AvlTreeDestroy(root->rchild);
	delete root;
	root = nullptr;
}