#include"Graph.h"
#include"Prim.h"
#include<iostream>
using namespace std;
int main()
{
	meihao::Graph g("data.txt");
	meihao::MiniSpanTree_Prim(g);
	cout<<endl;
	system("pause");
}