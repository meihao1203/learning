#ifndef __stack_h__
#define __stack_h__
#include <iostream>
#include<string>
#include<sstream>
using namespace std;
template <typename T,int num>
class Stack
{
        private:
                int _top;
                T _parr[num];
        public:
                Stack();
                ~Stack();
                bool full();
                bool empty();
                bool push(T elem);
                bool pop(T &);
                int getPos()
                {
                        return _top;
                }
};

template <typename T,int num>
Stack<T,num>::Stack():_top(-1)
{}
template <typename T,int num>
Stack<T,num>::~Stack()
{}
template <typename T,int num>
bool Stack<T,num>::full()
{
        return _top == (num-1);
}
template <typename T,int num>
bool Stack<T,num>::empty()
{
        return _top == -1;
}
template <typename T,int num>
bool Stack<T,num>::push(T elem)
{
        if(!full())
        {
                _parr[++_top] = elem;
                return true;
        }
        return false;
}
template <typename T,int num>
bool Stack<T,num>::pop(T & t)
{
        if(!empty())
        {
                t = _parr[_top--];
                return true;
        }
        else
                return false;
}
#endif
