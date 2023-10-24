#include<iostream>
using namespace std;

# define Maxsize 10    //宏定义不需要加分号
//静态链表
struct node
{
	int data;   //数据域
	int next;   //游标  指向下一个元素的数组下标
};

typedef struct
{
	int data;
	int next;
}slinklist[Maxsize];

void testslinklist()
{
	struct node a;      //单个结点
	cout << sizeof(a) << endl;

	struct node b[Maxsize];   //结点数组
	cout << sizeof(b) << endl;

	slinklist c;    //结点数组
	cout << sizeof(c) << endl;
}



//int main()
//{
//	testslinklist();
//	system("pause");
//	return 0;
//}