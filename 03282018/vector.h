 ///
 /// @file    vector.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-27 19:28:15
 ///
 
#include<iostream>
#include<string>
using namespace std;
template<typename T>
class vector
{
	class proxy;
	public:
		vector();
		~vector();
		
		void push_back(const T&);
		void pop_back();
		
		proxy operator[](int index);

		int size();
		int capacity();

		void reallocate();  // 重新分配内存，动态扩容
	private:
		T* _elems;  // 指向数组中的第一个元素
		T* _end;  // 指向数组本身之后的元素
		T* _first_free;  // 指向最后一个实际元素之后的那个元素

		class proxy
		{
			public:
				proxy(vector<T> v,int index):_v(v),_index(index){}
				T& operator=(const T elem);
				operator T(){  return _elems[_index];  }
			private:
				vector<T>& _v;
				int _index;
		};
};
// Vector模型
//  ______________________________
// |_|_|_|_|_|____________________|
// ↑         ↑                   ↑
// _elems   _first_free            _end

