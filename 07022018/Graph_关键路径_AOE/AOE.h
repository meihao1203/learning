#ifndef __AOE_H__
#define __AOE_H__
#include"Graph.h"
#include<iostream>
#include<stack>
namespace meihao
{
	//边表结点
	typedef struct EdgeNode
	{
		int vertexIdx;  //邻接点域，存放该结点在顶点表数组中的下标
		int weight;  //存放对应顶点到该边表结点的边上的权值
		struct EdgeNode* next;  //存放下一个边表结点的位置
	}edgeNode,*pEdgeNode;

	//顶点表结点
	typedef struct VertexNode
	{
		int in;  //顶点入度
		int data;  //顶点与，存放顶点数据信息
		edgeNode* firstEdge;
	}vertexNode,*pVertexNode;

	void initDataStruct(const meihao::Graph& g,vertexNode*& vertexArr); 
	//根据图来初始化出我们要的顶点数组和对应的边表

	int TopologicalSort_AOV(const meihao::Graph& g,vertexNode*& vertexArr,int* elv,stack<int>& AOV); //成功返回0，失败返回-1
	//在这个过程中计算出elv,并保存这个拓扑排序的逆序
	//这个拓扑排序的逆序后面求关键路径要用来计算ltv

	void CriticalPath_AOE(const meihao::Graph& g);
};
#endif