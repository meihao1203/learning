#include"AVL.h"
int nodeHeight(AvlNode* node)
{
	if(nullptr==node)
		return 0;
	else 
		return node->height;
}

int max(int a,int b)
{
	return a>b ? a : b;
}

AvlNode* LL_Right_Rotate(pAvlNode& root)
{
	if(nullptr==root)
		return nullptr;
	AvlNode* tmp = root->lchild;
	root->lchild = tmp->rchild;
	tmp->rchild = root;
	root->height = max( nodeHeight(root->lchild),nodeHeight(root->rchild) ) + 1;
	tmp->height = max( nodeHeight(tmp->lchild),nodeHeight(root) ) + 1;
	return tmp;
}

AvlNode* RR_Left_Rotate(pAvlNode& root)
{
	if(nullptr==root)
		return nullptr;
	AvlNode* tmp = root->rchild;
	root->rchild = tmp->lchild;
	tmp->lchild = root;
	root->height = max( nodeHeight(root->lchild),nodeHeight(root->rchild) ) + 1;
	tmp->height = max( nodeHeight(root),nodeHeight(root->rchild) ) + 1;
	return tmp;
}

AvlNode* LR_Left_Right_Rotate(pAvlNode& root)
{
	if(nullptr==root)
		return nullptr;
	root->lchild = RR_Left_Rotate(root->lchild);  //root->lchild可能更改，所以要用返回的最新值更新
	root = LL_Right_Rotate(root);
	return root;
}

AvlNode* RL_Right_Left_Rotate(pAvlNode& root)
{
	if(nullptr==root)
		return nullptr;
	root->rchild = LL_Right_Rotate(root->rchild);
	root = RR_Left_Rotate(root);
	return root;
}

AvlNode* AVL_Insert(pAvlNode& root,int key)
{
	if(nullptr==root)
	{
		root = new AvlNode();
		root->data = key;
		root->height = 1;
		root->lchild = root->rchild = nullptr;
	}
	else if(key<root->data)
	{//左子树插入
		root->lchild = AVL_Insert(root->lchild,key);  //插入的过程中会跳转树结构，所以要用返回的值来更新root->lchild
		if(nodeHeight(root->lchild)-nodeHeight(root->rchild)==2)
		{
			if(key<root->lchild->data)  //左子树的左子树插入引起不平衡
				root = LL_Right_Rotate(root);
			else 
				root = LR_Left_Right_Rotate(root);
		}
	}
	else if(key>root->data)
	{//右子树插入
		root->rchild = AVL_Insert(root->rchild,key);
		if(nodeHeight(root->rchild)-nodeHeight(root->lchild)==2)  
		{
			if(key>root->rchild->data) //右子树的右子树插入
				root = RR_Left_Rotate(root);
			else 
				root = RL_Right_Left_Rotate(root);
		}
	}
	else if(key==root->data)
	{
		cout<<"same key,can not insert!"<<endl;
		return nullptr;
	}
	//更新结点高度
	root->height = max( nodeHeight(root->lchild),nodeHeight(root->rchild) ) + 1;
	return root;
}

void preorderTraversal(const pAvlNode& root)
{
	if(nullptr==root)
		return ;
	cout<<root->data<<"（"<<root->height<<"）"<<" ";
	preorderTraversal(root->lchild);
	preorderTraversal(root->rchild);
}

AvlNode* AVL_Delete(pAvlNode& root,int key)
{
	avl_delete_error = deleteSuccess;
	if(nullptr==root)
	{
		avl_delete_error = deleteError;   //空结点，删除失败
		return nullptr;
	}
	else if(key<root->data)
	{
		root->lchild = AVL_Delete(root->lchild,key);  //在左子树中删除
		if(nodeHeight(root->rchild)-nodeHeight(root->lchild)==2)
		{
			if(nodeHeight(root->rchild->lchild)>nodeHeight(root->rchild->rchild))  // -2 1
				root = RL_Right_Left_Rotate(root);
			else 
				root = RR_Left_Rotate(root);
		}
	}
	else if(key>root->data)
	{
		root->rchild = AVL_Delete(root->rchild,key);
		if(nodeHeight(root->lchild)-nodeHeight(root->rchild)==2)
		{
			if(nodeHeight(root->lchild->lchild)<nodeHeight(root->lchild->rchild))
				root = LR_Left_Right_Rotate(root);	
			else 
				root = LL_Right_Rotate(root);
		}
	}
	else if(key==root->data)
	{
		//如果左右子树都存在，用前驱或者后继来替换，在删除这个前驱或后继
		if(nullptr!=root->lchild&&nullptr!=root->rchild)
		{
			if(nodeHeight(root->lchild)>nodeHeight(root->rchild))
			{
				AvlNode* pre = AVL_NodePre(root->lchild);
				root->data = pre->data;
				root->lchild = AVL_Delete(root->lchild,pre->data);
			}
			else 
			{
				AvlNode* post = AVL_NodePost(root->rchild);
				root->data = post->data;
				root->rchild = AVL_Delete(root->rchild,post->data);
			}
		}
		else
		{
			AvlNode* tmp = root;
			root = nullptr==root->lchild ? root->rchild : root->lchild;
			delete tmp;
			tmp = nullptr;
		}
	}
	//更新高度
	if(nullptr!=root)
		root->height = max(nodeHeight(root->lchild),nodeHeight(root->rchild)) + 1;
	return root;
}
AvlNode* AVL_NodePre(pAvlNode& node)
{
	if(nullptr==node)
		return nullptr;
	while(node->rchild!=nullptr)
		node = node->rchild;
	return node;
}
AvlNode* AVL_NodePost(pAvlNode& node)
{
	if(nullptr==node)
		return nullptr;
	while(node->lchild!=nullptr)
		node = node->lchild;
	return node;
}