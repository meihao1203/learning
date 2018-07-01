#ifndef __AOV_H__
#define __AOV_H__
#include<iostream>
#include"Graph.h"
namespace meihao
{
	//边表结点
	typedef struct EdgeNode
	{
		int vertexIdx;  //邻接点域，存放该结点在顶点表数组中的下标
		struct EdgeNode* next;  //存放下一个边表结点的位置
	}edgeNode,*pEdgeNode;

	//顶点表结点
	typedef struct VertexNode
	{
		int in;  //顶点入度
		int data;  //顶点与，存放顶点数据信息
		edgeNode* firstEdge;
	}vertexNode,*pVertexNode;

	void initDataStruct(const meihao::Graph& g,vertexNode*& vertexArr);  //根据图来初始化出我们要的顶点数组和对应的边表
	
	int TopologicalSort_AOV(const meihao::Graph& g);  //成功返回0，失败返回-1
};
#endif