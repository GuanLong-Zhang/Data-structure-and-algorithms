#include<iostream>
using namespace std;

//��

//��ȫ������˳��洢
#define MaxSize 100

struct treenode
{
	int value;   //����е�ֵ
	bool isempty;   //����Ƿ�Ϊ��
};

//��ʼ��һ   ����ָ��   ��ַ���� �βθı�Ӱ��ʵ��
treenode* inittree0_1(treenode *t)
{
	for (int i = 1; i <= MaxSize; i++)   //������һ���ռ䣬ʹ���±�ͽ����һ��
	{
		t[i].isempty = true;   //��ʼ����㶼�ÿ�
	}
	return t;
}

//��ʼ����   ����bool
bool inittree0_2(treenode* t)
{
	for (int i = 1; i <= MaxSize; i++)   //������һ���ռ䣬ʹ���±�ͽ����һ��
	{
		t[i].isempty = true;   //��ʼ����㶼�ÿ�
	}
	return true;
}

//��������˳��洢ֻ�ʺϴ洢��ȫ���������洢��Ĳ�����

//����������ʽ�洢
typedef struct bitnode
{
	int data;   //������
	struct bitnode* lchild, * rchild;   //��ָ�� ��ָ��
}bitnode,*bitree;    //bitnode* ǿ����һ����� bitree ǿ����һ����

//��ʼ��
bool inittree1(bitree&root)
{
	root = NULL;
	return true;
}

//��������
void insertroot(bitree& root,int i)
{
	root = (bitnode*)malloc(sizeof(bitnode));
	root->data = i;
	root->lchild = NULL;
	root->rchild = NULL;
}

//��������
void insertlchild(bitree&root,int i)
{
	bitnode* p = (bitnode*)malloc(sizeof(bitnode));
	p->data = i;
	p->lchild = NULL;
	p->rchild = NULL;
	root->lchild = p;    //��������������Ϊp
}

//�����ҽ��
void insertrchild(bitree& root,int i)
{
	bitnode* p = (bitnode*)malloc(sizeof(bitnode));
	p->data = i;
	p->lchild = NULL;
	p->rchild = NULL;
	root->rchild = p;    //�������ҽ������Ϊp
}

//�������ı���  ������� ������� ��������
//����������
void visit(bitree &root)
{
	cout << root->data << endl;
}

//�������
void preorder(bitree &root)
{
	if (root != NULL)
	{
		visit(root);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}

//�������
void inorder(bitree &root)
{
	if (root != NULL)
	{
		inorder(root->lchild);
		visit(root);
		inorder(root->rchild);
	}
}

//��������
void postorder(bitree &root)
{
	if (root != NULL)
	{
		postorder(root->lchild);
		postorder(root->rchild);
		visit(root);
	}
}

//��������α���
//��Ҫ�������н���ʵ��  �ڶ��е�Ӧ�����漰���Ĳ�α���
//������ʽ���н���ʵ�֣�����ͷ���

//����
typedef struct lnode2    //��ʽ���н��   ���Ƶ�����
{
	bitnode* bit;       //�˴�������Ľ���ָ��  bit������������������ָ����
	struct lnode2* next;
}lnode2;

typedef struct
{
	lnode2* front, * rear;    //��ͷָ��Ͷ�βָ��
}lqueue2;

//��ʼ�� ����ͷ���
void initqueue2(lqueue2& l)
{
	l.front = NULL;
	l.rear = NULL;
}

//�п�  ����ͷ���
bool emptylqueue2(lqueue2& l)
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

//��� ����ͷ���
bool pushlqueue2(lqueue2& l, bitree &root)
{
	lnode2* s = (lnode2*)malloc(sizeof(lnode2));   //����һ���½��
	if (s==NULL)   //����ʧ��
	{
		return false;
	}

	s->bit = root;     //�ڶ�β��ӣ����Խ��ָ��ΪNULL
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

//���� ����ͷ���
bool poplqueue2(lqueue2& l, bitree&root)
{
	if (l.front == NULL)    //�п�
	{
		return false;
	}
	lnode2* p = l.front;   //û��ͷ��㣬����frontָ��Ľ�����Ҫɾ���Ľ��
	root = p->bit;
	l.front = p->next;
	if (l.rear == p)    //���һ��Ԫ�أ���Ҫ�����ÿ�
	{
		l.front = NULL;   //�ն�״̬
		l.rear = NULL;

	}
	free(p);
	return true;
}

void levelorder(bitree &root)
{
	lqueue2 l;   //����  ��������
	initqueue2(l);    //��ʼ��
	bitree p;  //�����  �����洢���ӽ��
	pushlqueue2(l, root);  //��������
	while (!emptylqueue2(l))
	{
		poplqueue2(l, p);  //��ͷ����
		visit(p);   //���������Ϣ
		if (p->lchild!= NULL)    //���ӽ��������ӽ����ڣ��ʹ��븨��������
		{
			pushlqueue2(l, p->lchild);
		}
		if (p->rchild != NULL)
		{
			pushlqueue2(l, p->rchild);
		}
	}
}

//����������
typedef struct threadnode
{
	int data;   //������
	struct threadnode* lchild, * rchild;   //����ָ��   ǰ������
	int ltag, rtag;    //��ʶλ Ϊ0��ʾָ�룬Ϊ1��ʾ����
}threadnode,*threadtree;  //threadnode*ǿ����һ����� threadtreeǿ����һ����

//������
void visit1(threadtree& t,threadtree &pre)
{
	if (t->lchild == NULL)
	{
		t->lchild = pre;   //ǰ������
		t->ltag = 1;       //��������ʶ
	}
	if (pre != NULL && pre->rchild == NULL)
	{
		pre->rchild = t;   //�������
		pre->rtag = 1;
	}
	pre = t;    //�ƶ�pre
}

//�������������  һ�߱���һ��������  ������������visit1��
void inthread(threadtree& t,threadtree&pre)
{
	if (t != NULL)
	{
		inthread(t->lchild,pre);    //�� �� ��
		visit1(t,pre);
		inthread(t->rchild,pre);
	}
}

//����������
void createinthread(threadtree& root)
{
	threadtree pre = NULL;     //ǰ�����ָ���ʼ��
	if (root != NULL)
	{
		inthread(root,pre);
		if (pre->rchild == NULL)    //���һ���������
		{
			pre->rtag = 1;
		}
	}
}

//�������������  һ�߱���һ��������  ������������visit1��
void prethread(threadtree& t, threadtree& pre)
{
	if (t != NULL)
	{
		visit1(t, pre);     //�� �� ��
		if (t->ltag == 0)    //��Ҫ�����жϣ�������ӻ����ԭ��תȦ����� ֻ�е�������û�н�����������ʱ��Ž���������
		{
			prethread(t->lchild, pre);
		}
		prethread(t->rchild, pre);
	}
}

//����������
void createprethread(threadtree& root)
{
	threadtree pre = NULL;     //ǰ�����ָ���ʼ��
	if (root != NULL)
	{
		prethread(root, pre);
		if (pre->rchild == NULL)    //���һ���������
		{
			pre->rtag = 1;
		}
	}
}

//�������������  һ�߱���һ��������  ������������visit1��
void postthread(threadtree& t, threadtree& pre)
{
	if (t != NULL)
	{
		postthread(t->lchild, pre);  //�� �� ��
		postthread(t->rchild, pre);
		visit1(t, pre);
	}
}

//����������
void createpostthread(threadtree& root)
{
	threadtree pre = NULL;     //ǰ�����ָ���ʼ��
	if (root != NULL)
	{
		postthread(root, pre);
		if (pre->rchild == NULL)    //���һ���������
		{
			pre->rtag = 1;
		}
	}
}

//����������������ָ������������
threadnode* firstnode(threadnode* p)
{
	while (p->ltag == 0)   //������һֱ���ڣ��Ǿ�һֱѰ��
	{
		p = p->lchild;
	}
	return p;
}

threadnode* nextnode(threadnode* p)
{
	if (p->rtag == 0)   //δ��������  ����������
	{
		return firstnode(p->rchild);   //������������ߵĽ��
	}
	else   //�������� ֱ�ӷ���������
	{
		return p->rchild;
	}
}

//�������������������������   ��������ʵ�ַǵݹ����
void inorder1(threadtree& t)
{
	for (threadnode* p = firstnode(t); p != NULL; p = nextnode(p))  //���ҵ���һ�� �ٽ���������
	{
		cout << p->data << endl;
	}
}

//����������������ָ����������ǰ��
threadnode* lastnode(threadnode* p)
{
	while (p->rtag == 0)   //������һֱ���ڣ��Ǿ�һֱѰ��
	{
		p = p->rchild;
	}
	return p;
}

threadnode* prenode(threadnode* p)
{
	if (p->ltag == 0)   //δ��������  ����������
	{
		return lastnode(p->lchild);   //�����������ұߵĽ��
	}
	else   //�������� ֱ�ӷ���������
	{
		return p->lchild;
	}
}

//�����������������������������   ��������ʵ�ַǵݹ����
void revinorder1(threadtree& t)
{
	for (threadnode* p = lastnode(t); p != NULL; p = prenode(p))   //���ҵ����һ�� �ٽ�������ǰ��
	{
		cout << p->data << endl;
	}
}

//���Ĵ洢�ṹ
//��ʽһ��˫�ױ�ʾ��
//˳��洢��  ���þ�̬����ķ�ʽʵ��
#define max_size 100
typedef struct
{
	int data;   //������
	int parent;   //ָ���򣬲����˴���ŵ���˫�׽��������±꣨Ҳ���Ǹ��ڵ�������±꣩
}ptnode;

typedef struct
{
	ptnode nodes[max_size];  //����洢
	int n;   //�����
}ptree;

//��ʽ�������ӱ�ʾ��
//˳��+��ʽ�洢  ��̬����͵�����ķ�ʽʵ��
struct ctnode   //������
{
	int child;   //ָ���򣬺��ӽ�������±� 
	struct ctnode* next;   //��һ������
};

typedef struct
{
	int data;   //������
	struct ctnode* firstnode;   //ָ����
}ctbox;

typedef struct
{
	ctbox nodes[max_size];
	int n, r;   //����� ����λ��
}ctree;

//��ʽ���������ֵܱ�ʾ��   �����ڶ�����
typedef struct csnode
{
	int data;  //������
	struct csnode* firstnode, * nextsibling;   //ָ���� ���� ���ֵ�
}csnode,*cstree;



//int main()
//{
//	////��ȫ������˳��洢
//	//treenode t[MaxSize];   //ʵ����
//
//	////��ʼ��һ
//	//treenode *st= inittree0_1(t);  //��ʼ��
//	//int length = 0;
//	//for (int i = 1; i <= MaxSize; i++)   
//	//{
//	//	cout << st[i].isempty << endl;
//	//	length++;
//	//}
//	//cout << length << endl;
//
//	////��ʼ����
//	//if (inittree0_2(t))   //��ʼ��
//	//{
//	//	cout << "init is success!" << endl;
//	//}
//	//int length = 0;
//	//for (int i = 1; i <= MaxSize; i++)   
//	//{
//	//	cout << t[i].isempty << endl;
//	//	length++;
//	//}
//	//cout << length << endl;
//
//
//	//��������ʽ�洢
//	bitree root;   //ʵ����
//	if (inittree1(root))   //��ʼ��
//	{
//		cout << "init is success!" << endl;
//	}
//	if (root == NULL)
//	{
//		cout << "yes" << endl;
//	}
//	insertroot(root,1);   //��������
//	cout << root->data << endl;   
//
//	insertlchild(root,2);   //��������
//	cout << root->lchild->data << endl;
//
//	insertrchild(root,3);   //�����ҽ��
//	cout << root->rchild->data << endl;
//
//	insertlchild(root->lchild, 4);   
//	cout << root->lchild->lchild->data << endl;  //�ڸ����������������
//
//	cout << "�����������������" << endl;
//	preorder(root);
//
//	cout << "�����������������" << endl;
//	inorder(root);
//
//	cout << "�������ĺ��������" << endl;
//	postorder(root);
//
//	cout << "�������Ĳ�α�����" << endl;
//	levelorder(root);
//
//	//������
//	  
//
//	system("pause");
//	return 0;
//}