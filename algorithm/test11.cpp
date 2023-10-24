#include<iostream>
using namespace std;

//并查集
#define size 13

//初始化并查集
void initial(int s[])
{
	for (int i = 0; i < size; i++)
	{
		s[i] = -1;    //数组s中存储的是父节点指针，也就是数组下标，类似于树存储的双亲表示法
	}
}

//打印输出
void Print(int s[])
{

	for (int i = 0; i < size; i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;

}

//查操作
int Find(int s[], int x)   //x表示所查结点的数组下标
{
	while (s[x] >= 0)   //父节点指针大于等于0，说明还没有找到根结点
	{
		x = s[x];       //一直寻找，直到找到根结点
	}
	return x;   //根结点元素数组下标
}

//并操作
void Union(int s[], int root1, int root2)   //root1 root2表示俩个集合根结点的数组下标
{
	if (root1 == root2)   //两个集合是同一个集合
	{
		return;  //返回空
	}
	s[root1] = root2;  //将root1接到root2的后面，成为一个子集
}

//优化并操作   关键在于让小树合并到大树，这样就可以保证树的高度不会发生变换，这样对于查询而言，时间复杂度就会大大减小
void Union1(int s[], int root1, int root2)   //s[]存放的是父节点的指针，同时对于根结点其绝对值表示结点的个数,没有优化时候根结点绝对值为1
{
	if (root1 == root2)
	{
		return;
	}
	if (s[root1] > s[root2])   //root里面存放负值，所以谁大反而里面的结点数少，结点数少的就是小树，结点数多的就是大树
	{
		s[root2] += s[root1];   //对结点数进行相加,通过结点数来判断大小树   
		s[root1] = root2;       //小树的指针指向大树
	}
	else
	{
		s[root1] += s[root2];
		s[root2] = root1;
	}
}

//优化查操作 先查找到根结点，然后压缩路径
int find1(int s[], int x)  //x表示所查结点的数组下标
{
	int root = x;
	while (s[root] >= 0)  //非根结点
	{
		root = s[root];    //一直寻找，直到找到根结点，root为根结点数组下标
	}
	while (x != root)
	{
		int t = s[x];  //暂存x上一个父节点数组下标 
		s[x] = root;   //将x的父节点直接指向根结点
		x = t;         //让x的上一个父节点继续同样的操作
	}
	return root;       //返回根结点数组下标，也就是表示属于那个集合
}


//int main()
//{
//	int a[size];
//	initial(a);   //地址传递
//	Print(a);
//
//	system("pause");
//	return 0;
//}