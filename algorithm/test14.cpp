#include<iostream>
using namespace std;

//排序

//输出结果
void print_result(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

//输出堆排序结果    第一个位置废弃了，所以元素是从1开始
void print_heap(int a[], int n)
{
	for (int i = 1; i <n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}


//直接插入排序   对于前面已经排好序的序列采用的是顺序查找
void insert_sort(int a[], int n)   //n为数组个数
{
	int i,j,temp;
	for (i = 1; i < n; i++)  //从位置1开始排序
	{
		if (a[i - 1] > a[i])
		{
			temp = a[i];   //数据暂存
			for (j = i - 1; j >= 0 && a[j] > temp; j--)
			{
				a[j + 1] = a[j];   //大于temp的右移
			}
			a[j + 1] = temp;   //跳出循环后，j为要插入数据的前一个位置，所以需要+1
		}
	}
}

//折半插入排序  对于前面已经排好序的序列采用的是折半查找
void insert_sort_1(int a[], int n)   //n为数组个数
{
	int i,j,temp,low,high,mid;
	for (i = 1; i < n; i++)  //从位置1开始排序
	{
		if (a[i - 1] > a[i])
		{
			temp = a[i];   //数据暂存
			low = 0;
			high = i - 1;
			while (low <= high)
			{
				mid = (low + high) / 2;
				if (a[mid] > temp)
				{
					high = mid - 1;
				}
				else
				{
					low = mid + 1;
				}
			}
			for (j = i - 1; j >= high+1; j--)    //由于high跑到low之前，所以要+1才可以进行比较，high+1是要插入的位置，所以必须大于等于;low=high+1
			{
				a[j + 1] = a[j];   //右移空出插入位置
			}
			a[high + 1] = temp;   //跳出循环后，将temp插入high+1=low
		}
	}
}

//希尔排序  通过增量d构建子表，先进行子表的排序，直到d为1。  先部分有序，然后整体有序
void shell_sort(int a[], int n)
{
	int d, temp, i, j;
	for (d = n / 2; d >= 1; d = d / 2)   //增量变化，每次缩小一半，直到d为1
	{
		for (i = d; i < n; i++)    //从下一个元素进行比较，即为i=0+d
		{
			if (a[i] < a[i-d])
			{
				temp = a[i];   //小的数进行暂存
				for (j = i - d; j >= 0 && a[j] > temp; j = j - d)
				{
					a[j + d] = a[j];   //数据右移
				}
				a[j+d] = temp;   //跳出循环，j为插入位置的前一个位置，所以需要+d，进行元素的插入
			}
		}
	}
}


//冒泡排序  两两对比，若为逆序，则交换他们，直到序列比较完
void bubble_sort(int a[], int n)
{
	int i, j, temp;
	for (i = 0; i < n - 1; i++)    //外循环 n-1；n个数比较n-1趟
	{
		bool flag = false;   //发生交换标识符
		for (j = 0; j < n - 1 - i; j++)   //内循环  每一趟需要比较的次数 n-1-i
		{
			if (a[j + 1 ]< a[j])
			{
				temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
				flag = true;
			}
		}
		if (flag == false)
		{
			return;
		}
	}
}

//快速排序
int partition(int a[], int low, int high)
{
	int pivot = a[low];
	while (low < high)
	{
		while (low < high&&a[high]>=pivot)
		{
			high--;
		}
		a[low] = a[high];
		while (low < high && a[low] <= pivot)
		{
			low++;
		}
		a[high] = a[low];
	}
	a[low] = pivot;  //low==high此时为要插入的位置
	return low;      //返回插入位置
}

void quick_sort(int a[], int low, int high)
{
	if (low < high)
	{
		int pivot=partition(a, low, high);   //确定插入位置，划分左右
		quick_sort(a, low, pivot - 1);
		quick_sort(a, pivot + 1, high);
	}
}

//简单选择排序
void select_sort(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[i])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

//堆排序
//首先将根为k的子树调整为大根堆   下坠调整
void headadjust(int a[], int k, int n)
{
	a[0] = a[k];    //将k进行暂存
	for (int i = 2 * k; i <= n; i = i*2)
	{
		if (i < n && a[i] < a[i + 1])   //左子树小于右子树，将指针指向右子树
		{
			i++;
		}
		if (a[0] >= a[i])   //根结点的值大于等于子树结点值，结束
		{
			break;
		}
		else
		{
			a[k] = a[i];    //用子树的值替换根结点，同时改变根结点的指向k,将其指向子树结点的位置，进行下一步筛选
			k = i;
		}
	}
	a[k] = a[0];    //将暂存的值放入最后的位置
}

//建立大根堆
void buildmaxheap(int a[], int n)
{ 
	for (int i = n / 2; i > 0; i--)    //从最后的非终端结点进行构建
	{
		headadjust(a, i, n);
	}
}

//堆排序
void heap_sort(int a[], int n)
{
	buildmaxheap(a, n);   //先建立大根堆
	for (int i = n; i > 1; i--)   //从最后一个元素开始
	{
		int temp = a[i];     //将堆顶元素a[1]和最后一个元素a[i]进行互换
		a[i] = a[1];
		a[1] = temp;
		headadjust(a, 1, i - 1);   //调整为大根堆  下坠调整
	}
}

//归并排序

//归并操作
void merge(int a[], int low, int mid, int high)
{
	int* b = (int*)malloc((high - low + 1) * sizeof(int));   //辅助数组
	int i, j, k;
	for (k = low; k <= high; k++)
	{
		b[k] = a[k];     //将a的值复制到辅助数组中
	}
	for (i = low, j = mid + 1, k = i; i <= mid && j <= high;)
	{
		if (b[i] <= b[j])
		{
			a[k] = b[i];    //赋值后对应指针进行右移
			k++;
			i++;
		}
		else
		{
			a[k] = b[j];     
			k++;
			j++;
		}
	}
	while (i <= mid)    //跳出循环，说明某一部分已经结束，所以需要将辅助数组中的剩余元素全部赋给原数组
	{
		a[k] = b[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		a[k] = b[j];
		k++;
		j++;
	}
}

//排序
void merge_sort(int a[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;   //中间划分
		merge_sort(a, low, mid);      //左部分 ，归并递归
		merge_sort(a, mid + 1, high); //右部分，归并递归
		merge(a, low, mid, high);     //归并
	}

}

//基数排序
//外部排序


//对辅助数组赋值
void help_array(int a[], int b[],int n)
{
	b[0] = NULL;
	for (int i = 1; i < n + 1; i++)
	{
		b[i] = a[i-1];
	}

}

int main()
{
	int a[] = { 38,49,65,97,76,13,27,49 };
	int len = sizeof(a) / sizeof(int);
	//cout << len << endl;
	
	//insert_sort(a, len);    //直接插入排序
	//print_result(a, len);
	
	//insert_sort_1(a, len);  //折半插入排序
	//print_result(a, len);
	
	//shell_sort(a, len);     //希尔排序
	//print_result(a, len);
	
	//bubble_sort(a, len);      //冒泡排序
	//print_result(a, len);
	
	//int low = 0;
	//int high = len - 1;
	//quick_sort(a, low, high);   //快速排序
	//print_result(a, len);
	
	//select_sort(a, len);         //简单选择排序
	//print_result(a, len);

	//int* b = (int*)malloc((len + 1) * sizeof(int));      //第一个元素空出，辅助数组，大小为len+1
	//help_array(a, b, len);
	//heap_sort(b,len);      //堆排序
	//print_heap(b,len+1);

	int low = 0;
	int high = len - 1;
	merge_sort(a, low, high);   //归并排序
	print_result(a, len);

	system("pause");
	return 0;
}