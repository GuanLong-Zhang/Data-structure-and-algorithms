#include<iostream>
using namespace std;

//ѭ������    ѭ�������� ѭ��˫����

//ѭ��������   ���һ������ָ��ָ��ͷ���
typedef struct lnode   
{
	int data;   //������
	struct lnode* next;  //ָ���� 
}lnode, * linklist;      // lnode *l  linklist l  

//lnode *ǿ������һ�����  linklistǿ������һ��������


//��ʼ��һ��ѭ��������  ��ͷ���
bool initlist4(linklist& l)
{
	l = (lnode*)malloc(sizeof(lnode));   //������һ��ͷ���ռ�
	if (l == NULL)    //�������ʧ�ܣ�����false
	{
		return false;
	}
	l->next = l;   //ͷ���ָ��ָ��ͷ���   �����ڵ�������ָ��NULL
	return true;

}

//�ж�ѭ���������Ƿ�Ϊ��  ��ͷ���
bool empty4(linklist& l)
{
	if (l->next == l)    //ͷ����ָ����ͷ��㣬˵��ѭ��������Ϊ��
	{
		return true;
	}
	else
	{
		return false;
	}
}

//�жϽ��p�Ƿ���ѭ��������ı�β���
bool istail4(linklist& l, lnode* p)
{
	if (p->next == l)    //���ָ��ָ��ͷ��㣬˵���Ǳ�β���
	{
		return true;
	}
	else
	{
		return false;
	}
}

//ѭ��˫����   ���һ�����ĺ���ָ��ָ��ͷ��㣬ͷ����ǰ��ָ��ָ�����һ�����
typedef struct dnode
{
	int data;    //������
	struct dnode* prior, * next;   //ָ���� ǰ��ָ��ͺ��ָ��
}dnode, * dlinklist;      //˫����   dnode* �� dlinklist�ȼ�   ��һ��ǿ������һ����� �ڶ���ǿ������һ��˫����

//���²�������Ĭ�ϴ�ͷ����˫����
//��ʼ��ѭ��˫����
bool initdlinklist4(dlinklist& l)
{
	l = (dnode*)malloc(sizeof(dnode));  //����һ��ͷ���
	if (l == NULL)   //����ʧ��
	{
		return false;
	}
	l->prior = l;   //ͷ����ǰ��ָ��ͺ���ָ�붼ָ��ͷ��㣬������˫�����NULL�������γɱջ�
	l->next = l;
	return true;

}

//�ж�ѭ��˫�����Ƿ�Ϊ��
bool empty4(dlinklist& l)
{
	if (l->next == l)
	{
		return true;
	}
	else
	{
		return false;
	}

}

//�жϽ��p�Ƿ���ѭ��˫����ı�β���
bool istail4(dlinklist& l, dnode* p)
{
	if (p->next == l)    //���ָ��ָ��ͷ��㣬˵���Ǳ�β���
	{
		return true;
	}
	else
	{
		return false;
	}
}

//������˫����Ĳ����ɾ����ѭ��˫������Ҫ������һ���������жϣ�
//��Ϊ���һ�����ĺ����㲻��NULL������ɾ��ʱ����ֱ�ӽ��в�����



//int main()
//{
//
//	system("pause");
//	return 0;
//}