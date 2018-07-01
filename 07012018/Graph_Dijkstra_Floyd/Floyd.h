#ifndef __FLOYD_H__
#define __FLOYD_H__
#include"Graph.h"
#include<iostream>
namespace meihao
{
	void ShortestPath_Floyd(const meihao::Graph& g,weight_vaule_type** weight,int** pathPre);
	//weight相当于D数组，pathPre相当于P数组
	void printPath(int vi,int vj,int vertexCnt,int** pathPre);
	//打印vi到vj的最短路径
};
#endif