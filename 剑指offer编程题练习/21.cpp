//题目21：定义栈的数据结构，在该类型中实现一个能够得到栈的最小元素的min函数。
//在该栈中，调用min,push及pop的时间复杂度都是O(1)。
//思路：注意一点，如果最小元素弹出栈了，那你还怎么找次小元素
//该类型，就要用模板了
//定义一个辅助栈，元素进栈的时候，如果是第一个入栈元素，这个元素也压入辅助栈
//不是第一个入栈元素，如果这个元素小于等于辅助栈中的栈顶元素，那么这个元素也压入辅助栈，这样即使发生弹栈了，
//如果弹栈元素也和辅助栈中的栈顶元素相同，那么辅助栈也同步弹出。这样辅助栈的栈顶永远是栈中的最小元素
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
template<class T>
class StackWithMin
{
public:
	void myPush(T elem);
	void myPop();
	T Min()const;
private:
	stack<T> _stack;  //原始栈
	stack<T> _assist;  //辅助栈，保存栈中最小值
};
template<class T>
void StackWithMin<T>::myPush(T elem)
{
	_stack.push(elem);
	if(_assist.size()==0||_assist.top()>=elem)
		_assist.push(elem);
}
template<class T>
void StackWithMin<T>::myPop()
{
	if(!_stack.empty())
	{
		int tmp = _stack.top();
		_stack.pop();
		if(tmp==_assist.top())
		{
			_assist.pop();
		}
	}
}
template<class T>
T StackWithMin<T>::Min()const
{
	if(!_assist.empty())
		return _assist.top();
}
int main()
{
	StackWithMin<int> test;
	test.myPush(3);
	cout<<test.Min()<<endl;
	test.myPush(4);
	cout<<test.Min()<<endl;
	test.myPush(2);
	test.myPush(1);
	cout<<test.Min()<<endl;
	test.myPop();
	cout<<test.Min()<<endl;
	test.myPop();
	cout<<test.Min()<<endl;
	test.myPush(0);
	cout<<test.Min()<<endl;
	system("pause");
}
