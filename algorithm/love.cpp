# include<iostream>
using namespace std;

//�ݹ��㷨
void loveyou(int n)
{
	int i = 1;
	while (i <= n)
	{
		//i = i++;    //n   �𲽵�����
		i = i*2;      //log2n   �˷���
		cout << "I love you " << i << endl;

	}
	cout << "I love you more than " << n << endl;
}

//�ݹ����
void loveyou1(int n)
{
	if(n > 1)
	{
		loveyou1(n - 1);
	}
	cout << "I love you " << n << endl;  //�ݹ��������������Ϊ����С�������  ���ϵ��µݹ���ã�Ȼ���ٴ��µ��Ϸ���
}

//int main()
//{
//	//loveyou(3000);
//	loveyou1(5);
//	system("pause");
//	return 0;
//
//}