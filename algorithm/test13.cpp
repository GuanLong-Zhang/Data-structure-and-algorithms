# include<iostream>
using namespace std;

//����
//˳����ң�����

//�۰���ң�ֻ�����������˳��������ݼ�����
int binary_search_1(int a[], int key, int length)   //�����洢��˳���,����ݼ����߼��Ͳ���
{
	int low, mid, high;
	low = 0;
	high = length - 1;
	while (low <= high)
	{
		mid = (high + low) / 2;
		if (a[mid] == key)
		{
			return mid;
		}
		else if(a[mid] > key)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return -1;  //low>highʱ����ʧ��

}


//�ֿ���� �������򣬿������
//������������¼ÿ���ֿ�����ؼ��ֺͷֿ�洢����
typedef struct    //������
{
	int maxvalue;   //���ؼ���
	int low, high;   //�ֿ����䣬���޺�����
}index;

//���������������������������Ԫ�ص�������֯�Ͳ���  BST
typedef struct bstnode
{
	int key;   //������
	struct bstnode* lchild, * rchild;   //ָ���� ����ָ����Һ���ָ��
}bstnode,*bstree;

//�����������Ĳ���   �ǵݹ����
bstnode* bst_search(bstree T, int key)
{
	while (T != NULL && key != T->key)
	{
		if (key < T->key)
		{
			T = T->lchild;
		}
		else
		{
			T = T->rchild;
		}
	}
	return T;
}

//�����������Ĳ���   �ݹ����   �ռ临�Ӷȸ�
bstnode* bst_search_1(bstree T, int key)
{
	if (T == NULL)
	{
		return NULL;    //����ʧ��
	}
	if (key < T->key)
	{
		bst_search_1(T->lchild, key);   //���������в���
	}
	else if (key > T->key)
	{
		bst_search_1(T->rchild, key);    //���������в���
	}
	else
	{
		return T;       //���ҳɹ�
	}
}

//�����������Ĳ���  
int bst_insert(bstree& T, int key)   //�����漰���ĸı䣬���Խ������ô�ֵ���βθı�Ӱ��ʵ��
{
	if (T == NULL)   //����λ��Ϊ�գ������½��
	{
		T = (bstnode*)malloc(sizeof(bstnode));
		T->key = key;
		T->lchild = T->rchild = NULL;
		return 1;  //����ɹ�
	}
	else if (key == T->key)
	{
		return 0;   //����ʧ�ܣ���Ϊ���ﲻ��������ͬ��Ԫ�أ����Բ���ʧ��
	}
	else if (key < T->key)
	{
		bst_insert(T->lchild, key);
	}
	else
	{
		bst_insert(T->rchild, key);
	}
}

//�����������Ĺ���  ���ò������  ��������str
void creat_bstree(bstree& T, int str[], int n)
{
	T = NULL;
	int i = 0;
	while(i < n)
	{
		bst_insert(T, str[i]);
		i++;
	}
}

//ƽ�������  AVL
typedef struct avlnode
{
	int key;   //������
	int balance;   //ƽ������   ֻ���� -1 0 1
	struct avlnode* lchild, * rchild;   //ָ���� ���Һ���ָ��
}avlnode,*avltree;

//�����  RBT
typedef struct rbtnode
{
	int key;   //������
	int color;  //�����ɫ  ֻ���Ǻ� ��  ��0/1��ʾ
	struct rbtnode* lchild, * rchild, * parent;   //ָ���� �� �Һ���ָ�� �Լ������ָ��
}rbtnode,*rbtree;

//B��
//��������
struct node
{
	int key[4];     //�ĸ��ؼ��֣���Ϊ5������
	struct node* child[5];   //5�����ӷ�֧
	int num;        //����еĹؼ��ָ���
};

//ͨ��������������B������Ҫ�����������ԣ���m���������Ϊ��m��B��
//����������⣬�κν��������m/2ȡ���޸��ֲ棻�����κ�һ����㣬�����������߶���ͬ��

//int main()
//{
//	int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	//cout << sizeof(a) / 4 << endl;
//	//for (int i = 0; i < sizeof(a) / 4; i++)
//	//{
//	//	cout << a[i] << " ";
//	//}
//	//cout << endl;
//	int result = binary_search_1(a, 8, sizeof(a)/4);
//	cout << "����Ԫ����˳���ĵ�" << result << "��λ��" << endl;
//
//	system("pause");
//	return 0;
//}