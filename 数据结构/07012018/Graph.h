#ifndef __GRAPH_H__
#define __GRAPH_H__
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#define graph_value_type int   //图顶点的数据类型
#define weight_vaule_type int
#define max_weight_value 0x7FFFFFFF   //默认int类型是signed int,0XFFFFFFFF 计算机看是负数，存补码，0X10000001 = -1
namespace meihao
{
	//图中临界矩阵都动态申请空间
	using namespace std;
	static bool graph_error = false;
	class Graph
	{
	public:
		Graph(const string& fileName):_vertexNum(0)
			,_vertex(nullptr)
			,_arc(nullptr)
		{
			readGraphFromFile(fileName);
		}
		~Graph();
		void printVertexMatrix()const;
		void printGraphEdgeMatrix()const;
		int getGraphVertexNumber()const;
		weight_vaule_type getGraphEdgeWeight(int vi,int vj)const;
		graph_value_type getGraphVertexData(int vi)const;  //获取第vi个顶点的值
		int setGraphEdgeWeight(int vi,int vj,int weight);  //修改边的权值
		int getOutDegree(int vi)const;  //获取某一个顶点的出度
		int getInputDegree(int vi)const;  //获取某一个顶点的入度
	protected:
		void readGraphFromFile(const string& fileName);
		void writeGraphFromFile(const string& fileName);
	private:
		int _vertexNum;  //图的顶点数
		graph_value_type* _vertex;   //顶点数组
		weight_vaule_type** _arc;      //邻接矩阵,边数组
	};
};
#endif