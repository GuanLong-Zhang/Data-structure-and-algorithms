#include<iostream>
using namespace std;

//树

//完全二叉树顺序存储
#define MaxSize 100

struct treenode
{
	int value;   //结点中的值
	bool isempty;   //结点是否为空
};

//初始化一   返回指针   地址传递 形参改变影响实参
treenode* inittree0_1(treenode *t)
{
	for (int i = 1; i <= MaxSize; i++)   //舍弃第一个空间，使得下标和结点数一致
	{
		t[i].isempty = true;   //初始化结点都置空
	}
	return t;
}

//初始化二   返回bool
bool inittree0_2(treenode* t)
{
	for (int i = 1; i <= MaxSize; i++)   //舍弃第一个空间，使得下标和结点数一致
	{
		t[i].isempty = true;   //初始化结点都置空
	}
	return true;
}

//二叉树的顺序存储只适合存储完全二叉树，存储别的不方便

//二叉树的链式存储
typedef struct bitnode
{
	int data;   //数据域
	struct bitnode* lchild, * rchild;   //左指针 右指针
}bitnode,*bitree;    //bitnode* 强调是一个结点 bitree 强调是一课树

//初始化
bool inittree1(bitree&root)
{
	root = NULL;
	return true;
}

//插入根结点
void insertroot(bitree& root,int i)
{
	root = (bitnode*)malloc(sizeof(bitnode));
	root->data = i;
	root->lchild = NULL;
	root->rchild = NULL;
}

//插入左结点
void insertlchild(bitree&root,int i)
{
	bitnode* p = (bitnode*)malloc(sizeof(bitnode));
	p->data = i;
	p->lchild = NULL;
	p->rchild = NULL;
	root->lchild = p;    //根结点的左结点设置为p
}

//插入右结点
void insertrchild(bitree& root,int i)
{
	bitnode* p = (bitnode*)malloc(sizeof(bitnode));
	p->data = i;
	p->lchild = NULL;
	p->rchild = NULL;
	root->rchild = p;    //根结点的右结点设置为p
}

//二叉树的遍历  先序遍历 中序遍历 后续遍历
//输出结点数据
void visit(bitree &root)
{
	cout << root->data << endl;
}

//先序遍历
void preorder(bitree &root)
{
	if (root != NULL)
	{
		visit(root);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}

//中序遍历
void inorder(bitree &root)
{
	if (root != NULL)
	{
		inorder(root->lchild);
		visit(root);
		inorder(root->rchild);
	}
}

//后续遍历
void postorder(bitree &root)
{
	if (root != NULL)
	{
		postorder(root->lchild);
		postorder(root->rchild);
		visit(root);
	}
}

//二叉树层次遍历
//需要借助队列进行实现  在队列的应用中涉及树的层次遍历
//采用链式队列进行实现，不带头结点

//链列
typedef struct lnode2    //链式队列结点   类似单链表
{
	bitnode* bit;       //此处存放树的结点的指针  bit里面包含数据域和左，右指针域
	struct lnode2* next;
}lnode2;

typedef struct
{
	lnode2* front, * rear;    //队头指针和队尾指针
}lqueue2;

//初始化 不带头结点
void initqueue2(lqueue2& l)
{
	l.front = NULL;
	l.rear = NULL;
}

//判空  不带头结点
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

//入队 不带头结点
bool pushlqueue2(lqueue2& l, bitree &root)
{
	lnode2* s = (lnode2*)malloc(sizeof(lnode2));   //开辟一个新结点
	if (s==NULL)   //开辟失败
	{
		return false;
	}

	s->bit = root;     //在队尾入队，所以结点指针为NULL
	s->next = NULL;
	if (l.front == NULL)   //因为不带头结点，所以需要对队头指针进行判断，如果为NULL，
		                   //那么就需要对队头指针和队尾指针进行修改，进行第一个元素的填充
	{
		l.front = s;
		l.rear = s;
	}
	else
	{
		l.rear->next = s;  //队尾指针下一位为s，然后移动队尾指针
		l.rear = s;
	}
	return true;
}

//出队 不带头结点
bool poplqueue2(lqueue2& l, bitree&root)
{
	if (l.front == NULL)    //判空
	{
		return false;
	}
	lnode2* p = l.front;   //没有头结点，所以front指向的结点就是要删除的结点
	root = p->bit;
	l.front = p->next;
	if (l.rear == p)    //最后一个元素，需要进行置空
	{
		l.front = NULL;   //空队状态
		l.rear = NULL;

	}
	free(p);
	return true;
}

void levelorder(bitree &root)
{
	lqueue2 l;   //链列  辅助队列
	initqueue2(l);    //初始化
	bitree p;  //树结点  用来存储出队结点
	pushlqueue2(l, root);  //根结点入队
	while (!emptylqueue2(l))
	{
		poplqueue2(l, p);  //队头出队
		visit(p);   //输出出队信息
		if (p->lchild!= NULL)    //出队结点的左右子结点存在，就存入辅助队列中
		{
			pushlqueue2(l, p->lchild);
		}
		if (p->rchild != NULL)
		{
			pushlqueue2(l, p->rchild);
		}
	}
}

//线索二叉树
typedef struct threadnode
{
	int data;   //数据域
	struct threadnode* lchild, * rchild;   //左右指针   前后线索
	int ltag, rtag;    //标识位 为0表示指针，为1表示线索
}threadnode,*threadtree;  //threadnode*强调是一个结点 threadtree强调是一课树

//线索化
void visit1(threadtree& t,threadtree &pre)
{
	if (t->lchild == NULL)
	{
		t->lchild = pre;   //前驱线索
		t->ltag = 1;       //线索化标识
	}
	if (pre != NULL && pre->rchild == NULL)
	{
		pre->rchild = t;   //后继线索
		pre->rtag = 1;
	}
	pre = t;    //移动pre
}

//中序遍历线索化  一边遍历一边线索化  线索化操作在visit1中
void inthread(threadtree& t,threadtree&pre)
{
	if (t != NULL)
	{
		inthread(t->lchild,pre);    //左 根 右
		visit1(t,pre);
		inthread(t->rchild,pre);
	}
}

//中序线索化
void createinthread(threadtree& root)
{
	threadtree pre = NULL;     //前驱结点指针初始化
	if (root != NULL)
	{
		inthread(root,pre);
		if (pre->rchild == NULL)    //最后一个结点的情况
		{
			pre->rtag = 1;
		}
	}
}

//先序遍历线索化  一边遍历一边线索化  线索化操作在visit1中
void prethread(threadtree& t, threadtree& pre)
{
	if (t != NULL)
	{
		visit1(t, pre);     //根 左 右
		if (t->ltag == 0)    //需要进行判断，如果不加会出现原地转圈的情况 只有当左子树没有进行线索化的时候才进行线索化
		{
			prethread(t->lchild, pre);
		}
		prethread(t->rchild, pre);
	}
}

//先序线索化
void createprethread(threadtree& root)
{
	threadtree pre = NULL;     //前驱结点指针初始化
	if (root != NULL)
	{
		prethread(root, pre);
		if (pre->rchild == NULL)    //最后一个结点的情况
		{
			pre->rtag = 1;
		}
	}
}

//后序遍历线索化  一边遍历一边线索化  线索化操作在visit1中
void postthread(threadtree& t, threadtree& pre)
{
	if (t != NULL)
	{
		postthread(t->lchild, pre);  //左 右 根
		postthread(t->rchild, pre);
		visit1(t, pre);
	}
}

//后序线索化
void createpostthread(threadtree& root)
{
	threadtree pre = NULL;     //前驱结点指针初始化
	if (root != NULL)
	{
		postthread(root, pre);
		if (pre->rchild == NULL)    //最后一个结点的情况
		{
			pre->rtag = 1;
		}
	}
}

//中序线索二叉树找指定结点的中序后继
threadnode* firstnode(threadnode* p)
{
	while (p->ltag == 0)   //左子树一直存在，那就一直寻找
	{
		p = p->lchild;
	}
	return p;
}

threadnode* nextnode(threadnode* p)
{
	if (p->rtag == 0)   //未被线索化  存在右子树
	{
		return firstnode(p->rchild);   //找右子树最左边的结点
	}
	else   //被线索化 直接返回右子树
	{
		return p->rchild;
	}
}

//对中序线索二叉树做中序遍历   利用线索实现非递归遍历
void inorder1(threadtree& t)
{
	for (threadnode* p = firstnode(t); p != NULL; p = nextnode(p))  //先找到第一个 再进行中序后继
	{
		cout << p->data << endl;
	}
}

//中序线索二叉树找指定结点的中序前驱
threadnode* lastnode(threadnode* p)
{
	while (p->rtag == 0)   //右子树一直存在，那就一直寻找
	{
		p = p->rchild;
	}
	return p;
}

threadnode* prenode(threadnode* p)
{
	if (p->ltag == 0)   //未被线索化  存在左子树
	{
		return lastnode(p->lchild);   //找左子树最右边的结点
	}
	else   //被线索化 直接返回左子树
	{
		return p->lchild;
	}
}

//对中序线索二叉树做逆向中序遍历   利用线索实现非递归遍历
void revinorder1(threadtree& t)
{
	for (threadnode* p = lastnode(t); p != NULL; p = prenode(p))   //先找到最后一个 再进行中序前驱
	{
		cout << p->data << endl;
	}
}

//树的存储结构
//方式一：双亲表示法
//顺序存储法  采用静态数组的方式实现
#define max_size 100
typedef struct
{
	int data;   //数据域
	int parent;   //指针域，不过此处存放的是双亲结点的数组下标（也就是父节点的数组下标）
}ptnode;

typedef struct
{
	ptnode nodes[max_size];  //数组存储
	int n;   //结点数
}ptree;

//方式二：孩子表示法
//顺序+链式存储  静态数组和单链表的方式实现
struct ctnode   //单链表
{
	int child;   //指针域，孩子结点数组下标 
	struct ctnode* next;   //下一个孩子
};

typedef struct
{
	int data;   //数据域
	struct ctnode* firstnode;   //指针域
}ctbox;

typedef struct
{
	ctbox nodes[max_size];
	int n, r;   //结点数 根的位置
}ctree;

//方式三：孩子兄弟表示法   类似于二叉树
typedef struct csnode
{
	int data;  //数据域
	struct csnode* firstnode, * nextsibling;   //指针域 左孩子 右兄弟
}csnode,*cstree;



//int main()
//{
//	////完全二叉树顺序存储
//	//treenode t[MaxSize];   //实例化
//
//	////初始化一
//	//treenode *st= inittree0_1(t);  //初始化
//	//int length = 0;
//	//for (int i = 1; i <= MaxSize; i++)   
//	//{
//	//	cout << st[i].isempty << endl;
//	//	length++;
//	//}
//	//cout << length << endl;
//
//	////初始化二
//	//if (inittree0_2(t))   //初始化
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
//	//二叉树链式存储
//	bitree root;   //实例化
//	if (inittree1(root))   //初始化
//	{
//		cout << "init is success!" << endl;
//	}
//	if (root == NULL)
//	{
//		cout << "yes" << endl;
//	}
//	insertroot(root,1);   //插入根结点
//	cout << root->data << endl;   
//
//	insertlchild(root,2);   //插入左结点
//	cout << root->lchild->data << endl;
//
//	insertrchild(root,3);   //插入右结点
//	cout << root->rchild->data << endl;
//
//	insertlchild(root->lchild, 4);   
//	cout << root->lchild->lchild->data << endl;  //在根结点的左结点插入左结点
//
//	cout << "二叉树的先序遍历：" << endl;
//	preorder(root);
//
//	cout << "二叉树的中序遍历：" << endl;
//	inorder(root);
//
//	cout << "二叉树的后序遍历：" << endl;
//	postorder(root);
//
//	cout << "二叉树的层次遍历：" << endl;
//	levelorder(root);
//
//	//线索化
//	  
//
//	system("pause");
//	return 0;
//}