#include<iostream>
using namespace std;

//������
typedef struct lnode   //���������е�һ�����
{
	int data;   //������
	struct lnode* next;  //ָ���� ָ����һ�����
}lnode, *linklist;      // lnode *l  linklist l   ���ߵȼ۶��Ǳ�ʾָ�������һ������ָ��

//lnode *ǿ������һ�����  linklistǿ������һ��������

//��ʼ��һ��������  ����ͷ���
bool initlist2(linklist& l)
{
	l = NULL;    //ͷָ���ÿ�
	return true;
}

//��ʼ��һ��������  ��ͷ���
bool initlist2_1(linklist& l)
{
	l = (lnode*)malloc(sizeof(lnode));   //������һ��ͷ���ռ�
	if (l == NULL)    //�������ʧ�ܣ�����false
	{
		return false;
	}
	l->next = NULL;   //ͷ���ָ����һ������ÿ�   ͷ���������Ϊ��,���ǲ���ͷ���������
	return true;

}


//�жϵ������Ƿ�Ϊ��  ����ͷ���
bool empty2(linklist& l)
{
	if (l == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//�жϵ������Ƿ�Ϊ��  ��ͷ���
bool empty2_1(linklist& l)
{
	if (l->next == NULL)    //��һ��ͷ�������������ǿյģ������п�ֻ��Ҫ�жϵ�һ��ͷ���ָ�����Ƿ�Ϊ�վͿ�����
	{
		return true;
	}
	else
	{
		return false;
	}
}

//�ڵ�i��λ�ò���Ԫ��e   ����ͷ���  i = 1 2 3 4 5 6 ...  ��Ҫ�ڵ�һ��λ��������������
bool listinsert2(linklist& l, int i, int e)
{
	if (i < 1)   //����λ�ò��Ϸ�
	{
		return false;
	}
	if (i == 1)   //���⴦������ͷ����ڵ�һ��λ����Ҫ����һ����㵥��������,����ͷָ��û��next
	{
		lnode* s = (lnode*)malloc(sizeof(lnode));
		s->data = e;
		s->next = l;  //ͷָ�븳��s
		l = s;
	}

	lnode* p;
	p = l;
	int j = 1;   //pָ��ĳ�ʼ���λ�ã�û��ͷ��㣬����λ��Ϊ1����1����㣬ע��˴���1Ϊ����1
	while (p != NULL && j < i - 1)   //Ҫ�ڵ�i��λ�ò���Ԫ�أ���ô����Ҫ���ҵ�i-1��λ��
	{
		p = p->next;   //���ƶ�ָ��λ��
		j++;           //���λ������ j��ʾ��ǰpָ��ĵڼ������
	}
	if (p == NULL)     //����λ�ò��Ϸ�
	{
		return false;
	}

	lnode* s = (lnode*)malloc(sizeof(lnode));   //����һ���½��
	s->data = e;  //�������
	s->next = p->next;   //���ָ��
	p->next = s;
	return true;

}

//�ڵ�i��λ�ò���Ԫ��e   ��ͷ���  i = 1 2 3 4 5 6 ...
bool listinsert2_1(linklist& l, int i, int e)
{
	if (i < 1)   //����λ�ò��Ϸ�
	{
		return false;
	}
	lnode* p;  
	p = l;
	int j = 0;   //pָ��ĳ�ʼ���λ�ã�Ҳ����ͷ����λ�ã�λ��Ϊ0����0�����
	while (p != NULL && j < i - 1)   //Ҫ�ڵ�i��λ�ò���Ԫ�أ���ô����Ҫ���ҵ�i-1��λ��
	{
		p = p->next;   //���ƶ�ָ��λ��
		j++;           //���λ������ j��ʾ��ǰpָ��ĵڼ������
	}
	if (p == NULL)     //����λ�ò��Ϸ�
	{
		return false;
	}

	lnode* s = (lnode*)malloc(sizeof(lnode));   //����һ���½��
	s->data = e;  //�������
	s->next = p->next;   //���ָ��  p����һλ�ĵ�ַ����s����һλ ��sָ��p����һλ
	p->next = s;
	return true;

}

//���������в�������Ĭ����ͷ����

//ָ����������
bool insertnextnode2(lnode* p, int e)
{
	if (p == NULL)   //ָ����㲻�Ϸ�
	{
		return false;
	}
	lnode* s = (lnode*)malloc(sizeof(lnode));  //����һ�����
	if (s == NULL)   //���ٲ��Ϸ�
	{
		return false;
	}

	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;

}

//ָ�����ǰ�����   ���ʻ��Ǻ��ֻ�ǽ��������е����ݽ�����ת��,���ʵ����ǰ�����
bool insertfrontnode2(lnode* p, int e)
{
	if (p == NULL)
	{
		return false;
	}
	lnode* s = (lnode*)malloc(sizeof(lnode));
	if (s == NULL)
	{
		return false;
	}
	s->next = p->next;
	p->next = s;
	s->data = p->data;   //����ת�ƣ���ǰ������ݺ��ƣ�����ǰ���ֵ�滻����Ҫ���������
	p->data = e;
	return true;
}

//�ڵ�i��λ�ý���ɾ��   ��ͷ���  i = 1 2 3 4 5 6 ...  ��ɾ����Ԫ��Ҫ���з��� ���������ô���
bool listdelete2(linklist& l, int i, int &e)
{
	if (i < 1)   //ɾ��λ�ò��Ϸ�
	{
		return false;
	}
	lnode* p;
	p = l;
	int j = 0;   //pָ��ĳ�ʼ���λ�ã�Ҳ����ͷ����λ�ã�λ��Ϊ0����0�����
	while (p != NULL && j < i - 1)   //Ҫ�ڵ�i��λ�ý���ɾ������ô����Ҫ���ҵ�i-1��λ��
	{
		p = p->next;   //���ƶ�ָ��λ��
		j++;           //���λ������ j��ʾ��ǰpָ��ĵڼ������
	}
	if (p == NULL)     //ɾ��λ�ò��Ϸ�
	{
		return false;
	}
	if (p->next == NULL)
	{
		return false;
	}

	lnode* s = p->next;      // Ҫɾ���Ľ����p����һ����㣬���Զ���һ����㽫Ҫɾ���Ľ����б���
	e = s->data ;        //��ű�ɾ����Ԫ��e����Ԫ��e���з���
	p->next = s->next;   //����ɾ���Ľ�����һ����ַ����p
	free(s);      //�ͷű�ɾ���Ľ��
	return true;

}

//ָ��������ɾ����������Ҫ�ҵ�ָ������ǰ����㣬����ǰ�����Ѱ�Һ��鷳�����Ի��ǽ���ָ�����ĺ�ɾ��ֻ�ǽ�������ת�ƣ����ʵ��ɾ��
//�ô�����bug������ָ���Ľ�������һ������ʱ��p->next->dataΪ�գ���������ͻᱨ��dataΪ�գ�����ֻ��ͨ��Ѱ��ǰ�����ķ�ʽ����ɾ��
bool deletenode2(lnode* p) 
{
	if (p == NULL)     //ɾ��λ�ò��Ϸ�
	{
		return false;
	} 
	lnode* s = p->next;       //p�ĺ�һ��λ��
	p->data = p->next->data;   //p֮������ݽ���ǰ�ƣ�������ӵ�ʵ��ɾ��p   
	p->next = s->next;
	free(s);             //�ͷ�p֮���λ��
	return true;

}

//��λ����
lnode* getelem2(linklist l, int i)
{
	if (i < 0)   //����λ�ò��Ϸ�
	{
		return NULL;
	}
	lnode* p;
	int j = 0;   //pָ��ĳ�ʼλ�ã���ͷ��������j��ʼֵΪ0
	p = l;       //ָ��ͷ���
	if (p != NULL && j < i)
	{
		p=p->next;   //p����ƶ�
		j++;
	}
	return p;

}

//��ֵ����
lnode* locateelem2(linklist l, int e)
{
	lnode* p;
	p = l->next;   //ͷ������һ����㣬��Ϊͷ������沢��������ݣ�������Ҫ��pָ��ͷ������һλ
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	return p;
}

//������ĳ���
int length2(linklist l)
{
	int len = 0;
	lnode* p;
	p = l;   //pָ��ͷ���
	while (p->next != NULL)
	{
		p = p->next;   //p����ƶ�
		len++;
	}
	return len;

}

//β�巨����������
linklist list_tailinsert2(linklist& l)
{
	int x;
	l = (lnode*)malloc(sizeof(lnode));  //����һ��ͷ���
	lnode* s,* r;   //*r��ʾ��βָ��
	r = l;
	cin >> x;       // x��ʾҪ���������
	while (x != 9999)  // �������x Ϊ9999ʱ����ʾ�������
	{
		s = (lnode*)malloc(sizeof(lnode));  //����һ�����
		s->data = x;
		r->next = s;
		r = s;   //��rһֱָ���β
		cin >> x;
	}
	r->next = NULL;   //β�����һλ�ÿ�
	return l;

}

//ͷ�巨���������� �����Ͼ���ÿ����ͷ���֮���������
linklist list_headinsert2(linklist& l)
{
	int x;
	lnode* s;
	l = (lnode*)malloc(sizeof(lnode));   //����һ��ͷ���
	l->next = NULL;    //ͷ���ָ���ÿ�
	cin >> x;  //����Ҫ���������x
	while (x!= 9999)
	{
		s = (lnode*)malloc(sizeof(lnode));
		s->data = x;
		s->next = l->next;  //ͷ����ָ����ֵ��s
		l->next = s;
		cin >> x;
	}
	return l;

}

//int main()
//{
//	linklist l;   //����һ��������ָ��l
//
//
//
//	system("pause");
//	return 0;
//
//}