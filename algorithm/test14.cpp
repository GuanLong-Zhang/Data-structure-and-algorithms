#include<iostream>
using namespace std;

//����

//������
void print_result(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

//�����������    ��һ��λ�÷����ˣ�����Ԫ���Ǵ�1��ʼ
void print_heap(int a[], int n)
{
	for (int i = 1; i <n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}


//ֱ�Ӳ�������   ����ǰ���Ѿ��ź�������в��õ���˳�����
void insert_sort(int a[], int n)   //nΪ�������
{
	int i,j,temp;
	for (i = 1; i < n; i++)  //��λ��1��ʼ����
	{
		if (a[i - 1] > a[i])
		{
			temp = a[i];   //�����ݴ�
			for (j = i - 1; j >= 0 && a[j] > temp; j--)
			{
				a[j + 1] = a[j];   //����temp������
			}
			a[j + 1] = temp;   //����ѭ����jΪҪ�������ݵ�ǰһ��λ�ã�������Ҫ+1
		}
	}
}

//�۰��������  ����ǰ���Ѿ��ź�������в��õ����۰����
void insert_sort_1(int a[], int n)   //nΪ�������
{
	int i,j,temp,low,high,mid;
	for (i = 1; i < n; i++)  //��λ��1��ʼ����
	{
		if (a[i - 1] > a[i])
		{
			temp = a[i];   //�����ݴ�
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
			for (j = i - 1; j >= high+1; j--)    //����high�ܵ�low֮ǰ������Ҫ+1�ſ��Խ��бȽϣ�high+1��Ҫ�����λ�ã����Ա�����ڵ���;low=high+1
			{
				a[j + 1] = a[j];   //���ƿճ�����λ��
			}
			a[high + 1] = temp;   //����ѭ���󣬽�temp����high+1=low
		}
	}
}

//ϣ������  ͨ������d�����ӱ��Ƚ����ӱ������ֱ��dΪ1��  �Ȳ�������Ȼ����������
void shell_sort(int a[], int n)
{
	int d, temp, i, j;
	for (d = n / 2; d >= 1; d = d / 2)   //�����仯��ÿ����Сһ�룬ֱ��dΪ1
	{
		for (i = d; i < n; i++)    //����һ��Ԫ�ؽ��бȽϣ���Ϊi=0+d
		{
			if (a[i] < a[i-d])
			{
				temp = a[i];   //С���������ݴ�
				for (j = i - d; j >= 0 && a[j] > temp; j = j - d)
				{
					a[j + d] = a[j];   //��������
				}
				a[j+d] = temp;   //����ѭ����jΪ����λ�õ�ǰһ��λ�ã�������Ҫ+d������Ԫ�صĲ���
			}
		}
	}
}


//ð������  �����Աȣ���Ϊ�����򽻻����ǣ�ֱ�����бȽ���
void bubble_sort(int a[], int n)
{
	int i, j, temp;
	for (i = 0; i < n - 1; i++)    //��ѭ�� n-1��n�����Ƚ�n-1��
	{
		bool flag = false;   //����������ʶ��
		for (j = 0; j < n - 1 - i; j++)   //��ѭ��  ÿһ����Ҫ�ȽϵĴ��� n-1-i
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

//��������
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
	a[low] = pivot;  //low==high��ʱΪҪ�����λ��
	return low;      //���ز���λ��
}

void quick_sort(int a[], int low, int high)
{
	if (low < high)
	{
		int pivot=partition(a, low, high);   //ȷ������λ�ã���������
		quick_sort(a, low, pivot - 1);
		quick_sort(a, pivot + 1, high);
	}
}

//��ѡ������
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

//������
//���Ƚ���Ϊk����������Ϊ�����   ��׹����
void headadjust(int a[], int k, int n)
{
	a[0] = a[k];    //��k�����ݴ�
	for (int i = 2 * k; i <= n; i = i*2)
	{
		if (i < n && a[i] < a[i + 1])   //������С������������ָ��ָ��������
		{
			i++;
		}
		if (a[0] >= a[i])   //������ֵ���ڵ����������ֵ������
		{
			break;
		}
		else
		{
			a[k] = a[i];    //��������ֵ�滻����㣬ͬʱ�ı������ָ��k,����ָ����������λ�ã�������һ��ɸѡ
			k = i;
		}
	}
	a[k] = a[0];    //���ݴ��ֵ��������λ��
}

//���������
void buildmaxheap(int a[], int n)
{ 
	for (int i = n / 2; i > 0; i--)    //�����ķ��ն˽����й���
	{
		headadjust(a, i, n);
	}
}

//������
void heap_sort(int a[], int n)
{
	buildmaxheap(a, n);   //�Ƚ��������
	for (int i = n; i > 1; i--)   //�����һ��Ԫ�ؿ�ʼ
	{
		int temp = a[i];     //���Ѷ�Ԫ��a[1]�����һ��Ԫ��a[i]���л���
		a[i] = a[1];
		a[1] = temp;
		headadjust(a, 1, i - 1);   //����Ϊ�����  ��׹����
	}
}

//�鲢����

//�鲢����
void merge(int a[], int low, int mid, int high)
{
	int* b = (int*)malloc((high - low + 1) * sizeof(int));   //��������
	int i, j, k;
	for (k = low; k <= high; k++)
	{
		b[k] = a[k];     //��a��ֵ���Ƶ�����������
	}
	for (i = low, j = mid + 1, k = i; i <= mid && j <= high;)
	{
		if (b[i] <= b[j])
		{
			a[k] = b[i];    //��ֵ���Ӧָ���������
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
	while (i <= mid)    //����ѭ����˵��ĳһ�����Ѿ�������������Ҫ�����������е�ʣ��Ԫ��ȫ������ԭ����
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

//����
void merge_sort(int a[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;   //�м仮��
		merge_sort(a, low, mid);      //�󲿷� ���鲢�ݹ�
		merge_sort(a, mid + 1, high); //�Ҳ��֣��鲢�ݹ�
		merge(a, low, mid, high);     //�鲢
	}

}

//��������

//�Ը������鸳ֵ
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
	
	//insert_sort(a, len);    //ֱ�Ӳ�������
	//print_result(a, len);
	
	//insert_sort_1(a, len);  //�۰��������
	//print_result(a, len);
	
	//shell_sort(a, len);     //ϣ������
	//print_result(a, len);
	
	//bubble_sort(a, len);      //ð������
	//print_result(a, len);
	
	//int low = 0;
	//int high = len - 1;
	//quick_sort(a, low, high);   //��������
	//print_result(a, len);
	
	//select_sort(a, len);         //��ѡ������
	//print_result(a, len);

	//int* b = (int*)malloc((len + 1) * sizeof(int));      //��һ��Ԫ�ؿճ����������飬��СΪlen+1
	//help_array(a, b, len);
	//heap_sort(b,len);      //������
	//print_heap(b,len+1);

	int low = 0;
	int high = len - 1;
	merge_sort(a, low, high);   //�鲢����
	print_result(a, len);

	system("pause");
	return 0;
}