#include"Prim.h"
#include<iostream>
namespace meihao
{
	typedef struct Arr
	{
		int vi;  //顶点vi
		weight_vaule_type weight;  //(vi,vj)的权值
	}node,*pNode;
	//思路：
	//从结点0开始，定义n-1个node的数组，分别赋值(0,1),(0,2)...
	void MiniSpanTree_Prim(const meihao::Graph& g)
	{
		//获取顶点个数
		int vertexNum = g.getGraphVertexNumber();
		node* arr = new node[vertexNum]();
		for(int idx=1;idx!=vertexNum;++idx)
		{
			arr[idx].vi = 0;  //选取的初始结点0
			arr[idx].weight = g.getGraphEdgeWeight(0,idx);
		}
		for(int idx=1;idx!=vertexNum;++idx)
		{
			weight_vaule_type min = max_weight_value;
			int newVertex;
			for(int iidx=1;iidx!=vertexNum;++iidx)
			{
				if(0!=arr[iidx].weight&&arr[iidx].weight<min)
				{
					min = arr[iidx].weight;
					newVertex = iidx;
				}
			}
			cout<<"("<<arr[newVertex].vi<<","<<newVertex<<")"<<" ";
			arr[newVertex].weight = 0;
			//更新数组
			for(int iiidx=1;iiidx!=vertexNum;++iiidx)
			{
				if(0!=arr[iiidx].weight&&g.getGraphEdgeWeight(newVertex,iiidx)<arr[iiidx].weight)
				{
					arr[iiidx].vi = newVertex;  
					arr[iiidx].weight = g.getGraphEdgeWeight(newVertex,iiidx);
				}
			}
		}
	}
};
