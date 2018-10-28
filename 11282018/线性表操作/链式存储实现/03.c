//将两个有序线性表合并为一个
#if 0
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node* next;
}node,*pNode;
node* mergeOrderList(pNode* list1,pNode* list2)
{
	node* list = NULL;
	node* cur = list;
	if((*list1) == NULL)
		return (*list2);
	if((*list2) == NULL)
		return (*list1);
	while(*list1 != NULL && *list2 != NULL)
	{
		if((*list1)->data>(*list2)->data)
		{
			if(list==NULL)
			{
				list = (*list2);
				cur = list;
			}
			else
			{
				cur->next = (*list2);
				cur = cur->next;
			}	
			(*list2) = (*list2)->next;
		}
		else
		{
			if(list==NULL)
			{
				list = (*list1);
				cur = list;
			}
			else
			{
				cur->next = (*list1);
				cur = cur->next;
			}	
			(*list1) = (*list1)->next;
		}
	}
	if((*list1)==NULL)
		cur->next = (*list2);
	else
		cur->next = (*list1);
	return list;
}
void printList(pNode head)
{
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head = head->next;
	}
	printf("\n");
}
void test()
{
	//建立链表
	//list1：1->3->5
	//list2：2->4
	node* list1 = NULL;
	node* list2 = NULL;
	node* node1 = (node*)malloc(sizeof(node));
	node* node2 = (node*)malloc(sizeof(node));
	node* node3 = (node*)malloc(sizeof(node));
	node* node4 = (node*)malloc(sizeof(node));
	node* node5 = (node*)malloc(sizeof(node));
	node1->data = 1;

	node2->data = 3;

	node3->data = 5;

	node4->data = 2;

	node5->data = 4;
	list1 = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	list2 = node4;
	node4->next = node5;
	node5->next = NULL;

	//合并
	list1 = mergeOrderList(&list1,&list2);
	printList(list1);
}
int main()
{
	test();
	system("pause");  //stdlib.h
}
#endif
//1 2 3 4 5
//请按任意键继续. . .