//�����Ա���ɾ������ֵ�ظ���Ԫ��
#if 0
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node* next;
}node,*pNode;
node* delNode(pNode* head,pNode del)
{  //������ɾ��ָ�����del������������ͷ���
	node* cur = *head;
	if(head==NULL||del==NULL)
	{
		if(head==NULL)
			return NULL;
		else
			return *head;
	}
	//���Ҫɾ������ͷ���
	if( (*head) == del )
	{
		*head = (*head)->next;
		free(del);
		del = NULL;
		return *head;
	}
	//ɾ����ͷ���
	while(cur != NULL)
	{
		if(cur->next == del)
		{
			cur->next = cur->next->next;
			free(del);
			del = NULL;
			break;
		}
		cur = cur->next;
	}
	return *head;
}
node* delRepeat(pNode* head)
{
	node* phead = (*head);
	node* cur = phead;
	int tmp = 0;
	int flag = 0;
	if(NULL == (*head))
		return NULL;
	//�ҳ��ظ���Ԫ�أ�Ȼ��ɾ��
	while(phead != NULL)
	{  
		cur = phead->next;
		tmp = phead->data;
		flag = 0;
		while(cur != NULL)
		{  //�ظ�Ԫ��ȫ����Ϊ-1�����ɾ�������е�-1���
			if(tmp == -1)
				break;
			else if(cur->data == tmp)
			{
				flag = 1;
				cur->data = -1;
			}	
			cur = cur->next;
		}
		if(flag)
			phead->data = -1;
		phead = phead->next;
	}
	phead = (*head);
	cur = phead;
	while(cur != NULL)
	{
		if(cur->data == -1)
		{
			phead = delNode(head,cur);
			cur = phead;
		}
		else
			cur = cur->next;
	}
	return phead;
}
node* buildList()
{
	//��������
	//2->1->3->5->2
	node* head = NULL;
	node* node1 = (node*)malloc(sizeof(node));
	node* node2 = (node*)malloc(sizeof(node));
	node* node3 = (node*)malloc(sizeof(node));
	node* node4 = (node*)malloc(sizeof(node));
	node* node5 = (node*)malloc(sizeof(node));
	node1->data = 2;

	node2->data = 1;

	node3->data = 3;

	node4->data = 5;

	node5->data = 2;
	head = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;
	return head;
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
	node* head = buildList();
	head = delRepeat(&head);
	printList(head);
}
int main()
{
	test();
	system("pause");  //stdlib.h
}
#endif
//1 3 5
//�밴���������. . .