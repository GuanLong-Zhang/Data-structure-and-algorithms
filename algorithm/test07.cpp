#include<iostream>
using namespace std;

#define MaxSize 10

//ջ  ˳��ջ  ����ջ  ��ʽջ

//˳��ջ
typedef struct
{
	int data[MaxSize];    //��̬���飬���ջ�е�Ԫ��
	int top;   //ջ��ָ��  һ���������±�,ջ��������±�
}SqStack;

void teststack()
{
	SqStack s;
	cout << sizeof(s) << endl;  //44=40+4
}

//��ʼ��˳��ջ
void initstack(SqStack& s)
{
	s.top = -1;  //ջ��ָ���ʼ��Ϊ-1
}

//�ж�˳��ջ�Ƿ�Ϊ��
bool stackempty(SqStack s)
{
	if (s.top == -1)   //ջ��ָ��Ϊ-1����֤��Ϊ�գ���֮����
	{
		return true;
	}
	else
	{
		return false;
	}
}

//��ջ����
bool pushstack(SqStack& s, int x)
{
	if (s.top == MaxSize - 1)   //ջ��
	{
		return false;
	}
	s.top = s.top + 1;   //ջ��ָ������
	s.data[s.top] = x;   //��Ԫ�ز���������
	return true;

}

//��ջ����
bool popstack(SqStack& s, int& x)   //��ջԪ��ҲҪ���з��أ����Խ������ô���
{
	if (s.top == -1)  //ջ�ף�ջΪ��
	{
		return false;
	}
	x = s.data[s.top];   //Ԫ���ȳ�ջ�����ҽ��з���
	s.top = s.top - 1;    //ջ��ָ������
	return true;

}

//��ȡջ��Ԫ�ز���
bool gettop(SqStack& s, int& x)
{
	if (s.top == -1)  //ջ�ͣ�ջΪ��
	{
		return false;
	}
	x = s.data[s.top];  //���ջ��Ԫ��,�����ڳ�ջ������Ҫ����ջ��ָ�������
	return true;
}

//����ջ   ����ջ����������ջ��ָ�룬һ���������棬һ���������棬�ƶ�˳��Ϊ��һ�����ƣ�һ������
typedef struct
{
	int data[MaxSize];
	int top0;   //ջ��ָ��0
	int top1;   //ջ��ָ��1
}shstack;

//��ʼ������ջ
void initshstack(shstack& s)   //���ô�ֵ���Խ��з���
{
	s.top0 = -1;        //ջ����������   ����
	s.top1 = MaxSize;   //ջ����������   ����

}

//�жϹ���ջջ��������Ϊ��
//s.top0+1==s.top1

//��ջ   �����Ͼ��ǵ�����Ĳ���������������ջ�ͳ�ջ���ԣ�ֻ���Ƕ�Ӧ�������ͷ���ͷɾ���൱�ڽ���ͷ����ջ��
typedef struct lnode
{
	int data;   //������
	struct lnode* next; //ָ����
}lnode,*lstack;     //lnode*ǿ������һ����㣬lstackǿ������һ������

//��ʼ����ջ ��ͷ���
bool initlstack(lstack& l)
{
	l = (lnode*)malloc(sizeof(lnode));   //����һ��ͷ���
	if (l == NULL)   //����ʧ��
	{
		return false;
	}
	l->next = NULL;
	return true;
}

//�п�
bool emptylstack(lstack& l)
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

//��ջ���� �൱�ڵ������ͷ��  ��ͷ���ģ����Զ�����ͷ���֮����в���
bool pushlstack(lstack& l, int x)
{
	lnode* s = (lnode*)malloc(sizeof(lnode));
	if (s == NULL)   //��㿪��ʧ��
	{
		return false;
	}
	s->data = x;
	s->next = l->next;
	l->next = s;
	return true;

}

//��ջ����  �൱�ڵ������ͷɾ  ��ͷ��㣬
bool poplstack(lstack& l, int& x)   //��Ҫ��ɾ����Ԫ�ؽ��з��أ�����Ҫ���ô���
{
	if (l->next == NULL)    //��ջΪ��
	{
		return false;
	}
	lnode* s = l->next;
	x = s->data;
	l->next = s->next;
	free(s);
	return true;
}

//int main()
//{
//	teststack();
//	system("pause");
//	return 0;
//}


