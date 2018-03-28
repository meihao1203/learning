 ///
 /// @file    vector.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-28 09:06:40
 ///
 
#include<iostream>
#include"vector.h"
#include<string.h>
using namespace std;
template<typename T>
vector<T>::vector():_elems(new T[1]),_first_free(_elems)
{
	T* tmp = _elems;
	_end = ++tmp;
}
template<typename T>
vector<T>::~vector()
{
	delete _elems;
	_elems = NULL;
}
template<typename T>
int vector<T>::size()
{
	return _first_free-_elems;
}
template<typename T>
int vector<T>::capacity()
{
	return _end-_elems;
}
template<typename T>
void vector<T>::reallocate()
{
	int size = this->size();
	T* tmp = new T[size*2];
	memcpy(tmp,_elems,size*sizeof(T));
	_elems = tmp;
	_first_free = _elems+size;
	_end = (_elems+size*2);
}
template<typename T>
void vector<T>::push_back(const T& elem)
{
	if(this->size()!=this->capacity())
	{
		int i = (_first_free-_elems)/sizeof(T);
		_elems[i] = elem;
		++_first_free;
	}
	else if(this->size()==this->capacity())
	{
		this->reallocate();
		int i = (_first_free-_elems)/sizeof(T);
		_elems[i] = elem;
		++_first_free;
	}
}
template<typename T>
void vector<T>::pop_back()
{
	if(this->size()!=0)
		--_first_free;
}
template<typename T>
typename vector<T>::proxy vector<T>::operator[](int index)
{
	cout<<"cc"<<endl;
	return proxy(*this,index);
}
template<typename T>
T& vector<T>::proxy::operator=(const T elem)
{
	cout<<"BB"<<endl;
	_v::_elems[_index] = elem;
	cout<<"bb"<<endl;
	return _elems[_index];
}
