#include"Graph.h"
#include<iostream>
#include"Dijkstra.h"
using namespace std;
int main()
{
	meihao::Graph g("data.txt");
	int vertexCnt = g.getGraphVertexNumber();
	int* pathPre = new int[vertexCnt]();
	weight_vaule_type* weight = new weight_vaule_type[vertexCnt]();
	meihao::ShortestPath_Dijkstra(g,pathPre,weight,vertexCnt);
	for(int idx=0;idx!=vertexCnt;++idx)
	{
		meihao::printShortestPath(0,idx,pathPre,vertexCnt);
		cout<<"路径权值："<<weight[idx];
		cout<<endl;
	}
	cout<<endl;
	cout<<"图的起始顶点0到终点8的最短路径：";
	meihao::printShortestPath(0,8,pathPre,vertexCnt);
	cout<<"  路径权值："<<weight[8]<<endl;
	delete []pathPre;
	delete []weight;
}
//0 路径权值：0
//0 1 路径权值：1
//0 1 2 路径权值：4
//0 1 2 4 3 路径权值：7
//0 1 2 4 路径权值：5
//0 1 2 4 5 路径权值：8
//0 1 2 4 3 6 路径权值：10
//0 1 2 4 3 6 7 路径权值：12
//0 1 2 4 3 6 7 8 路径权值：16
//
//图的起始顶点0到终点8的最短路径：0 1 2 4 3 6 7 8   路径权值：16
