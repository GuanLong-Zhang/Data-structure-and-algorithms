#include<iostream>
using namespace std;

//图的存储
//方法一：邻接矩阵法  顺序存储
# define maxvertexnum 100
# define infinity 2147483647   //使用int型最大值来表示无穷

//定义
typedef struct
{
	char vex[maxvertexnum];   //用于存放元素
	int edge[maxvertexnum][maxvertexnum];   //用于存放关系 不带权值：0表示不邻接 1表示邻接   带权值：权值表示邻接 无穷表示不邻接
	int vexnum, arcnum;     //存放当前图的顶点数和边数
}mgraph;


//方法二：邻接表法  顺序存储+链式存储  类似于树的孩子表示法存储
typedef struct arcnode    //链表
{
	int data;   //指向那个结点的数组下标
	struct arcnode* next;    //指向下一个结点的指针
}arcnode;

typedef struct vnode
{
	char data;    //存放顶点元素
	arcnode* first;   //存放边
}vnode,adjlist[maxvertexnum];   //用数组存放顶点元素和边

typedef struct
{
	adjlist vertices;
	int vexnum, arcnum;
}algraph;

//图的基本操作
//图的遍历 BFS DFS
//图的应用 最小生成树（普利姆算法，克鲁斯卡尔算法） 最短路径（BFS算法，迪杰斯特拉算法，弗洛伊德算法）
//有向无环图拓扑排序，逆拓扑排序
//关键路径


//int main()
//{
//
//	system("pause");
//	return 0;
//}


