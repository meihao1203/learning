#include<iostream>
#include"AVL.h"
using namespace std;
#define len 10
int main()
{
	int a[len] = {3,2,1,4,5,6,7,10,9,8};
	cout<<"待插入元素序列：";
	for(int idx=0;idx!=len;++idx)
	{
		cout<<a[idx]<<" ";
	}
	cout<<endl;
	pAvlNode root = nullptr;
	for(int idx=0;idx!=len;++idx)
	{
		root = AVL_Insert(root,a[idx]);  //因为在插入过程中会修改根结点
		if( nullptr == root )
			cout<<"insert "<<a[idx]<<" fail!"<<endl;
	}
	cout<<"中序遍历：";
	preorderTraversal(root);
	cout<<endl;

	for(int idx=0;idx!=len;++idx)
	{
		if( nullptr == AVL_Delete(root,a[idx]) && avl_delete_error ==deleteError )
			cout<<"delete "<<a[idx]<<" fail!"<<endl;
		else
		{
			cout<<"删除"<<a[idx]<<",前序遍历：";
			preorderTraversal(root);
			cout<<endl<<endl;
		}
	}
	system("pause");
}
//待插入元素序列：3 2 1 4 5 6 7 10 9 8
//中序遍历：4（4） 2（2） 1（1） 3（1） 7（3） 6（2） 5（1） 9（2） 8（1） 10（1）
//删除3,前序遍历：4（4） 2（2） 1（1） 7（3） 6（2） 5（1） 9（2） 8（1） 10（1）
//
//删除2,前序遍历：7（4） 4（3） 1（1） 6（2） 5（1） 9（2） 8（1） 10（1）
//
//删除1,前序遍历：7（3） 5（2） 4（1） 6（1） 9（2） 8（1） 10（1）
//
//删除4,前序遍历：7（3） 5（2） 6（1） 9（2） 8（1） 10（1）
//
//删除5,前序遍历：7（3） 6（1） 9（2） 8（1） 10（1）
//
//删除6,前序遍历：9（3） 7（2） 8（1） 10（1）
//
//删除7,前序遍历：9（2） 8（1） 10（1）
//
//删除10,前序遍历：9（2） 8（1）
//
//删除9,前序遍历：8（1）
//
//删除8,前序遍历：
//
//请按任意键继续. . .