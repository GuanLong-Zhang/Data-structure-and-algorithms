#include<iostream>
using namespace std;

//ͼ�Ĵ洢
//����һ���ڽӾ���  ˳��洢
# define maxvertexnum 100
# define infinity 2147483647   //ʹ��int�����ֵ����ʾ����

//����
typedef struct
{
	char vex[maxvertexnum];   //���ڴ��Ԫ��
	int edge[maxvertexnum][maxvertexnum];   //���ڴ�Ź�ϵ ����Ȩֵ��0��ʾ���ڽ� 1��ʾ�ڽ�   ��Ȩֵ��Ȩֵ��ʾ�ڽ� �����ʾ���ڽ�
	int vexnum, arcnum;     //��ŵ�ǰͼ�Ķ������ͱ���
}mgraph;


//���������ڽӱ�  ˳��洢+��ʽ�洢  ���������ĺ��ӱ�ʾ���洢
typedef struct arcnode    //����
{
	int data;   //ָ���Ǹ����������±�
	struct arcnode* next;    //ָ����һ������ָ��
}arcnode;

typedef struct vnode
{
	char data;    //��Ŷ���Ԫ��
	arcnode* first;   //��ű�
}vnode,adjlist[maxvertexnum];   //�������Ŷ���Ԫ�غͱ�

typedef struct
{
	adjlist vertices;
	int vexnum, arcnum;
}algraph;

//ͼ�Ļ�������
//ͼ�ı��� BFS DFS
//ͼ��Ӧ�� ��С������������ķ�㷨����³˹�����㷨�� ���·����BFS�㷨���Ͻ�˹�����㷨�����������㷨��
//�����޻�ͼ������������������
//�ؼ�·��


//int main()
//{
//
//	system("pause");
//	return 0;
//}


