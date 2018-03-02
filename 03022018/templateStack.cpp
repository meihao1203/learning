 ///
 /// @file    templateStack.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-02 11:06:30
 ///
 
#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;
template<class T,int num>
class stack
{
	public:
		stack();
		~stack();
		bool empty();
		bool full();
		bool push(T elem);
		bool pop(T &);  // 模板定义stack,所以不能直接取值,要根据具体类型传引用来得到栈顶值
		int size();
		int getTop();  
	private:
		int _top;
		T _arr[num];
};
template<class T,int num>
stack<T,num>::stack():_top(-1){}
template<class T,int num>
stack<T,num>::~stack(){}
template<class T,int num>
bool stack<T,num>::empty()
{
	return _top == -1;
}
template<class T,int num>
bool stack<T,num>::full()
{
	return _top == num-1;
}
template<class T,int num>
bool stack<T,num>::push(T elem)
{
	if(!full())
	{
		_arr[++_top] = elem;
		return true;
	}
	return false;
}
template<class T,int num>
bool stack<T,num>::pop(T &elem)
{
	if(!empty())
	{
		elem = _arr[_top--];
		return true;
	}
	return false;
}
template<class T,int num>
int stack<T,num>::size()
{
	return _top+1;
}
template<class T,int num>
int stack<T,num>::getTop()
{
	return _top;
}
int main()
{
	stack<int,10> s1;
	s1.push(1);
	s1.push(2);
	cout<<s1.size()<<" "<<s1.getTop()<<endl;
	cout<<"-------------------------------"<<endl;
	stack<string,5> s2;
	s2.push("hello");
	s2.push("world");
	cout<<s2.size()<<endl;
	string tmp;
	s2.pop(tmp);
	cout<<tmp<<endl;
	return 0;
}
//2 1
//-------------------------------
//2
//world
