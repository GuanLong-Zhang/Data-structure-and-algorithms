# include<iostream>
using namespace std;

//双链表
typedef struct dnode
{
	int data;    //数据域
	struct dnode* prior, * next;   //指针域 前驱指针和后继指针
}dnode,*dlinklist;      //双链表   dnode* 和 dlinklist等价   第一个强调的是一个结点 第二个强调的是一个双链表

//以下操作都是默认带头结点的双链表
//初始化双链表
bool initdlinklist3(dlinklist& l)   
{
	l = (dnode*)malloc(sizeof(dnode));  //开辟一个头结点
	if (l == NULL)   //开辟失败
	{
		return false;
	}
	l->prior = NULL;   //prior永远指向空  头结点的前驱结点一定为空
	l->next = NULL;
	return true;

}

//判断双链表是否为空
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

//指定结点后插操作
bool insertnextdnode3(dnode*p,dnode*s)
{
	if (p == NULL || s == NULL)   //插入结点不合法
	{
		return false;
	}
	s->next = p->next;
	if (p->next != NULL)   //防止p是最后一个结点
	{
		p->next->prior = s;
	}
	
	s->prior = p;
	p->next = s;
	return true;
	
}

//指定结点前插操作
//可以利用双链表的特性，找到指定结点的前驱结点，然后针对前驱结点进行后插操作即可
bool insertfrontdnode3(dnode* p, dnode* s)
{
	if (p == NULL || s == NULL)   //插入结点不合法
	{
		return false;
	}
	dnode* q;   //定义p的前驱结点
	q = p->prior;
	insertnextdnode3(q, s);
}

//删除指定结点的后继结点
bool deletenextdnode3(dnode* p)
{
	if (p == NULL)
	{
		return false;
	}
	dnode* q;  //定义p的后继结点
	q = p->next; 
	if (q == NULL)   //后继结点不合法
	{
		return false;
	}
	p->next = q->next;
	if (q->next != NULL)   //防止q是最后一个结点
	{
		q->next->prior = p;
	}
	free(q);
	return true;
	
}

//销毁一个双链表
void destorydlinklist3(dlinklist& l)
{
	while (l->next != NULL)   //后指针不为空，就执行删除后继结点的操作
	{
		deletenextdnode3(l);   
	}
	free(l);  
	l->next = NULL;   //头指针指向NULL

}

//后向遍历双链表
void fornextdlinklist3(dnode* p)
{
	while (p!= NULL)
	{
		cout << p->data << endl;
		p = p->next;
	}
}

//前向遍历双链表
void forfrontdlinklist3(dnode* p)
{
	while (p != NULL)   //while(p->prior!=NULL)   //只要不是头结点就可以进行操作，跳过头结点
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