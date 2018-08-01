#ifndef __DFS_H__
#define __DFS_H__
#include"Graph.h"
namespace meihao
{
	void DFS(const meihao::Graph& g,int vi,bool*& visited);  //参数，图和顶点数组中某个顶点的下标
	void DFSTraversal(const meihao::Graph& g);
};
#endif