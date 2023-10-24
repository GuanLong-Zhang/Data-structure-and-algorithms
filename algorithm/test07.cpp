#include<iostream>
using namespace std;

#define MaxSize 10

//栈  顺序栈  共享栈  链式栈

//顺序栈
typedef struct
{
	int data[MaxSize];    //静态数组，存放栈中的元素
	int top;   //栈顶指针  一般存放数组下标,栈顶数组的下标
}SqStack;

void teststack()
{
	SqStack s;
	cout << sizeof(s) << endl;  //44=40+4
}

//初始化顺序栈
void initstack(SqStack& s)
{
	s.top = -1;  //栈顶指针初始化为-1
}

//判断顺序栈是否为空
bool stackempty(SqStack s)
{
	if (s.top == -1)   //栈顶指针为-1，则证明为空；反之则不是
	{
		return true;
	}
	else
	{
		return false;
	}
}

//入栈操作
bool pushstack(SqStack& s, int x)
{
	if (s.top == MaxSize - 1)   //栈满
	{
		return false;
	}
	s.top = s.top + 1;   //栈顶指针上移
	s.data[s.top] = x;   //将元素插入数组中
	return true;

}

//出栈操作
bool popstack(SqStack& s, int& x)   //出栈元素也要进行返回，所以进行引用传递
{
	if (s.top == -1)  //栈底，栈为空
	{
		return false;
	}
	x = s.data[s.top];   //元素先出栈，并且进行返回
	s.top = s.top - 1;    //栈顶指针下移
	return true;

}

//读取栈顶元素操作
bool gettop(SqStack& s, int& x)
{
	if (s.top == -1)  //栈低，栈为空
	{
		return false;
	}
	x = s.data[s.top];  //获得栈顶元素,区别于出栈，不需要进行栈顶指针的下移
	return true;
}

//共享栈   共享栈里面有两个栈顶指针，一个在最上面，一个在最下面，移动顺序为，一个下移，一个上移
typedef struct
{
	int data[MaxSize];
	int top0;   //栈顶指针0
	int top1;   //栈顶指针1
}shstack;

//初始化共享栈
void initshstack(shstack& s)   //引用传值可以进行返回
{
	s.top0 = -1;        //栈顶在最下面   上移
	s.top1 = MaxSize;   //栈顶在最上面   下移

}

//判断共享栈栈满的条件为：
//s.top0+1==s.top1

//链栈   本质上就是单链表的操作，不过对于入栈和出栈而言，只能是对应单链表的头插和头删，相当于将链头当做栈顶
typedef struct lnode
{
	int data;   //数据域
	struct lnode* next; //指针域
}lnode,*lstack;     //lnode*强调这是一个结点，lstack强调这是一个链表

//初始化链栈 带头结点
bool initlstack(lstack& l)
{
	l = (lnode*)malloc(sizeof(lnode));   //分配一个头结点
	if (l == NULL)   //分配失败
	{
		return false;
	}
	l->next = NULL;
	return true;
}

//判空
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

//入栈操作 相当于单链表的头插  带头结点的，所以都是在头结点之后进行操作
bool pushlstack(lstack& l, int x)
{
	lnode* s = (lnode*)malloc(sizeof(lnode));
	if (s == NULL)   //结点开辟失败
	{
		return false;
	}
	s->data = x;
	s->next = l->next;
	l->next = s;
	return true;

}

//出栈操作  相当于单链表的头删  带头结点，
bool poplstack(lstack& l, int& x)   //需要将删除的元素进行返回，所以要引用传递
{
	if (l->next == NULL)    //链栈为空
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


