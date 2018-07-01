#include"AOV.h"
#include<stack>
namespace meihao
{
	void initDataStruct(const meihao::Graph& g,vertexNode*& vertexArr)
	{
		int vertexNum = g.getGraphVertexNumber();
		vertexArr = new vertexNode[vertexNum]();  //建立顶点数组
		for(int idx=0;idx!=vertexNum;++idx)
		{
			vertexArr[idx].data = idx;
			vertexArr[idx].in = g.getInputDegree(idx);  //获取入度
			vertexArr[idx].firstEdge = nullptr;
		}
		for(int idx=0;idx!=vertexNum;++idx)
		{
			for(int iidx=0;iidx!=vertexNum;++iidx)
			{
				if(1==g.getGraphEdgeWeight(idx,iidx))
				{
					edgeNode* tmp = new edgeNode();
					tmp->vertexIdx = iidx;
					tmp->next = vertexArr[idx].firstEdge;
					vertexArr[idx].firstEdge = tmp;
				}
			}
		}
	}
	
	int TopologicalSort_AOV(const meihao::Graph& g)
	{
		stack<int> zeroInputDegreeVertex;
		int vertexNum = g.getGraphVertexNumber();
		vertexNode* vertexArr = nullptr;  //建立顶点表数组
		initDataStruct(g,vertexArr);  //建立顶点边和对应的边表
		for(int idx=0;idx!=vertexNum;++idx)
		{
			if(0==vertexArr[idx].in)
			{
				zeroInputDegreeVertex.push(idx);
			}
		}
		//遍历输出拓扑排序
		int cnt = 0;  //统计拓扑排序输出的点数，如果cnt最后不等于图的顶点数，说明不是AOV
		while(!zeroInputDegreeVertex.empty())
		{
			int idx = zeroInputDegreeVertex.top();
			cout<<vertexArr[idx].data<<" ";  //输出一个度为0的顶点
			zeroInputDegreeVertex.pop();
			++cnt;
			for(edgeNode* node = vertexArr[idx].firstEdge;nullptr!=node;node=node->next)
			{//删除了一个度为0的顶点，对应其出边表中的顶点的入得要减1
				
				vertexArr[node->vertexIdx].in--;
				if( 0==(vertexArr[node->vertexIdx].in) )
					zeroInputDegreeVertex.push( node->vertexIdx );
			}
		}
		if(vertexNum==cnt)
			return 0;
		else 
			return -1;
	}
};