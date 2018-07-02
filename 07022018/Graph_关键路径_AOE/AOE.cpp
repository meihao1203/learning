#include"AOE.h"
namespace meihao
{
	void initDataStruct(const meihao::Graph& g,vertexNode*& vertexArr)
	{
		int vertexNum = g.getGraphVertexNumber();
		vertexArr = new VertexNode[vertexNum]();  //顶点数组开辟空间
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
				if(0!=g.getGraphEdgeWeight(idx,iidx))
				{
					edgeNode* tmp = new edgeNode();
					tmp->vertexIdx = iidx;
					tmp->weight = g.getGraphEdgeWeight(idx,iidx);
					tmp->next = vertexArr[idx].firstEdge;
					vertexArr[idx].firstEdge = tmp;
				}
			}
		}
	}

	int TopologicalSort_AOV(const meihao::Graph& g,vertexNode*& vertexArr,int* etv,stack<int>& AOV)
	{
		if(!AOV.empty())
			return -1;   //传递来的AOV必须是空的
		stack<int> zeroInputDegreeVertex;
		int vertexNum = g.getGraphVertexNumber();
		vertexArr = nullptr;
		initDataStruct(g,vertexArr);

		//入度为0的顶点入栈
		for(int idx=0;idx!=vertexNum;++idx)
		{
			if(0==vertexArr[idx].in)
				zeroInputDegreeVertex.push(idx);
		}
		//初始化elv,每个顶点的最早开始时间,全部为0
		for(int idx=0;idx!=vertexNum;++idx)
		{
			etv[idx] = 0;
		}
		//遍历输出拓扑排序
		int cnt = 0;
		cout<<"拓扑排序：";
		while(!zeroInputDegreeVertex.empty())
		{
			int idx = zeroInputDegreeVertex.top();
			cout<<vertexArr[idx].data<<" "; //输出一个度为0的顶点
			zeroInputDegreeVertex.pop();
			AOV.push(idx);  //保存结果
			++cnt;
			for(edgeNode* node = vertexArr[idx].firstEdge;nullptr!=node;node=node->next)
			{
				if( (etv[idx]+node->weight) >
					 etv[node->vertexIdx] )
				{ //从第一个入度为0的点，也就是源点，就可以开始计算从源点出发可以到达的点的elv了
					etv[node->vertexIdx] = etv[idx]+node->weight;
				}
				--(vertexArr[node->vertexIdx].in);
				if(0==vertexArr[node->vertexIdx].in)
					zeroInputDegreeVertex.push(node->vertexIdx);  
				//这里比较特殊，node->vertexIdx == vertexArr[node->vertexIdx].data
			}
		}
		cout<<endl;
		if(cnt==vertexNum)
			return 0;
		else 
			return -1;
	}

	void CriticalPath_AOE(const meihao::Graph& g)
	{
		int vertexNum = g.getGraphVertexNumber();
		stack<int> AOV;
		int* etv = new int[vertexNum];  //顶点表示的事件的最早开始时间数组
		vertexNode* vertexArr = nullptr;
		int ret = TopologicalSort_AOV(g,vertexArr,etv,AOV);
		if(-1==ret)
		{
			cout<<"TopologicalSort_AOV error!"<<endl;
			return ;
		}
		//根据得到的AOE网的拓扑排序的逆序求ltv,  顶点表示的事件的最晚开始时间数组
		int* ltv = new int[vertexNum];
		for(int idx=0;idx!=vertexNum;++idx)
		{
			ltv[idx] = etv[vertexNum-1];
		}
		while(!AOV.empty())
		{
			int vertexIdx = AOV.top();
			for(edgeNode* node = vertexArr[vertexIdx].firstEdge;nullptr!=node;node=node->next)
			{
				if( ltv[vertexIdx] >
					ltv[node->vertexIdx]-node->weight )
					ltv[vertexIdx] = ltv[node->vertexIdx]-node->weight;
			}
			AOV.pop();
		}
		/* test etv 和 ltv */
		cout<<"etv"<<" ";
		for(int idx=0;idx!=vertexNum;++idx)
		{
			cout<<etv[idx]<<" ";
		}
		cout<<endl;
		cout<<"ltv"<<" ";
		for(int idx=0;idx!=vertexNum;++idx)
		{
			cout<<ltv[idx]<<" ";
		}
		cout<<endl;
		//现在已经得到了etv和ltv了，可以遍历图中所有顶点，根据etv和ltv求出对应顶点之间的活动的ete和lte
		cout<<"关键路径：";
		for(int idx=0;idx!=vertexNum;++idx)
		{//从0号顶点开始，判断0号可以到达其他顶点之间的活动
			for(edgeNode* node=vertexArr[idx].firstEdge;nullptr!=node;node=node->next)
			{
				//ete 活动最早开始时间，<idx,node,vertexIdx>, ete = etv[idx]
				int ete = etv[idx];
				//lte 活动最晚开始时间，<idx,node,vertexIdx>, lte = ltv[node->vertexIdx] - <idx,node,vertexIdx>
				int lte = ltv[node->vertexIdx] - node->weight;
				if(ete==lte)  //相等，关键路径，关键活动
				{
					cout<<"<"<<idx<<","<<node->vertexIdx<<">="<<g.getGraphEdgeWeight(idx,node->vertexIdx)<<" ";
				}
			}
		}
		cout<<endl;
		//释放期间开辟的动态内存
		stack<edgeNode*> edgeNodeAddr;
		for(int idx=0;idx!=vertexNum;++idx)
		{
			for(edgeNode* node=vertexArr[idx].firstEdge;nullptr!=node;node=node->next)
			{
				edgeNodeAddr.push(node);
			}
			while(!edgeNodeAddr.empty())
			{
				delete edgeNodeAddr.top();
				edgeNodeAddr.top() = nullptr;
				edgeNodeAddr.pop();
			}
		}
		for(int idx=0;idx!=vertexNum;++idx)
		{
			delete []vertexArr;
			vertexArr = nullptr;
		}
		delete []etv;
		etv = nullptr;
		delete []ltv;
		ltv = nullptr;
	}
};