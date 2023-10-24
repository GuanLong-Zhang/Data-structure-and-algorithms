# include<iostream>
using namespace std;

# define maxsize 10   //默认最大容量

//静态存储顺序表

struct sqlist
{
	int data[maxsize];   
	int length;
};

void initlist(sqlist& l)
{
	for (int i = 0; i < maxsize; i++)
	{
		l.data[i] = 0;    //元素初始化
	}
	l.length = 0;     //长度初始化

}

void printlist(sqlist &l)
{
	cout << "输出结果为：" << endl;
	for (int i = 0; i < l.length; i++)    //输出小于长度的内容
	{
		cout << l.data[i] << endl;
	}
}

//int main()
//{
//	struct sqlist l;
//	//cout << "sizeof(l)=" << sizeof(l) << endl;
//	initlist(l);   //初始化l  引用传递
//	//printlist(l);  //输出l
//
//	system("pause");
//	return 0;
//}

