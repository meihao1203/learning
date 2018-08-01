#include"DFS.h"
namespace meihao
{
	void DFS(const meihao::Graph& g,int vi,bool*& visited)
	{
		visited[vi] = true;  //修改第vi个结点的访问标记为true
		cout<<g.getGraphVertexData(vi)<<" ";
		for(int idx=0;idx!=g.getGraphVertexNumber();++idx)
		{
			if(1==g.getGraphEdgeWeight(vi,idx)&&
				false==visited[idx])  //如果(vi,idx)之间存在边（==1），并且第idx个顶点还没有访问过
			{
				DFS(g,idx,visited);  //递归遍历第idx个顶点
			}
		}
	}
	void DFSTraversal(const meihao::Graph& g)
	{
		bool* visited = new bool[g.getGraphVertexNumber()];
		for(int idx=0;idx!=g.getGraphVertexNumber();++idx)
		{
			visited[idx] = false;  //初始化访问标记，全部为false，表示未访问
		}
		for(int idx=0;idx!=g.getGraphVertexNumber();++idx)
		{
			if(false==visited[idx])  //随便选一个点，如果未访问过，就从它开始深度优先遍历
				DFS(g,idx,visited);
		}
	}
};