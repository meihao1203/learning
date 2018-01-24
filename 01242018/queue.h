 ///
 /// @file    queue.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-01-24 18:10:52
 ///
 
#ifndef __QUEUE_H__
#define __QUEUE_H__
#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct NODE
{
	int data;
	struct NODE* next;
}node,*pnode;
class queue
{
	public:
		queue()
		{
			_head = NULL;
			_tail = NULL;
		}
		~queue()
		{
			if(NULL!=_head)
			{
				_head = _head->next;
				free(_head);
			}
			_tail = NULL;
		}
		void push(int element)
		{
			pnode tmp = (pnode)calloc(1,sizeof(node));
			tmp->data = element;
			if(_head==NULL&&_tail==NULL)
			{
				_head = tmp;
				_tail = tmp;
			}
			else
			{
				_tail->next = tmp;
				_tail = tmp;
			}
		}
		void pop()
		{
			if(_head==_tail&&_head!=NULL)
			{
				pnode tmp = _head;
				_head = _tail = NULL;
				free(tmp);
			}
			else if(_head!=NULL)
			{
				pnode tmp = _head;
				_head = _head->next;
				free(tmp);
			}
			else
			{
				cout<<"pop fail!"<<endl;
			}
		}
		int front()
		{
			if(NULL==_head)
			{
				cout<<"empty queue!"<<endl;
				return -1;
			}
			return _head->data;
		}
		int back()
		{
			if(NULL==_tail)
			{
				cout<<"empty queue!"<<endl;
				return -1;
			}
			return _tail->data;
		}
		bool empty()
		{
			if(_head!=NULL)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		bool full()
		{
			return false;
		}
	private:
		pnode _head;
		pnode _tail;
};
#endif
