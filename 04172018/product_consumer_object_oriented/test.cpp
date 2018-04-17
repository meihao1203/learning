 ///
 /// @file    test.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-17 10:26:17
 ///
 
#include<iostream>
#include"ProduceThread.h"
#include"ConsumerThread.h"
using namespace std;
int main()
{
	meihao::Buffer buffer(10);
	meihao::Thread* produce = new meihao::ProduceThread(buffer);
	meihao::Thread* consumer = new meihao::ConsumerThread(buffer);

	produce->start();
	consumer->start();

	produce->join();
	consumer->join();

	delete produce;
	delete consumer;
	return 0;
}
//Consumer a num 52
//produce a num 52
//produce a num 44
//Consumer a num 44
//produce a num 25
//produce a num 10
//Consumer a num 25
//produce a num 92
//Consumer a num 10
//Consumer a num 92
