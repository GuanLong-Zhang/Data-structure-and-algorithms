#include<iostream>
using namespace std;

# define Maxsize 10    //�궨�岻��Ҫ�ӷֺ�
//��̬����
struct node
{
	int data;   //������
	int next;   //�α�  ָ����һ��Ԫ�ص������±�
};

typedef struct
{
	int data;
	int next;
}slinklist[Maxsize];

void testslinklist()
{
	struct node a;      //�������
	cout << sizeof(a) << endl;

	struct node b[Maxsize];   //�������
	cout << sizeof(b) << endl;

	slinklist c;    //�������
	cout << sizeof(c) << endl;
}



//int main()
//{
//	testslinklist();
//	system("pause");
//	return 0;
//}