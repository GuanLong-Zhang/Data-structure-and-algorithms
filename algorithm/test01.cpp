# include<iostream>
using namespace std;

# define initsize 10  //Ĭ����󳤶�

//��̬�洢˳���

struct sqlist0
{
	int* data;      //ָ��̬�����ָ��
	int maxsize;    //��󳤶�
	int length;     //��ǰ����

};

void initlist0(sqlist0& l)   //��ʼ��
{
	//����һƬ�����Ĵ洢�ռ�
	l.data = (int*)malloc(initsize * sizeof(int));  //����40�ֽڵ��ڴ�ռ�
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
	cout << "������Ϊ��" << endl;
	for (int i = 0; i < l.length; i++)    //���С�ڳ��ȵ�����
	{
		cout << l.data[i] << endl;
	}
}

void increasesize0(sqlist0& l,int len)   //���Ӷ�̬���鳤��
{
	int* p = l.data;
	l.data = (int*)malloc((l.maxsize + len) * sizeof(int));   //�����µ��ڴ�ռ�
	for (int i = 0; i < l.length; i++)
	{
		l.data[i] = p[i];  //��ԭ�ȵ����ݸ����µ��ڴ�ռ�
	}
	l.maxsize = l.maxsize + len;
	free(p);   //�ͷ�ԭ�����ڴ�ռ�

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