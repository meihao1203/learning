//题目26：实现函数ComplexListNode* Clone(ComplexListNode* pHead);复制一个复杂链表。
//		复杂链表中，每个节点除了有一个m_pNext指针指向下一个结点外，还有一个m_pSibling指向链表中的任意
//		结点或者NULL。
//思路：保证时间复杂度O(n),并且空间复杂度O(1);
//		分三步，第一个复制结点和m_pNext,同时把复制的结点链接到被赋值节点之后
//		第二步：复制m_pSibling
//      前两步得到的链表拆分成两个，奇数点得到的是原始链表，偶数点得到的是复制后的链表
#if 0
#include<iostream>
#include<stack>
typedef struct node
{
	int m_nValue;
	node* m_pNext;
	node* m_pSibling;
}*ComplexList,ComplexListNode;
using namespace std;
ComplexListNode* createNode(int m_value);
void buildNode(ComplexListNode* node,ComplexListNode* next,ComplexListNode* sibling);  //设置每个节点的指针 
void printList(ComplexList head);

ComplexListNode* Clone(ComplexListNode* pHead);
void CloneNodes(ComplexListNode* pHead);  //第一步
void ConnectSiblingNodes(ComplexListNode* pHead);  //第二步
ComplexListNode* ReturnNewList(ComplexListNode* pHead);  //第三步
//都是拷贝，就不用传链表头指针的地址
void printList(ComplexList head);
void test1();
void test2();  //sibling指向自己
void test3();  //sibling成环
void test4();  //空指针
int main()
{
	test1();
	cout<<endl<<endl;
	test2();
	cout<<endl<<endl;
	test3();
	cout<<endl<<endl;
	test4();
	system("pause");
}
void test1()
{
/*
	   _______
      ▽     |
	1->2->3->4->5
	|__|__△
	   |________△	 
*/
	ComplexListNode* node1 = createNode(1);
	ComplexListNode* node2 = createNode(2);
	ComplexListNode* node3 = createNode(3);
	ComplexListNode* node4 = createNode(4);
	ComplexListNode* node5 = createNode(5);
	buildNode(node1,node2,node3);
	buildNode(node2,node3,node5);
	buildNode(node3,node4,NULL);
	buildNode(node4,node5,node2);
	buildNode(node5,NULL,NULL);
	ComplexList head= node1;
	printList(head);
	ComplexList cloneList = Clone(head);
	printList(cloneList);
}
void test2()
{
/*
	   _______
       ▽     |
	1->2->3->4->5
	|  △
	|_____△  
*/
	ComplexListNode* node1 = createNode(1);
	ComplexListNode* node2 = createNode(2);
	ComplexListNode* node3 = createNode(3);
	ComplexListNode* node4 = createNode(4);
	ComplexListNode* node5 = createNode(5);
	buildNode(node1,node2,node3);
	buildNode(node2,node3,node2);
	buildNode(node3,node4,NULL);
	buildNode(node4,node5,node2);
	buildNode(node5,NULL,NULL);
	ComplexList head= node1;
	printList(head);
	ComplexList cloneList = Clone(head);
	printList(cloneList);
}
void test3()
{
/*
         ________
	   ▽______ |
       ▽     | |
	1->2->3->4->5   
	|  |_____△
	|_____△  
*/
	ComplexListNode* node1 = createNode(1);
	ComplexListNode* node2 = createNode(2);
	ComplexListNode* node3 = createNode(3);
	ComplexListNode* node4 = createNode(4);
	ComplexListNode* node5 = createNode(5);
	buildNode(node1,node2,node3);
	buildNode(node2,node3,node4);
	buildNode(node3,node4,NULL);
	buildNode(node4,node5,node2);
	buildNode(node5,NULL,node4);
	ComplexList head= node1;
	printList(head);
	ComplexList cloneList = Clone(head);
	printList(cloneList);

}
void test4()
{
	ComplexList head= NULL;
	printList(head);
	ComplexList cloneList = Clone(head);
	printList(cloneList);
}
void printList(ComplexList head)
{
	if(NULL==head)
		return ;
	while(head!=NULL)
	{
		cout<<head->m_nValue;
		if(head->m_pSibling!=NULL)
			cout<<"("<<head->m_pSibling->m_nValue<<")"<<" -> ";
		else
			cout<<"(NULL)"<<" -> ";
		head = head->m_pNext;
	}
	cout<<"NULL"<<endl;
}
ComplexListNode* createNode(int m_value)
{
	ComplexListNode* node = new ComplexListNode;
	node->m_nValue = m_value;
	node->m_pNext = NULL;
	node->m_pSibling = NULL;
	return node;
}
void buildNode(ComplexListNode* node,ComplexListNode* next,ComplexListNode* sibling)
{
	node->m_pNext = next;
	node->m_pSibling = sibling;
}
void CloneNodes(ComplexListNode* pHead)
{
	if(NULL==pHead)
		return ;
	ComplexListNode* pCurNode = pHead;
	while(pCurNode!=NULL)
	{
		ComplexListNode* pCloneNode = new ComplexListNode;
		pCloneNode->m_nValue = pCurNode->m_nValue;
		pCloneNode->m_pNext = pCurNode->m_pNext;
		pCloneNode->m_pSibling = NULL;  //这个第二步再设置
		pCurNode->m_pNext = pCloneNode;
		pCurNode = pCloneNode->m_pNext;
	}
}
void ConnectSiblingNodes(ComplexListNode* pHead)
{
	if(NULL==pHead)
		return ;
	ComplexListNode* pCurNode = pHead;
	ComplexListNode* pCloneNode = NULL;
	while(pCurNode!=NULL)
	{
		pCloneNode = pCurNode->m_pNext;
		if(pCurNode->m_pSibling!=NULL)
			pCloneNode->m_pSibling = pCurNode->m_pSibling->m_pNext;
		pCurNode = pCloneNode->m_pNext;
	}
}
ComplexListNode* ReturnNewList(ComplexListNode* pHead)
{ //拆分链表，奇数结点和偶数结点
	if(NULL==pHead)
		return NULL;
	ComplexListNode* pCurNode = pHead;
	ComplexListNode* pCloneHead = NULL;
	ComplexListNode* pCloneNode = NULL;
	if(pCurNode!=NULL)
	{//最先初始化复制链表头结点
		pCloneHead = pCloneNode = pCurNode->m_pNext;  
	 //pCurNode向前偏移
		pCurNode->m_pNext = pCloneNode->m_pNext;
		pCurNode = pCloneNode->m_pNext;
	}
	while(pCurNode!=NULL)
	{
		pCloneNode->m_pNext = pCurNode->m_pNext;
		pCloneNode = pCurNode->m_pNext;
		pCurNode->m_pNext = pCloneNode->m_pNext;
		pCurNode = pCloneNode->m_pNext;
	}
	return pCloneHead;
}
ComplexListNode* Clone(ComplexListNode* pHead)
{
	CloneNodes(pHead);
	ConnectSiblingNodes(pHead);
	ComplexListNode* newList = ReturnNewList(pHead);
	return newList;
}
#endif
//1(3) -> 2(5) -> 3(NULL) -> 4(2) -> 5(NULL) -> NULL
//1(3) -> 2(5) -> 3(NULL) -> 4(2) -> 5(NULL) -> NULL
//
//
//1(3) -> 2(2) -> 3(NULL) -> 4(2) -> 5(NULL) -> NULL
//1(3) -> 2(2) -> 3(NULL) -> 4(2) -> 5(NULL) -> NULL
//
//
//1(3) -> 2(4) -> 3(NULL) -> 4(2) -> 5(4) -> NULL
//1(3) -> 2(4) -> 3(NULL) -> 4(2) -> 5(4) -> NULL