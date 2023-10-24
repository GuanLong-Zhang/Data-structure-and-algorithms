# include<iostream>
using namespace std;

//˫����
typedef struct dnode
{
	int data;    //������
	struct dnode* prior, * next;   //ָ���� ǰ��ָ��ͺ��ָ��
}dnode,*dlinklist;      //˫����   dnode* �� dlinklist�ȼ�   ��һ��ǿ������һ����� �ڶ���ǿ������һ��˫����

//���²�������Ĭ�ϴ�ͷ����˫����
//��ʼ��˫����
bool initdlinklist3(dlinklist& l)   
{
	l = (dnode*)malloc(sizeof(dnode));  //����һ��ͷ���
	if (l == NULL)   //����ʧ��
	{
		return false;
	}
	l->prior = NULL;   //prior��Զָ���  ͷ����ǰ�����һ��Ϊ��
	l->next = NULL;
	return true;

}

//�ж�˫�����Ƿ�Ϊ��
bool empty3(dlinklist& l)
{
	if (l->next == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}

}

//ָ����������
bool insertnextdnode3(dnode*p,dnode*s)
{
	if (p == NULL || s == NULL)   //�����㲻�Ϸ�
	{
		return false;
	}
	s->next = p->next;
	if (p->next != NULL)   //��ֹp�����һ�����
	{
		p->next->prior = s;
	}
	
	s->prior = p;
	p->next = s;
	return true;
	
}

//ָ�����ǰ�����
//��������˫��������ԣ��ҵ�ָ������ǰ����㣬Ȼ�����ǰ�������к���������
bool insertfrontdnode3(dnode* p, dnode* s)
{
	if (p == NULL || s == NULL)   //�����㲻�Ϸ�
	{
		return false;
	}
	dnode* q;   //����p��ǰ�����
	q = p->prior;
	insertnextdnode3(q, s);
}

//ɾ��ָ�����ĺ�̽��
bool deletenextdnode3(dnode* p)
{
	if (p == NULL)
	{
		return false;
	}
	dnode* q;  //����p�ĺ�̽��
	q = p->next; 
	if (q == NULL)   //��̽�㲻�Ϸ�
	{
		return false;
	}
	p->next = q->next;
	if (q->next != NULL)   //��ֹq�����һ�����
	{
		q->next->prior = p;
	}
	free(q);
	return true;
	
}

//����һ��˫����
void destorydlinklist3(dlinklist& l)
{
	while (l->next != NULL)   //��ָ�벻Ϊ�գ���ִ��ɾ����̽��Ĳ���
	{
		deletenextdnode3(l);   
	}
	free(l);  
	l->next = NULL;   //ͷָ��ָ��NULL

}

//�������˫����
void fornextdlinklist3(dnode* p)
{
	while (p!= NULL)
	{
		cout << p->data << endl;
		p = p->next;
	}
}

//ǰ�����˫����
void forfrontdlinklist3(dnode* p)
{
	while (p != NULL)   //while(p->prior!=NULL)   //ֻҪ����ͷ���Ϳ��Խ��в���������ͷ���
	{
		cout << p->data << endl;
		p = p->prior;
	}

}



//int main()
//{
//	system("pause");
//	return 0;
//
//}