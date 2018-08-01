#ifndef __KRUSCAL_H__
#define __KRUSCAL_H__
#include"Graph.h"
namespace meihao
{
	typedef struct EdgeSetArr  //边集数组
	{
		int begin;  //边起点
		int end;    //边终点
		weight_vaule_type weight;  //边权值
	}edges;
	void readEgdesFromGraph(const meihao::Graph& g);  //从图中读出我们需要的边集数组
	int find(int* parent,int vi);
	void MiniSpanTree_Kruskal(const meihao::Graph& g);
};
#endif