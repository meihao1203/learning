#include"DFS.h"
#include"BFS.h"
#include<iostream>
int main()
{
	meihao::Graph g("data.txt");
	meihao::DFSTraversal(g);
	cout<<endl;
	meihao::BFSTraversal(g);
	cout<<endl;
	system("pause");
}
//A B C D E F G H I
//A B F C G I E D H
//请按任意键继续. . .