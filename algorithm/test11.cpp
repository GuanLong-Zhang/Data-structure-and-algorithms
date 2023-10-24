#include<iostream>
using namespace std;

//���鼯
#define size 13

//��ʼ�����鼯
void initial(int s[])
{
	for (int i = 0; i < size; i++)
	{
		s[i] = -1;    //����s�д洢���Ǹ��ڵ�ָ�룬Ҳ���������±꣬���������洢��˫�ױ�ʾ��
	}
}

//��ӡ���
void Print(int s[])
{

	for (int i = 0; i < size; i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;

}

//�����
int Find(int s[], int x)   //x��ʾ������������±�
{
	while (s[x] >= 0)   //���ڵ�ָ����ڵ���0��˵����û���ҵ������
	{
		x = s[x];       //һֱѰ�ң�ֱ���ҵ������
	}
	return x;   //�����Ԫ�������±�
}

//������
void Union(int s[], int root1, int root2)   //root1 root2��ʾ�������ϸ����������±�
{
	if (root1 == root2)   //����������ͬһ������
	{
		return;  //���ؿ�
	}
	s[root1] = root2;  //��root1�ӵ�root2�ĺ��棬��Ϊһ���Ӽ�
}

//�Ż�������   �ؼ�������С���ϲ��������������Ϳ��Ա�֤���ĸ߶Ȳ��ᷢ���任���������ڲ�ѯ���ԣ�ʱ�临�ӶȾͻ����С
void Union1(int s[], int root1, int root2)   //s[]��ŵ��Ǹ��ڵ��ָ�룬ͬʱ���ڸ���������ֵ��ʾ���ĸ���,û���Ż�ʱ���������ֵΪ1
{
	if (root1 == root2)
	{
		return;
	}
	if (s[root1] > s[root2])   //root�����Ÿ�ֵ������˭�󷴶�����Ľ�����٣�������ٵľ���С�����������ľ��Ǵ���
	{
		s[root2] += s[root1];   //�Խ�����������,ͨ����������жϴ�С��   
		s[root1] = root2;       //С����ָ��ָ�����
	}
	else
	{
		s[root1] += s[root2];
		s[root2] = root1;
	}
}

//�Ż������ �Ȳ��ҵ�����㣬Ȼ��ѹ��·��
int find1(int s[], int x)  //x��ʾ������������±�
{
	int root = x;
	while (s[root] >= 0)  //�Ǹ����
	{
		root = s[root];    //һֱѰ�ң�ֱ���ҵ�����㣬rootΪ����������±�
	}
	while (x != root)
	{
		int t = s[x];  //�ݴ�x��һ�����ڵ������±� 
		s[x] = root;   //��x�ĸ��ڵ�ֱ��ָ������
		x = t;         //��x����һ�����ڵ����ͬ���Ĳ���
	}
	return root;       //���ظ���������±꣬Ҳ���Ǳ�ʾ�����Ǹ�����
}


//int main()
//{
//	int a[size];
//	initial(a);   //��ַ����
//	Print(a);
//
//	system("pause");
//	return 0;
//}