#include"BFS.h"
#include<queue>
namespace meihao
{
	void BFSTraversal(const meihao::Graph& g)
	{//广度优先遍历相当于层序遍历
		queue<int> rootNode;  //存放图的顶点
		bool* visited = new bool[g.getGraphVertexNumber()];
		for(int idx=0;idx!=g.getGraphVertexNumber();++idx)
		{
			visited[idx] = false;
		}
		for(int idx=0;idx!=g.getGraphVertexNumber();++idx)
		{
			if(false==visited[idx])  //如果该结点没有访问到
			{
				//访问
				cout<<g.getGraphVertexData(idx)<<" ";
				visited[idx] = true;
				rootNode.push(idx);
				while(!rootNode.empty())  //把刚刚访问到的结点的下一层结点访问并入队列
				{
					for(int iidx=0;iidx!=g.getGraphVertexNumber();++iidx)
					{
						if(1==g.getGraphEdgeWeight(rootNode.front(),iidx)&&
							false==visited[iidx])
						{
							cout<<g.getGraphVertexData(iidx)<<" ";
							visited[iidx] = true;
							rootNode.push(iidx);
						}
					}
					rootNode.pop();  //最先访问的一个结点出队列
				}
			}
		}
	}
};