# include<iostream>
using namespace std;

# define maxsize 10   //Ĭ���������

//��̬�洢˳���

struct sqlist
{
	int data[maxsize];   
	int length;
};

void initlist(sqlist& l)
{
	for (int i = 0; i < maxsize; i++)
	{
		l.data[i] = 0;    //Ԫ�س�ʼ��
	}
	l.length = 0;     //���ȳ�ʼ��

}

void printlist(sqlist &l)
{
	cout << "������Ϊ��" << endl;
	for (int i = 0; i < l.length; i++)    //���С�ڳ��ȵ�����
	{
		cout << l.data[i] << endl;
	}
}

//int main()
//{
//	struct sqlist l;
//	//cout << "sizeof(l)=" << sizeof(l) << endl;
//	initlist(l);   //��ʼ��l  ���ô���
//	//printlist(l);  //���l
//
//	system("pause");
//	return 0;
//}

