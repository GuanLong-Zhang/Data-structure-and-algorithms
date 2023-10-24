#include<iostream>
using namespace std;

#define MaxSize 10
//����  ˳�����  ����  ˫�˶���
//˳�����
typedef struct
{
	int data[MaxSize];   //��̬���� ��Ŷ����е�Ԫ��
	int front, rear;     //��ͷָ�� ��βָ��   ��ͷ���ڳ��ӣ���β�������
}SqQueue;

void testsqqueue()
{
	SqQueue s;
	cout << sizeof(s) << endl;   //40+4+4
}

//��ʼ������   ��ͷָ��Ͷ�βָ�붼Ϊ0
void initqueue(SqQueue& s)
{
	s.front = 0;
	s.rear = 0;
}

//�п�   ��ͷָ����ڶ�βָ��ʱ��ʾ����Ϊ��
bool emptyqueue(SqQueue& s)
{
	if (s.front == s.rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//��Ӳ���  ��Զ�β���в���
bool pushqueue(SqQueue& s, int x)
{
	if ((s.rear + 1) % MaxSize == s.front)   //����   ������һ���洢�ռ�
	{ 
		return false;
	}
	s.data[s.rear] = x;   //�Ȳ��룬���ƶ���βָ���λ��
	s.rear = (s.rear + 1)% MaxSize;
	return true;
}

//���Ӳ���  ��Զ�ͷ���в���   ������Ҫ����ɾ�������ݽ��з���
bool popqueue(SqQueue& s,int&x)
{
	if (s.front == s.rear)   //�ӿ�
	{
		return false;
	}
	x = s.data[s.front];    //��ɾ�������ƶ���ͷָ���λ��
	s.front = (s.front + 1) % MaxSize;
	return true;

}

//��ö�ͷԪ��   ����ͷԪ�ؽ��з��أ����Խ������ô���   �Աȳ������˶�ͷָ����ƶ�
bool gethead(SqQueue& s, int& x)
{
	if (s.front == s.rear)    //ջ��
	{
		return false;
	}
	x = s.data[s.front];    //��ͷ���ݽ��з���
	return true;   
}

//���������ڶ���˳����е�ʱ������size������ԣ�������¼���еĳ���
//��ʼ����ʱ����size=0
//��ӵ�ʱ�򣬽���size++
//���ӵ�ʱ�򣬽���size--
//������size=MaxSize
//�пգ�size=0
typedef struct
{
	int data[MaxSize];   //��̬���� ���ڴ�Ŷ���Ԫ��
	int front, rear;     //��ͷָ�� ��βָ��
	int size;            //���г���
}SqQueue2;

//���������ڶ���˳����е�ʱ������tag������ԣ���������ǽ�����ɾ�����ǽ����˲���  ɾ�����Ϊ0  ������Ϊ1
//���  tag=1
//����  tag=0
//�п�  front==rear&&tag==0   ֻ�г��Ӳſ���Ϊ��
//����  front==rear&&tag==1   ֻ����Ӳſ���Ϊ��
typedef struct
{
	int data[MaxSize];
	int front, rear;
	int tag;
}SqQueue3;

//����
typedef struct lnode    //��ʽ���н��   ���Ƶ�����
{
	int data;
	struct lnode* next;
}lnode;

typedef struct    
{
	lnode * front, * rear;    //��ͷָ��Ͷ�βָ��
}lqueue;

void testlqueue()
{
	lqueue l;
	cout << sizeof(l) << endl;   //8
}

//��ʼ��  ��ͷ���
void initlqueue(lqueue& l)
{
	l.front = l.rear = (lnode*)malloc(sizeof(lnode));  //����һ��ͷ��㣬������ͷָ��Ͷ�βָ�붼ָ��ͷ���
	l.front->next = NULL;    //ͷ������ָ���ÿ�

}

//��ʼ�� ����ͷ���
void initqueue1(lqueue& l)
{
	l.front = NULL;
	l.rear = NULL;
}

//�п�   ��ͷ���
bool emptylqueue(lqueue& l)
{
	if (l.front == l.rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//�п�  ����ͷ���
bool emptylqueue1(lqueue& l)
{
	if (l.front == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//��� ��ͷ���  ��ʽ�洢�����ڴ������������������ӵ�ʱ����Ҫ�����п�
bool pushlqueue(lqueue& l, int x)
{
	lnode* s = (lnode*)malloc(sizeof(lnode));   //����һ���½��
	if (s == NULL)   //����ʧ��
	{
		return false;
	}
	s->data = x;    //�ڶ�β������ӣ����Խ��ָ��ΪNULL
	s->next = NULL;
	l.rear->next = s;
	l.rear = s;
	return true;
}

//��� ����ͷ���
bool pushlqueue1(lqueue& l, int x)
{
	lnode* s = (lnode*)malloc(sizeof(lnode));   //����һ���½��
	if (s == NULL)   //����ʧ��
	{
		return false;
	}
	s->data = x;     //�ڶ�β��ӣ����Խ��ָ��ΪNULL
	s->next = NULL;
	if (l.front == NULL)   //��Ϊ����ͷ��㣬������Ҫ�Զ�ͷָ������жϣ����ΪNULL��
		                   //��ô����Ҫ�Զ�ͷָ��Ͷ�βָ������޸ģ����е�һ��Ԫ�ص����
	{
		l.front = s;
		l.rear = s;
	}
	else
	{
		l.rear->next = s;  //��βָ����һλΪs��Ȼ���ƶ���βָ��
		l.rear = s;
	}
	return true;
}

//���� ��ͷ���
bool poplqueue(lqueue& l, int& x)
{
	if (l.front == l.rear)    //�Ƚ����пղ������������ʧ��
	{
		return false;
	}
	lnode* p = l.front->next;    //��Ϊ��ͷ��㣬����Ҫɾ���Ľ����ͷ������һλ
	x = p->data;
	l.front->next = p->next;
	if (l.rear == p)    //��βָ��ָ��p��Ҳ�������һ��Ԫ�أ�����Ҫ�������ÿ�
	{
		l.rear = l.front;    //�ָ�Ϊ�ն�״̬
	} 
	free(p);
	return true;

}

//���� ����ͷ���
bool poplqueue1(lqueue& l, int& x)
{
	if (l.front == NULL)    //�п�
	{
		return false;
	}
	lnode* p = l.front;   //û��ͷ��㣬����frontָ��Ľ�����Ҫɾ���Ľ��
	x = p->data;
	l.front = p->next;
	if (l.rear == p)    //���һ��Ԫ�أ���Ҫ�����ÿ�
	{
		l.front = NULL;   //�ն�״̬
		l.rear = NULL;
		
	}
	free(p);
	return true;

}

//˫�˶���  ���������˽��в����ɾ�������Ա�
//�������޵�˫�˶��У�Ҳ����һ�˽������룬���˽������
//������޵�˫�˶��У�Ҳ�������˽������룬һ�˽������


//int main()
//{
//	testsqqueue();
//	testlqueue();
//	system("pause");
//	return 0;
//}