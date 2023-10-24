# include<iostream>
using namespace std;

# define maxsize 10   //Ĭ���������

//��̬�洢˳���

struct sqlist1
{
	int data[maxsize];
	int length;
};

void initlist1(sqlist1& l)
{
	l.length = 0;     //���ȳ�ʼ��
}

void fuzhi1(sqlist1& l)
{
	for (int i = 0; i < maxsize/2; i++)    //��һ����ڴ�ռ���и�ֵ
	{
		l.data[i] = i;
		l.length++;
	}
}

bool listinsert1(sqlist1& l, int i, int e)   //������� �Ⱥ����ٲ���
{
	if (l.length >= maxsize)
	{
		return false;
	}
	if (i<1 || i>maxsize+1)   //�����Ļ����ڿ�λ�ã���͵��²�������
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

bool listdelete1(sqlist1& l, int i, int &e)   //ɾ������  ��ɾ�������ݷ���
{
	if (i>l.length||i<1 )   //ɾ����0������ɾ������󻹴�����Ͳ��Ϸ���
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
		cout << "��ɾ����ֵeΪ��" << e << endl;
	}
	else
	{
		cout << "ɾ��ʧ�ܣ�" << endl;
	}
}

int getelem1(sqlist1 l, int i)    //��λ����
{
	return l.data[i - 1];
}

int locateelem1(sqlist1 l, int i)   //��ֵ����   ���ض�Ӧֵ��λ��
{
	for (int j = 0; j < l.length; j++)
	{
		if (l.data[j] == i)
		{
			return j + 1;
		}	
	}
	cout <<"����ʧ��" << endl;
	return 0;
}

void printlist1(sqlist1& l)
{
	cout << "������Ϊ��" << endl;
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
//	cout<<"�����Ƿ���ȷ��"<<listinsert1(l, 3, 0) << endl;   //�ڵ�����λ�ò���0
//	printlist1(l);
//	int e = 0;   //��ʼ��e����ֵΪ0
//	testlistdelete1(l, 4, e);   //ɾ�����ĸ�λ�õ�ֵ��������ɾ����ֵ���з���
//	printlist1(l);
//	cout <<"���ĸ�Ԫ��Ϊ��"<< getelem1(l, 4) << endl;   //���ҵ��ĸ����� ��λ����   
//	cout <<"����3�ڣ���"<< locateelem1(l, 3) <<"λ" << endl;    //����2��Ӧ��λ��   ��ֵ����
//
//	system("pause");
//	return 0;
//}

