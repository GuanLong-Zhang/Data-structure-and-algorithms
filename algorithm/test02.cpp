# include<iostream>
using namespace std;

# define maxsize 10   //默认最大容量

//静态存储顺序表

struct sqlist1
{
	int data[maxsize];
	int length;
};

void initlist1(sqlist1& l)
{
	l.length = 0;     //长度初始化
}

void fuzhi1(sqlist1& l)
{
	for (int i = 0; i < maxsize/2; i++)    //对一半的内存空间进行赋值
	{
		l.data[i] = i;
		l.length++;
	}
}

bool listinsert1(sqlist1& l, int i, int e)   //插入操作 先后移再插入
{
	if (l.length >= maxsize)
	{
		return false;
	}
	if (i<1 || i>maxsize+1)   //这样的话存在空位置，这就导致不连续了
	{
		return false;
	}
	for (int j = l.length; i <= j; j--)
	{
		l.data[j] = l.data[j-1];
	}
	l.data[i-1] = e;
	l.length++;
	return true;

}

bool listdelete1(sqlist1& l, int i, int &e)   //删除操作  将删除的内容返回
{
	if (i>l.length||i<1 )   //删除第0个或者删除比最后还大的数就不合法了
	{
		return false;
	}
	e = l.data[i - 1];
	for (int j=i;j<l.length;j++)
	{
		l.data[j-1] = l.data[j];
	}
	l.length--;
	return true;

}

void testlistdelete1(sqlist1&l,int i,int e)
{
	if (listdelete1(l, i, e))   
	{
		cout << "被删除的值e为：" << e << endl;
	}
	else
	{
		cout << "删除失败！" << endl;
	}
}

int getelem1(sqlist1 l, int i)    //按位查找
{
	return l.data[i - 1];
}

int locateelem1(sqlist1 l, int i)   //按值查找   返回对应值的位序
{
	for (int j = 0; j < l.length; j++)
	{
		if (l.data[j] == i)
		{
			return j + 1;
		}	
	}
	cout <<"查找失败" << endl;
	return 0;
}

void printlist1(sqlist1& l)
{
	cout << "输出结果为：" << endl;
	for (int i = 0; i < l.length; i++)    
	{
		cout << l.data[i] << endl;
	}
}

//int main()
//{
//	struct sqlist1 l;
//	initlist1(l); 
//	fuzhi1(l);
//	printlist1(l);  
//	cout<<"插入是否正确？"<<listinsert1(l, 3, 0) << endl;   //在第三个位置插入0
//	printlist1(l);
//	int e = 0;   //初始化e并赋值为0
//	testlistdelete1(l, 4, e);   //删除第四个位置的值，并将被删除的值进行返回
//	printlist1(l);
//	cout <<"第四个元素为："<< getelem1(l, 4) << endl;   //查找第四个数据 按位查找   
//	cout <<"数字3在：第"<< locateelem1(l, 3) <<"位" << endl;    //查找2对应的位序   按值查找
//
//	system("pause");
//	return 0;
//}

