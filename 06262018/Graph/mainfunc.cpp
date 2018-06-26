#include"Graph.h"
int main()
{
	meihao::Graph g("data.txt");
	cout<<"图顶点数："<<g.getGraphVertexNumber()<<endl;
	cout<<"图顶点矩阵："<<endl;
	g.printVertexMatrix();
	g.printGraphEdgeMatrix();

	cout<<"点A的入度："<<g.getInputDegree(0)<<endl;
	cout<<"点A的出度："<<g.getOutDegree(0)<<endl;

	cout<<"(A,C)="<<g.getGraphEdgeWeight(1,2)<<endl;

	cout<<"set (C,D)=5"<<endl;
	g.setGraphEdgeWeight(2,3,5);

	cout<<"(C,D)="<<g.getGraphEdgeWeight(2,3)<<endl;

}
//图顶点数：4
//图顶点矩阵：
//A B C D
//0 1 1 1
//1 0 1 0
//1 1 0 1
//1 0 1 0
//
//点A的入度：3
//点A的出度：3
//(A,C)=1
//set (C,D)=5
//(C,D)=5
//请按任意键继续. . .
