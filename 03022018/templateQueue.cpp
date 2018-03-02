///
/// @file    templateQueue.cpp
/// @author  meihao1203(meihao19931203@outlook.com)
/// @date    2018-03-02 12:35:34
///

#include<iostream>
#include<string>
using namespace std;
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
int main()
{
	queue<int,10> q1;
	q1.push(3);
	q1.push(5);
	int tmp;
	cout<<q1.size()<<endl;
	q1.pop(tmp);
	cout<<tmp<<endl;
	cout<<"----------------------"<<endl;
	queue<string,5> q2;
	q2.push("hello");
	q2.push("world");
	cout<<q2.size()<<endl;
	string tmpString;
	q2.pop(tmpString);
	cout<<q2.size()<<"  "<<tmpString<<endl;
	return 0;
}
//2
//3
//----------------------
//2
//1  hello
