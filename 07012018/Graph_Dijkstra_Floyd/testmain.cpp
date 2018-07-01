#include"Graph.h"
#include<iostream>
#include"Dijkstra.h"
#include"Floyd.h"
#include<iomanip>
using namespace std;
void test0()   //测试Dijkstra
{
	cout<<"test Dijkstra:"<<endl;
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
void test1()  //测试Floyd
{
	cout<<"test Floyd:"<<endl;
	meihao::Graph g("data.txt");
	int vertexCnt = g.getGraphVertexNumber();
	int** pathPre = new int*[vertexCnt]();
	for(int idx=0;idx!=vertexCnt;++idx)
		pathPre[idx] = new int[vertexCnt]();
	weight_vaule_type** weight = new weight_vaule_type*[vertexCnt]();
	for(int idx=0;idx!=vertexCnt;++idx)
		weight[idx] = new weight_vaule_type[vertexCnt];
	meihao::ShortestPath_Floyd(g,weight,pathPre);

	cout<<"print weight matrix:"<<endl;
	for(int idx=0;idx!=vertexCnt;++idx)
	{
		for(int iidx=0;iidx!=vertexCnt;++iidx)
		{
			cout<<setw(3)<<weight[idx][iidx]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"print pathPre matrix:"<<endl;
	for(int idx=0;idx!=vertexCnt;++idx)
	{
		for(int iidx=0;iidx!=vertexCnt;++iidx)
		{
			cout<<setw(3)<<pathPre[idx][iidx]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int idx=0;idx!=vertexCnt;++idx)
	{
		meihao::printPath(0,idx,vertexCnt,pathPre);
		cout<<"路径权值: "<<weight[0][idx]<<endl;
	}
	//释放动态内存
	for(int idx=0;idx!=vertexCnt;++idx)
	{
		delete []pathPre[idx];
		pathPre[idx] = nullptr;
		delete []weight[idx];
		weight[idx] = nullptr;
	}
	delete []pathPre;
	pathPre = nullptr;
	delete []weight;
	weight = nullptr;
}
int main()
{
	test0();
	cout<<endl;
	test1();
}

//test Dijkstra:
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
//
//test Floyd:
//print weight matrix:
//  0   1   4   7   5   8  10  12  16
//  1   0   3   6   4   7   9  11  15
//  4   3   0   3   1   4   6   8  12
//  7   6   3   0   2   5   3   5   9
//  5   4   1   2   0   3   5   7  11
//  8   7   4   5   3   0   7   5   9
// 10   9   6   3   5   7   0   2   6
// 12  11   8   5   7   5   2   0   4
// 16  15  12   9  11   9   6   4   0
//
//print pathPre matrix:
//  0   1   1   1   1   1   1   1   1
//  0   1   2   2   2   2   2   2   2
//  1   1   2   4   4   4   4   4   4
//  4   4   4   3   4   4   6   6   6
//  2   2   2   3   4   5   3   3   3
//  4   4   4   4   4   5   7   7   7
//  3   3   3   3   3   7   6   7   7
//  6   6   6   6   6   5   6   7   8
//  7   7   7   7   7   7   7   7   8
//
//0 路径权值: 0
//0 1 路径权值: 1
//0 1 2 路径权值: 4
//0 1 2 4 3 路径权值: 7
//0 1 2 4 路径权值: 5
//0 1 2 4 5 路径权值: 8
//0 1 2 4 3 6 路径权值: 10
//0 1 2 4 3 6 7 路径权值: 12
//0 1 2 4 3 6 7 8 路径权值: 16
//请按任意键继续. . .
