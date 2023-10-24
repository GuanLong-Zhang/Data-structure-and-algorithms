#include<iostream>
using namespace std;

//单链表
typedef struct lnode   //定义链表中的一个结点
{
	int data;   //数据域
	struct lnode* next;  //指针域 指向下一个结点
}lnode, *linklist;      // lnode *l  linklist l   两者等价都是表示指向单链表第一个结点的指针

//lnode *强调这是一个结点  linklist强调这是一个单链表

//初始化一个单链表  不带头结点
bool initlist2(linklist& l)
{
	l = NULL;    //头指针置空
	return true;
}

//初始化一个单链表  带头结点
bool initlist2_1(linklist& l)
{
	l = (lnode*)malloc(sizeof(lnode));   //分配了一个头结点空间
	if (l == NULL)    //假如分配失败，返回false
	{
		return false;
	}
	l->next = NULL;   //头结点指向下一个结点置空   头结点数据域为空,我们不在头结点存放数据
	return true;

}


//判断单链表是否为空  不带头结点
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

//判断单链表是否为空  带头结点
bool empty2_1(linklist& l)
{
	if (l->next == NULL)    //第一个头结点数据域本身就是空的，所以判空只需要判断第一个头结点指针域是否为空就可以了
	{
		return true;
	}
	else
	{
		return false;
	}
}

//在第i个位置插入元素e   不带头结点  i = 1 2 3 4 5 6 ...  需要在第一个位置上做单独处理
bool listinsert2(linklist& l, int i, int e)
{
	if (i < 1)   //插入位置不合法
	{
		return false;
	}
	if (i == 1)   //特殊处理，不带头结点在第一个位置需要申请一个结点单独做处理,并且头指针没有next
	{
		lnode* s = (lnode*)malloc(sizeof(lnode));
		s->data = e;
		s->next = l;  //头指针赋给s
		l = s;
	}

	lnode* p;
	p = l;
	int j = 1;   //p指向的初始结点位置，没有头结点，所以位置为1，第1个结点，注意此处的1为数字1
	while (p != NULL && j < i - 1)   //要在第i个位置插入元素，那么就需要先找到i-1的位置
	{
		p = p->next;   //逐步移动指针位置
		j++;           //结点位置自增 j表示当前p指向的第几个结点
	}
	if (p == NULL)     //插入位置不合法
	{
		return false;
	}

	lnode* s = (lnode*)malloc(sizeof(lnode));   //开辟一个新结点
	s->data = e;  //存放数据
	s->next = p->next;   //存放指针
	p->next = s;
	return true;

}

//在第i个位置插入元素e   带头结点  i = 1 2 3 4 5 6 ...
bool listinsert2_1(linklist& l, int i, int e)
{
	if (i < 1)   //插入位置不合法
	{
		return false;
	}
	lnode* p;  
	p = l;
	int j = 0;   //p指向的初始结点位置，也就是头结点的位置，位置为0，第0个结点
	while (p != NULL && j < i - 1)   //要在第i个位置插入元素，那么就需要先找到i-1的位置
	{
		p = p->next;   //逐步移动指针位置
		j++;           //结点位置自增 j表示当前p指向的第几个结点
	}
	if (p == NULL)     //插入位置不合法
	{
		return false;
	}

	lnode* s = (lnode*)malloc(sizeof(lnode));   //开辟一个新结点
	s->data = e;  //存放数据
	s->next = p->next;   //存放指针  p的下一位的地址赋给s的下一位 将s指向p的下一位
	p->next = s;
	return true;

}

//后续的所有操作都是默认有头结点的

//指定结点后插操作
bool insertnextnode2(lnode* p, int e)
{
	if (p == NULL)   //指定结点不合法
	{
		return false;
	}
	lnode* s = (lnode*)malloc(sizeof(lnode));  //开辟一个结点
	if (s == NULL)   //开辟不合法
	{
		return false;
	}

	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;

}

//指定结点前插操作   本质还是后插只是将数据域中的数据进行了转移,间接实现了前插操作
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
	s->data = p->data;   //数据转移，将前面的数据后移，并将前面的值替换成需要插入的数据
	p->data = e;
	return true;
}

//在第i个位置进行删除   带头结点  i = 1 2 3 4 5 6 ...  被删除的元素要进行返回 所以用引用传递
bool listdelete2(linklist& l, int i, int &e)
{
	if (i < 1)   //删除位置不合法
	{
		return false;
	}
	lnode* p;
	p = l;
	int j = 0;   //p指向的初始结点位置，也就是头结点的位置，位置为0，第0个结点
	while (p != NULL && j < i - 1)   //要在第i个位置进行删除，那么就需要先找到i-1的位置
	{
		p = p->next;   //逐步移动指针位置
		j++;           //结点位置自增 j表示当前p指向的第几个结点
	}
	if (p == NULL)     //删除位置不合法
	{
		return false;
	}
	if (p->next == NULL)
	{
		return false;
	}

	lnode* s = p->next;      // 要删除的结点是p的下一个结点，所以定义一个结点将要删除的结点进行保存
	e = s->data ;        //存放被删除的元素e，将元素e进行返回
	p->next = s->next;   //将被删除的结点的下一个地址赋给p
	free(s);      //释放被删除的结点
	return true;

}

//指定结点进行删除，这样需要找到指定结点的前驱结点，但是前驱结点寻找很麻烦，所以还是进行指定结点的后删，只是进行数据转移，间接实现删除
//该代码有bug，即当指定的结点是最后一个结点的时候，p->next->data为空，这样代码就会报错data为空，这样只能通过寻找前驱结点的方式进行删除
bool deletenode2(lnode* p) 
{
	if (p == NULL)     //删除位置不合法
	{
		return false;
	} 
	lnode* s = p->next;       //p的后一个位置
	p->data = p->next->data;   //p之后的数据进行前移，这样间接的实现删除p   
	p->next = s->next;
	free(s);             //释放p之后的位置
	return true;

}

//按位查找
lnode* getelem2(linklist l, int i)
{
	if (i < 0)   //查找位置不合法
	{
		return NULL;
	}
	lnode* p;
	int j = 0;   //p指向的初始位置，带头结点的所以j初始值为0
	p = l;       //指向头结点
	if (p != NULL && j < i)
	{
		p=p->next;   //p向后移动
		j++;
	}
	return p;

}

//按值查找
lnode* locateelem2(linklist l, int e)
{
	lnode* p;
	p = l->next;   //头结点的下一个结点，因为头结点里面并不存放数据，所以需要将p指向头结点的下一位
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	return p;
}

//求单链表的长度
int length2(linklist l)
{
	int len = 0;
	lnode* p;
	p = l;   //p指向头结点
	while (p->next != NULL)
	{
		p = p->next;   //p向后移动
		len++;
	}
	return len;

}

//尾插法建立单链表
linklist list_tailinsert2(linklist& l)
{
	int x;
	l = (lnode*)malloc(sizeof(lnode));  //开辟一个头结点
	lnode* s,* r;   //*r表示表尾指针
	r = l;
	cin >> x;       // x表示要插入的数据
	while (x != 9999)  // 当输入的x 为9999时，表示输入结束
	{
		s = (lnode*)malloc(sizeof(lnode));  //开辟一个结点
		s->data = x;
		r->next = s;
		r = s;   //让r一直指向表尾
		cin >> x;
	}
	r->next = NULL;   //尾结点下一位置空
	return l;

}

//头插法建立单链表 本质上就是每次在头结点之后插入数据
linklist list_headinsert2(linklist& l)
{
	int x;
	lnode* s;
	l = (lnode*)malloc(sizeof(lnode));   //开辟一个头结点
	l->next = NULL;    //头结点指针置空
	cin >> x;  //输入要插入的数据x
	while (x!= 9999)
	{
		s = (lnode*)malloc(sizeof(lnode));
		s->data = x;
		s->next = l->next;  //头结点的指针域赋值给s
		l->next = s;
		cin >> x;
	}
	return l;

}

//int main()
//{
//	linklist l;   //声明一个单链表指针l
//
//
//
//	system("pause");
//	return 0;
//
//}