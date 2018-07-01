#include"AOV.h"
#include"Graph.h"
#include<iostream>
using namespace std;
int main()
{
	meihao::Graph g("data.txt");
	int ret = meihao::TopologicalSort_AOV(g);
	if(0==ret)
		cout<<"success!"<<endl;
	else
		cout<<"fail!"<<endl;
}
//3 1 2 6 0 4 5 8 7 12 9 10 13 11 success!
