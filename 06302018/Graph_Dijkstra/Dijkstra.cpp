#include"Dijkstra.h"
namespace meihao
{
	void ShortestPath_Dijkstra(const meihao::Graph& g,int* pathPre,weight_vaule_type* weight,int vertexCnt)
	{
		if(nullptr==pathPre||nullptr==weight||0==vertexCnt)
			return ;
		//定义一个数组标记每个结点是否已经在最短路径中
		int* isInShortestPath = new int[vertexCnt]();  //初始为0，表示都还没有在最短路径之中
		//默认从图中第0个结点开始，初始化weight，表示0到其他结点的最短路径
		for(int idx=0;idx!=vertexCnt;++idx)
		{
			weight[idx] = g.getGraphEdgeWeight(0,idx);   //weight[idx]存放的就是0到idx的权值
			pathPre[idx] = 0;  //weight最开始用0到对应下标的距离来初始化，所以pathPre只能全部是0了
		}
		//计算V0到其他结点的最短路径
		isInShortestPath[0] = 1; 
		for(int idx=1;idx!=vertexCnt;++idx)  //V0已经在路径中，只要从下一个顶点开始
		{
			int min = max_weight_value;
			int nextShortestPathVertex = 0;  //下一个可以加到最短路径上的顶点
			//开始遍历weight数组找到一条从V0顶点到对应数组小标顶点的最有最小权值的边，并记录边的另一端顶点
			for(int iidx=0;iidx!=vertexCnt;++iidx)
			{
				if(0==isInShortestPath[iidx]&&
					weight[iidx]<min)
				{
					nextShortestPathVertex = iidx;
					min = weight[iidx];
				}
			}
			//找到了个可以加入到最短路径的顶点
			isInShortestPath[nextShortestPathVertex] = 1;  //修改nextShortestPathVertex为1
			//得到了一个点，通过这个点可以到一些其他顶点，这是后可能路径又会有变化
			//加入nextShortestPathVertex，更新weight数组
			for(int iiidx=0;iiidx!=vertexCnt;++iiidx)
			{
				/*if(0==isInShortestPath[iiidx]&&
					(weight[nextShortestPathVertex]+g.getGraphEdgeWeight(nextShortestPathVertex,iiidx))<weight[iiidx])  */   
				//这里错误的原因是有的weigth是weight_vaule_type能表示的最大值，再加就溢出了
				if(0==isInShortestPath[iiidx] &&
					 g.getGraphEdgeWeight(nextShortestPathVertex,iiidx) !=max_weight_value &&     //多一个条件，防止溢出，也就是(nextShortestPathVertex,iiidx)之间有边的顶点
					 (weight[nextShortestPathVertex]+g.getGraphEdgeWeight(nextShortestPathVertex,iiidx) ) < weight[iiidx] )

				//如果新加入最短路径的点到其他没有标记到最短路径中的点idx的权值小于之前某点到idx的权值，就可以更新这个权值
				{
					weight[iiidx] = weight[nextShortestPathVertex]+g.getGraphEdgeWeight(nextShortestPathVertex,iiidx);
					pathPre[iiidx] = nextShortestPathVertex;
				}
			}
		}
	}

	void printShortestPath(int vi,int vj,int* pathPre,int vertexCnt)
	{
		if(nullptr==pathPre||0==vertexCnt||vi<0||vj<0||vi>vj||vi>=vertexCnt||vj>=vertexCnt)
			return ;
		if(vi==vj)
		{
			cout<<vi<<" ";
			return ;
		}
		printShortestPath(vi,pathPre[vj],pathPre,vertexCnt);
		cout<<vj<<" ";
	}
};