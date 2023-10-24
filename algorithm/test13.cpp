# include<iostream>
using namespace std;

//查找
//顺序查找，遍历

//折半查找，只适用于有序的顺序表（递增递减排序）
int binary_search_1(int a[], int key, int length)   //递增存储的顺序表,如果递减，逻辑就不对
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
	return -1;  //low>high时查找失败

}


//分块查找 块内无序，块间有序
//索引表用来记录每个分块的最大关键字和分块存储区间
typedef struct    //索引表
{
	int maxvalue;   //最大关键字
	int low, high;   //分块区间，下限和上限
}index;

//二叉排序树（二叉查找树）用于元素的有序组织和查找  BST
typedef struct bstnode
{
	int key;   //数据域
	struct bstnode* lchild, * rchild;   //指针域 左孩子指针和右孩子指针
}bstnode,*bstree;

//二叉排序树的查找   非递归查找
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

//二叉排序树的查找   递归查找   空间复杂度高
bstnode* bst_search_1(bstree T, int key)
{
	if (T == NULL)
	{
		return NULL;    //查找失败
	}
	if (key < T->key)
	{
		bst_search_1(T->lchild, key);   //左子树进行查找
	}
	else if (key > T->key)
	{
		bst_search_1(T->rchild, key);    //右子树进行查找
	}
	else
	{
		return T;       //查找成功
	}
}

//二叉排序树的插入  
int bst_insert(bstree& T, int key)   //插入涉及树的改变，所以进行引用传值，形参改变影响实参
{
	if (T == NULL)   //插入位置为空，开辟新结点
	{
		T = (bstnode*)malloc(sizeof(bstnode));
		T->key = key;
		T->lchild = T->rchild = NULL;
		return 1;  //插入成功
	}
	else if (key == T->key)
	{
		return 0;   //插入失败，因为树里不可以有相同的元素，所以插入失败
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

//二叉排序树的构造  调用插入操作  传入数组str
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

//平衡二叉树  AVL
typedef struct avlnode
{
	int key;   //数据域
	int balance;   //平衡因子   只能是 -1 0 1
	struct avlnode* lchild, * rchild;   //指针域 左右孩子指针
}avlnode,*avltree;

//红黑树  RBT
typedef struct rbtnode
{
	int key;   //数据域
	int color;  //结点颜色  只能是黑 红  用0/1表示
	struct rbtnode* lchild, * rchild, * parent;   //指针域 左 右孩子指针 以及父结点指针
}rbtnode,*rbtree;

//B树
//五叉查找树
struct node
{
	int key[4];     //四个关键字，分为5个分区
	struct node* child[5];   //5个孩子分支
	int num;        //结点中的关键字个数
};

//通过五叉查找树引入B树，需要满足两个特性，则将m叉查找树变为了m阶B树
//即除根结点外，任何结点至少有m/2取上限个分叉；对于任何一个结点，其所有子树高度相同；

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
//	cout << "所查元素在顺序表的第" << result << "个位置" << endl;
//
//	system("pause");
//	return 0;
//}