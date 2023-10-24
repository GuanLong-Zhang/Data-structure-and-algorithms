#include<iostream>
using namespace std;

#define MaxSize 10
//队列  顺序队列  链列  双端队列
//顺序队列
typedef struct
{
	int data[MaxSize];   //静态数组 存放队列中的元素
	int front, rear;     //队头指针 队尾指针   队头用于出队，队尾用于入队
}SqQueue;

void testsqqueue()
{
	SqQueue s;
	cout << sizeof(s) << endl;   //40+4+4
}

//初始化队列   队头指针和队尾指针都为0
void initqueue(SqQueue& s)
{
	s.front = 0;
	s.rear = 0;
}

//判空   队头指针等于队尾指针时表示队列为空
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

//入队操作  针对队尾进行操作
bool pushqueue(SqQueue& s, int x)
{
	if ((s.rear + 1) % MaxSize == s.front)   //队满   牺牲了一个存储空间
	{ 
		return false;
	}
	s.data[s.rear] = x;   //先插入，再移动队尾指针的位置
	s.rear = (s.rear + 1)% MaxSize;
	return true;
}

//出队操作  针对队头进行操作   出队需要对于删除的数据进行返回
bool popqueue(SqQueue& s,int&x)
{
	if (s.front == s.rear)   //队空
	{
		return false;
	}
	x = s.data[s.front];    //先删除，再移动队头指针的位置
	s.front = (s.front + 1) % MaxSize;
	return true;

}

//获得队头元素   将队头元素进行返回，所以进行引用传递   对比出队少了队头指针的移动
bool gethead(SqQueue& s, int& x)
{
	if (s.front == s.rear)    //栈空
	{
		return false;
	}
	x = s.data[s.front];    //队头数据进行返回
	return true;   
}

//方案二，在定义顺序队列的时候引入size这个属性，用来记录队列的长度
//初始化的时候，让size=0
//入队的时候，进行size++
//出队的时候，进行size--
//判满，size=MaxSize
//判空，size=0
typedef struct
{
	int data[MaxSize];   //静态数组 用于存放队列元素
	int front, rear;     //队头指针 队尾指针
	int size;            //队列长度
}SqQueue2;

//方案三，在定义顺序队列的时候引入tag这个属性，用来标记是进行了删除还是进行了插入  删除标记为0  插入标记为1
//入队  tag=1
//出队  tag=0
//判空  front==rear&&tag==0   只有出队才可能为空
//判满  front==rear&&tag==1   只有入队才可能为满
typedef struct
{
	int data[MaxSize];
	int front, rear;
	int tag;
}SqQueue3;

//链列
typedef struct lnode    //链式队列结点   类似单链表
{
	int data;
	struct lnode* next;
}lnode;

typedef struct    
{
	lnode * front, * rear;    //队头指针和队尾指针
}lqueue;

void testlqueue()
{
	lqueue l;
	cout << sizeof(l) << endl;   //8
}

//初始化  带头结点
void initlqueue(lqueue& l)
{
	l.front = l.rear = (lnode*)malloc(sizeof(lnode));  //开辟一个头结点，并将队头指针和队尾指针都指向头结点
	l.front->next = NULL;    //头结点后向指针置空

}

//初始化 不带头结点
void initqueue1(lqueue& l)
{
	l.front = NULL;
	l.rear = NULL;
}

//判空   带头结点
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

//判空  不带头结点
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

//入队 带头结点  链式存储不存在存满的情况，所以在入队的时候不需要进行判空
bool pushlqueue(lqueue& l, int x)
{
	lnode* s = (lnode*)malloc(sizeof(lnode));   //开辟一个新结点
	if (s == NULL)   //开辟失败
	{
		return false;
	}
	s->data = x;    //在队尾进行入队，所以结点指针为NULL
	s->next = NULL;
	l.rear->next = s;
	l.rear = s;
	return true;
}

//入队 不带头结点
bool pushlqueue1(lqueue& l, int x)
{
	lnode* s = (lnode*)malloc(sizeof(lnode));   //开辟一个新结点
	if (s == NULL)   //开辟失败
	{
		return false;
	}
	s->data = x;     //在队尾入队，所以结点指针为NULL
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

//出队 带头结点
bool poplqueue(lqueue& l, int& x)
{
	if (l.front == l.rear)    //先进行判空操作，空则出队失败
	{
		return false;
	}
	lnode* p = l.front->next;    //因为带头结点，所以要删除的结点是头结点的下一位
	x = p->data;
	l.front->next = p->next;
	if (l.rear == p)    //队尾指针指向p，也就是最后一个元素，就需要将链列置空
	{
		l.rear = l.front;    //恢复为空队状态
	} 
	free(p);
	return true;

}

//出队 不带头结点
bool poplqueue1(lqueue& l, int& x)
{
	if (l.front == NULL)    //判空
	{
		return false;
	}
	lnode* p = l.front;   //没有头结点，所以front指向的结点就是要删除的结点
	x = p->data;
	l.front = p->next;
	if (l.rear == p)    //最后一个元素，需要进行置空
	{
		l.front = NULL;   //空队状态
		l.rear = NULL;
		
	}
	free(p);
	return true;

}

//双端队列  允许在两端进行插入和删除的线性表
//输入受限的双端队列，也就是一端进行输入，两端进行输出
//输出受限的双端队列，也就是两端进行输入，一端进行输出


//int main()
//{
//	testsqqueue();
//	testlqueue();
//	system("pause");
//	return 0;
//}