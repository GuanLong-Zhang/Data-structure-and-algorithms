#include<iostream>
using namespace std;

//循环链表    循环单链表 循环双链表

//循环单链表   最后一个结点的指针指向头结点
typedef struct lnode   
{
	int data;   //数据域
	struct lnode* next;  //指针域 
}lnode, * linklist;      // lnode *l  linklist l  

//lnode *强调这是一个结点  linklist强调这是一个单链表


//初始化一个循环单链表  带头结点
bool initlist4(linklist& l)
{
	l = (lnode*)malloc(sizeof(lnode));   //分配了一个头结点空间
	if (l == NULL)    //假如分配失败，返回false
	{
		return false;
	}
	l->next = l;   //头结点指针指向头结点   区别于单链表不是指向NULL
	return true;

}

//判断循环单链表是否为空  带头结点
bool empty4(linklist& l)
{
	if (l->next == l)    //头结点的指向还是头结点，说明循环单链表为空
	{
		return true;
	}
	else
	{
		return false;
	}
}

//判断结点p是否是循环单链表的表尾结点
bool istail4(linklist& l, lnode* p)
{
	if (p->next == l)    //结点指针指向头结点，说明是表尾结点
	{
		return true;
	}
	else
	{
		return false;
	}
}

//循环双链表   最后一个结点的后向指针指向头结点，头结点的前向指针指向最后一个结点
typedef struct dnode
{
	int data;    //数据域
	struct dnode* prior, * next;   //指针域 前驱指针和后继指针
}dnode, * dlinklist;      //双链表   dnode* 和 dlinklist等价   第一个强调的是一个结点 第二个强调的是一个双链表

//以下操作都是默认带头结点的双链表
//初始化循环双链表
bool initdlinklist4(dlinklist& l)
{
	l = (dnode*)malloc(sizeof(dnode));  //开辟一个头结点
	if (l == NULL)   //开辟失败
	{
		return false;
	}
	l->prior = l;   //头结点的前向指针和后向指针都指向头结点，区别于双链表的NULL，两者形成闭环
	l->next = l;
	return true;

}

//判断循环双链表是否为空
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

//判断结点p是否是循环双链表的表尾结点
bool istail4(dlinklist& l, dnode* p)
{
	if (p->next == l)    //结点指针指向头结点，说明是表尾结点
	{
		return true;
	}
	else
	{
		return false;
	}
}

//区别于双链表的插入和删除，循环双链表不需要针对最后一个结点进行判断，
//因为最后一个结点的后向结点不是NULL，插入删除时可以直接进行操作。



//int main()
//{
//
//	system("pause");
//	return 0;
//}