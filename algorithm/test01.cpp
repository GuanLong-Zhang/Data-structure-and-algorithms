# include<iostream>
using namespace std;

# define initsize 10  //默认最大长度

//动态存储顺序表

struct sqlist0
{
	int* data;      //指向动态数组的指针
	int maxsize;    //最大长度
	int length;     //当前长度

};

void initlist0(sqlist0& l)   //初始化
{
	//申请一片连续的存储空间
	l.data = (int*)malloc(initsize * sizeof(int));  //申请40字节的内存空间
	l.length = 0;
	l.maxsize = initsize;
}

void fuzhi0(sqlist0& l)
{
	for (int i = 0; i < l.maxsize; i++)
	{
		l.data[i] = i;
		l.length++;
	}

}

void printlist0(sqlist0& l)
{
	cout << "输出结果为：" << endl;
	for (int i = 0; i < l.length; i++)    //输出小于长度的内容
	{
		cout << l.data[i] << endl;
	}
}

void increasesize0(sqlist0& l,int len)   //增加动态数组长度
{
	int* p = l.data;
	l.data = (int*)malloc((l.maxsize + len) * sizeof(int));   //申请新的内存空间
	for (int i = 0; i < l.length; i++)
	{
		l.data[i] = p[i];  //将原先的内容赋给新的内存空间
	}
	l.maxsize = l.maxsize + len;
	free(p);   //释放原来的内存空间

}


//int main()
//{
//	struct sqlist0 l;
//	initlist0(l);
//	fuzhi0(l);
//	printlist0(l);
//	increasesize0(l, 5);
//	cout << "l.maxsize=" << l.maxsize << endl;
//	printlist0(l);
//
//
//	system("pause");
//	return 0;
//}