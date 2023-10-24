#include<iostream>
using namespace std;

# define MaxSize 255

//串的顺序存储
typedef struct
{
	char a[MaxSize];    //静态数组  存储字符    //优点：随机存取（适合查找）  缺点：插入，删除不太方便
	int length;         //串的长度
}SString;

typedef struct
{
	char* ch;       //动态数组   串的基地址
	int length;
}HString;

//串的链式存储
typedef struct stingnode
{
	char ch;                    //数据域   一个结点一个字符       存储密度低
	struct strintnode* next;    //指针域
}stringnode,*string;

typedef struct stringnode1       //推荐方式
{
	char ch[4];                  //数据域   一个结点存多个字符（越多越好）     存储密度提高了
	struct stringnode1* next;    //指针域
}stringnode1,*string1;

//求子串  顺序存储  静态数组
bool substring(SString& sub, SString s, int pos, int len)   //从第几个位置取多少长度，作为子串
{
	if ((pos + len - 1) > s.length)    //防止长度过长，超出范围    数组第一个位置不存储元素，从第二个位置开始存取，也就是从下标为1的位置进行存取
	{
		return false;
	}
	for (int i = pos; i < pos + len; i++)
	{
		sub.a[i - pos + 1] = s.a[i];   //数据域赋值

	}
	sub.length = len;
	return true;
}

//比较大小
int strcompare(SString s, SString t)
{
	for (int i = 1; i < s.length && i < t.length; i++)     //从数组下标1开始进行遍历   
	{
		if (s.a[i] != t.a[i])
		{
			return s.a[i] - t.a[i];    // 大于0  或者 小于0
		}
	}
	return s.length - t.length;    //每一位都相等，那么长度长的就大
}

//定位操作   本质上就是将 取子串 比较 进行融合
int index(SString s, SString t)
{
	int i = 1;
	int n = s.length;     //假设一个是7  一个是3  那么就可以移动5次才可以取完所有的连续的3
	int m = t.length;
	SString sub;    //用来暂时存储子串
	while (i <=  n - m + 1) 
	{
		substring(sub, s, i, m);  //从主串中找子串
		if (strcompare(sub, t) != 0)    //不相等  继续循环
		{
			++i;
		}
		else    //相等 返回下标
		{
			return i;
		}
	}
	return 0;   //失败
}

//朴素模式匹配算法  算法思想和定位算法类似  暴力法去实现匹配
int index1(SString s, SString t)    //其中s表示主串 t表示模式串 需要从主串中找到和模式串匹配的子串，并将其下标进行返回
{
	int i = 1, j = 1;   //i是主串的指针 j是模式串的指针
	while (i <= s.length && j <= t.length)
	{
		if (s.a[i] == t.a[j])   //相等后移指针，进行后续的匹配
		{
			++i;    //移动指针
			++j;
		}
		else      //不相等，主串指针回复到下一个子串的起始位置重新进行匹配   模式串指针变为1  
		{
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > t.length)    //匹配成功  返回子串第一个的下标
	{
		return i - t.length;
	}
	else
	{
		return 0;     //匹配失败
	}
}

//KMP算法  朴素模式匹配算法的改进
int index1_kmp(SString s, SString t, int next[])    //模式匹配部分
{
	int i = 1, j = 1;
	while (i <= s.length && j <= t.length)
	{
		if (j == 0 || s.a[i] == t.a[j])  //j为0 或者 数据相等的时候进行指针的后移
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];    //next数组用于存放j的位置   i保持不变 只改变j的值 此处next数组需要根据模式串的类型进行手动计算
		}
	}
	if (j > t.length)
	{
		return i - t.length;
	}
	else
	{
		return 0;
	}
}

//优化KMP算法  本质上就是优化next数组，将next数组转换为nextval数组,得到nextval数组后，将其传入模式匹配算法中
int* next2nextval(int next[], int nextval[], SString t)
{
	nextval[1] = 0;
	for (int j = 2; j <= t.length; j++)
	{
		if (t.a[j] == t.a[next[j]])
		{
			nextval[j] = nextval[next[j]];
		}
		else
		{
			nextval[j] = next[j];
		}
	}
	return nextval;
}



//int main()
//{
//	//动态数组
//	HString S;   //实例化
//	S.ch = (char*)malloc(MaxSize * sizeof(char));   //动态分配大小
//	S.length = 0;
//	
//
//}