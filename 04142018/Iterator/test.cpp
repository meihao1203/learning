 ///
 /// @file    test.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-14 15:16:07
 ///
 
// 提供一种方法顺序访问一个聚合对象中各个元素,,而又不需暴露该对象的内部表示.  
#include<iostream>
#include"iterator.h"
using namespace std;
int main()
{
	Aggregate* pAggregate = new ConcreteAggregate(5);
	Iterator* pIterator = pAggregate->createIterator();
	for(;false==pIterator->isDone();pIterator->next())
	{
		cout<<pIterator->currentItem()<<"  ";
	}
	cout<<endl<<endl;

	Iterator* it1 = pAggregate->begin();  // 建一个产品类指针，指向工厂类造的一个对象
	// 内部实现就是it1指向上面创建的数组的开头ConcreteIterator(this,0);
	Iterator* it2 = pAggregate->end();
	for(;(*it1)!=(*it2);++(*it1))
	{
		cout<<*(*it1)<<endl;
	}
	delete pAggregate;
	delete pIterator;
	return 0;
}
//Aggregate()
//ConcreteAggregate()
//ConcreteIterator(Aggregate*,int)
//1  2  3  4  5  
//
//ConcreteIterator(Aggregate*,int)
//ConcreteIterator(Aggregate*,int)
//~ConcreteAggregate()
//~Aggregate()
//~ConcreteIterator()
//~Iterator()
