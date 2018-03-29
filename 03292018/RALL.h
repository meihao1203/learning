///
/// @file    RALL.h
/// @author  meihao1203(meihao19931203@outlook.com)
/// @date    2018-03-29 16:18:48
///

#include<iostream>
using namespace std;
template<typename T>
class RALL
{
	public:
		RALL(T* p):_p(p){ cout<<"托管资源"<<endl; }
		~RALL()  // 托管资源，可能多个指针指向同一块内存区域，if判断不能发挥作用
		{ 
			if(NULL!=_p)
			{ 
				delete _p;
				_p=NULL; 
			}cout<<"释放资源"<<endl;
		}
		// 资源指针，被托管的都是资源的地址，
		// 所以要重载这些运算符，能够获取
		// 资源的地址
		T* get()const;
		T& operator*()const;
		T* operator->()const;  // 似乎没怎么用到这个

		void reset(T* new_p);  // 更改托管资源地址
		void swap(RALL<T> &rhs);  // 交换地址
	private:
		RALL(const RALL<T>&);  //禁止调用拷贝构造函数
		RALL<T>& operator=(const RALL<T>&);  // 禁止调用赋值构造函数
	private:
		T* _p;  // _p指向被托管的资源
};
template<typename T>
T* RALL<T>::get()const
{
	return _p;
}
template<typename T>
T& RALL<T>::operator*()const
{
	return *_p;
}
template<typename T>
T* RALL<T>::operator->()const
{
	return _p;
}
	template<typename T>
void RALL<T>::reset(T* new_p)
{
	delete _p;
	_p = new_p;
}
	template<typename T>
void RALL<T>::swap(RALL<T> &rhs)
{
	std::swap(_p,rhs._p);
}
