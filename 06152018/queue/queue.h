#ifndef __QUEUE_H__
#define __QUEUE_H__
#include<iostream>
#include<string>
using namespace std;
//队列判空和判满
//头尾指针相同为空
//尾指针指向下一个可存放数据的单元，如果尾指针偏移一个单元和头指针相同，队列为满
template<class T,int num>
class queue
{
        public:
                queue();
                ~queue();
                bool empty();
                bool full();
                bool push(T elem);
                bool pop(T& tmp);
                int size();
        private:
                int _front;
                int _real;
                T _arr[num];
};
template<class T,int num>
queue<T,num>::queue():_front(0),_real(0){}

template<class T,int num>
queue<T,num>::~queue(){}

template<class T,int num>
bool queue<T,num>::empty()
{
        return _front == _real;
}

template<class T,int num>
bool queue<T,num>::full()
{
        return _front == (_real+1)%num;
}

template<class T,int num>
bool queue<T,num>::push(T elem)
{
        if(!full())
        {
                _arr[_real] = elem;
                _real = (_real+1)%num;
                return true;
        }
        else
                return false;
}

template<class T,int num>
bool queue<T,num>::pop(T &tmp)
{
        if(!empty())
        {
                tmp = _arr[_front];
                _front = (_front+1)%num;
                return true;
        }
        else
                return false;
}

template<class T,int num>
int queue<T,num>::size()
{
        return (_real-_front+num)%num;
}
#endif