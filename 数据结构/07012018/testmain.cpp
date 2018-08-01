#include"Graph.h"
#include"AOE.h"
#include<iostream>
using namespace std;
int main()
{
	meihao::Graph g("data.txt");
	meihao::CriticalPath_AOE(g);
	system("pause");
}
//拓扑排序：0 1 2 3 4 6 5 7 8 9
//etv 0 3 4 12 15 11 24 19 24 27
//ltv 0 7 4 12 15 13 25 19 24 27
//关键路径：<0,2>=4 <2,3>=8 <3,4>=3 <4,7>=4 <7,8>=5 <8,9>=3
//请按任意键继续. . .