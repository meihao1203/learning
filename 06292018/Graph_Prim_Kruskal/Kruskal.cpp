#include"Kruskal.h"
#include<iostream>
#include<vector>
#include<algorithm>
namespace meihao
{
	bool cmp(const edges& a,const edges& b)
	{
		return a.weight < b.weight;  //从小到大排序
	}
	void readEgdesFromGraph(const meihao::Graph& g,vector<edges>& edgeArr)
	{//无向图邻接矩阵都是对称的，只读取上三角即可
		int vertexCnt = g.getGraphVertexNumber();
		for(int idx=0;idx!=vertexCnt;++idx)
		{
			for(int iidx=idx;iidx!=vertexCnt;++iidx)
			{
				if(0!=g.getGraphEdgeWeight(idx,iidx)&&max_weight_value!=g.getGraphEdgeWeight(idx,iidx))
				{
					edges tmp;
					tmp.begin = idx;
					tmp.end = iidx;
					tmp.weight = g.getGraphEdgeWeight(idx,iidx);
					edgeArr.push_back(::move(tmp));
				}
			}
		}
		sort(edgeArr.begin(),edgeArr.end(),cmp);  //从小到大排序
	}
	void MiniSpanTree_Kruskal(const meihao::Graph& g)
	{
		vector<edges> edgeArr;  //边集数组
		readEgdesFromGraph(g,edgeArr);
		//定义parent数组，数组下标对应唯一的图结点，数组值对应小标结点的父结点，最小生成树就是一棵树
		int vertexCnt = g.getGraphVertexNumber();
		int* parent = new int[vertexCnt]();  //初始化全部为0，parent[i] = 0,表示i结点没有父结点（根结点）
		int edgeCnt = edgeArr.size();  //边集数组大小，也就是图中边的数量
		for(int idx=0;idx!=edgeCnt;++idx)
		{
			int firstFather = find(parent,edgeArr[idx].begin);
			int secondFather = find(parent,edgeArr[idx].end);
			if(firstFather!=secondFather)  //待加入的这条边的父结点相同，如果再把这条边加入，就会出现环。
			{//这个过程就是一个找爹过程，最小生成树只能有一个根结点，如果待加入边对其两端的顶点去找爹找到相同的，这时候再加入这条边就出现环，∧->△
				parent[firstFather] = secondFather;   //加入该条边，(firstFather,secondFather),firstFather的父结点secondFather
				//输出找到的边
				cout<<"("<<edgeArr[idx].begin<<","<<edgeArr[idx].end<<")"<<" ";
			}
		}
		cout<<endl;
	}
	//int find(int* parent,int vi)
	//{
	//	while(parent[vi]>0)  //vi结点有父结点
	//	{
	//		vi = parent[vi];
	//	}
	//	return vi;
	//}
	int find(int* parent,int vi)
	{//优化
		int viTmp = vi;
		while(parent[vi]>0)  //vi结点有父结点
		{
			vi = parent[vi];  //找父结点
		}
		while(vi!=viTmp)  
		{//vi有父结点，遍历，如果有父结点还有祖先结点，就要说生成树层数，假设eg:0→1→5（0的父结1,1的父亲5） 变成 0→5，1→5
			int tmp = parent[viTmp];  //暂存最初vi结点(0)的父结点(tmp=1)
			parent[viTmp] = vi;  //(parent[0]=5)
			viTmp = tmp;  //0变成1；
		}
		return vi;
	}
};