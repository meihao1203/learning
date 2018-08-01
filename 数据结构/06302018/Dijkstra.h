#ifndef __DIJKSTRA_H__
#define __DIJKSTRA_H__
#include"Graph.h"
namespace meihao
{
	void ShortestPath_Dijkstra(const meihao::Graph& g,int* pathPre,weight_vaule_type* weight,int vertexCnt);  //参数pathPre数组是用来存放计算得到到图中某一点的最短路径前驱
	//pathPre[2] = 1,表示V2到V1的最短路径中,V2前面一个点是V1, ...V1->V2...
	//weight是存放指定的一个开始遍历的到对应数组小标的点的权值。eg:图中起始的点V0，weight[2] = N,表示V0到V2的最短路径权值和为N
	
	//定义一个函数输出指定两点之间的最短路径和权值和
	void printShortestPath(int vi,int vj,int* pathPre,int vertexCnt);
};
#endif