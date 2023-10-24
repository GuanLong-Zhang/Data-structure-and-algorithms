#include<iostream>
using namespace std;

# define MaxSize 255

//����˳��洢
typedef struct
{
	char a[MaxSize];    //��̬����  �洢�ַ�    //�ŵ㣺�����ȡ���ʺϲ��ң�  ȱ�㣺���룬ɾ����̫����
	int length;         //���ĳ���
}SString;

typedef struct
{
	char* ch;       //��̬����   ���Ļ���ַ
	int length;
}HString;

//������ʽ�洢
typedef struct stingnode
{
	char ch;                    //������   һ�����һ���ַ�       �洢�ܶȵ�
	struct strintnode* next;    //ָ����
}stringnode,*string;

typedef struct stringnode1       //�Ƽ���ʽ
{
	char ch[4];                  //������   һ���������ַ���Խ��Խ�ã�     �洢�ܶ������
	struct stringnode1* next;    //ָ����
}stringnode1,*string1;

//���Ӵ�  ˳��洢  ��̬����
bool substring(SString& sub, SString s, int pos, int len)   //�ӵڼ���λ��ȡ���ٳ��ȣ���Ϊ�Ӵ�
{
	if ((pos + len - 1) > s.length)    //��ֹ���ȹ�����������Χ    �����һ��λ�ò��洢Ԫ�أ��ӵڶ���λ�ÿ�ʼ��ȡ��Ҳ���Ǵ��±�Ϊ1��λ�ý��д�ȡ
	{
		return false;
	}
	for (int i = pos; i < pos + len; i++)
	{
		sub.a[i - pos + 1] = s.a[i];   //������ֵ

	}
	sub.length = len;
	return true;
}

//�Ƚϴ�С
int strcompare(SString s, SString t)
{
	for (int i = 1; i < s.length && i < t.length; i++)     //�������±�1��ʼ���б���   
	{
		if (s.a[i] != t.a[i])
		{
			return s.a[i] - t.a[i];    // ����0  ���� С��0
		}
	}
	return s.length - t.length;    //ÿһλ����ȣ���ô���ȳ��ľʹ�
}

//��λ����   �����Ͼ��ǽ� ȡ�Ӵ� �Ƚ� �����ں�
int index(SString s, SString t)
{
	int i = 1;
	int n = s.length;     //����һ����7  һ����3  ��ô�Ϳ����ƶ�5�βſ���ȡ�����е�������3
	int m = t.length;
	SString sub;    //������ʱ�洢�Ӵ�
	while (i <=  n - m + 1) 
	{
		substring(sub, s, i, m);  //�����������Ӵ�
		if (strcompare(sub, t) != 0)    //�����  ����ѭ��
		{
			++i;
		}
		else    //��� �����±�
		{
			return i;
		}
	}
	return 0;   //ʧ��
}

//����ģʽƥ���㷨  �㷨˼��Ͷ�λ�㷨����  ������ȥʵ��ƥ��
int index1(SString s, SString t)    //����s��ʾ���� t��ʾģʽ�� ��Ҫ���������ҵ���ģʽ��ƥ����Ӵ����������±���з���
{
	int i = 1, j = 1;   //i��������ָ�� j��ģʽ����ָ��
	while (i <= s.length && j <= t.length)
	{
		if (s.a[i] == t.a[j])   //��Ⱥ���ָ�룬���к�����ƥ��
		{
			++i;    //�ƶ�ָ��
			++j;
		}
		else      //����ȣ�����ָ��ظ�����һ���Ӵ�����ʼλ�����½���ƥ��   ģʽ��ָ���Ϊ1  
		{
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > t.length)    //ƥ��ɹ�  �����Ӵ���һ�����±�
	{
		return i - t.length;
	}
	else
	{
		return 0;     //ƥ��ʧ��
	}
}

//KMP�㷨  ����ģʽƥ���㷨�ĸĽ�
int index1_kmp(SString s, SString t, int next[])    //ģʽƥ�䲿��
{
	int i = 1, j = 1;
	while (i <= s.length && j <= t.length)
	{
		if (j == 0 || s.a[i] == t.a[j])  //jΪ0 ���� ������ȵ�ʱ�����ָ��ĺ���
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];    //next�������ڴ��j��λ��   i���ֲ��� ֻ�ı�j��ֵ �˴�next������Ҫ����ģʽ�������ͽ����ֶ�����
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

//�Ż�KMP�㷨  �����Ͼ����Ż�next���飬��next����ת��Ϊnextval����,�õ�nextval����󣬽��䴫��ģʽƥ���㷨��
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
//	//��̬����
//	HString S;   //ʵ����
//	S.ch = (char*)malloc(MaxSize * sizeof(char));   //��̬�����С
//	S.length = 0;
//	
//
//}