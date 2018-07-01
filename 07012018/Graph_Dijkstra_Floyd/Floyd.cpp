#include"Floyd.h"
#include<iostream>
namespace meihao
{
	void ShortestPath_Floyd(const meihao::Graph& g,weight_vaule_type** weight,int** pathPre)
	{
		if(nullptr==weight||nullptr==pathPre)
			return ;
		//读取图中数组初始化weight和pathPre
		int vertexCnt = g.getGraphVertexNumber();
		for(int idx=0;idx!=vertexCnt;++idx)
		{
			for(int iidx=0;iidx!=vertexCnt;++iidx)
			{
				weight[idx][iidx] = g.getGraphEdgeWeight(idx,iidx);
				pathPre[idx][iidx] = iidx;
			}
		}
		//开始依次选择中间结点，更新weight和pathPre数组
		//中间结点为0时和初始化的矩阵一样
		for(int idx=1;idx!=vertexCnt;++idx)
		{
			for(int v=0;v!=vertexCnt;++v)
			{
				for(int w=0;w!=vertexCnt;++w)
				{
					if( (max_weight_value!=weight[v][idx] && max_weight_value!=weight[idx][w]) &&  //经过中间结点idx，(v,idx)和(idx,w)都不能是最大值，不然下边的相加判断会溢出
						//max_weight_value是权值weight_vaule_type所能表示的最大值了，再加就溢出
						 weight[v][w]>(weight[v][idx] + weight[idx][w]) )
					{//更新
						weight[v][w] = weight[v][idx] + weight[idx][w];
						pathPre[v][w] = pathPre[v][idx];  //pathPre[v][w] = idx,也就是(v,w)要先到达idx，但是(v,idx)不是一步就到达的，也要先经过pathPre[v][idx]
						//pathPre[v][w] = idx;  //不能写这个，要在前面得到的中间结果的基础之上
					}
				}
			}
		}
	}

	void printPath(int vi,int vj,int vertexCnt,int** pathPre)
	{
		if(vi<0||vj<0||vertexCnt<=0||nullptr==pathPre)
			return ;
		if(vi==vj)
		{
			cout<<vi<<" ";
			return ;
		}	
		int max = vi>=vj?vi:vj;
		int min = vi<vj?vi:vj;
		cout<<min<<" ";  //从最小的起始点开始
		while(min!=max)
		{
			cout<<pathPre[min][max]<<" ";  //第一个要经过的点
			min = pathPre[min][max];  //更新起始顶点
		}
	}
};