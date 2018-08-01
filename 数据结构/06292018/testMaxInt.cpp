#include"Graph.h"
#include"Prim.h"
#include"Kruskal.h"
#include<iostream>
using namespace std;
int main()
{
	meihao::Graph g("data.txt");
	cout<<"MiniSpanTree_Prim:"<<endl;
	meihao::MiniSpanTree_Prim(g);
	cout<<endl<<endl;
	cout<<"MiniSpanTree_Kruskal:"<<endl;
	meihao::MiniSpanTree_Kruskal(g);
	cout<<endl;
	system("pause");
}
//MiniSpanTree_Prim:
//(0,1) (0,5) (1,8) (8,2) (1,6) (6,7) (7,4) (7,3)
//
//MiniSpanTree_Kruskal:
//(4,7) (2,8) (0,1) (0,5) (1,8) (1,6) (3,7) (6,7)
//
//请按任意键继续. . .