# include<iostream>
using namespace std;

//递归算法
void loveyou(int n)
{
	int i = 1;
	while (i <= n)
	{
		//i = i++;    //n   逐步递增型
		i = i*2;      //log2n   乘法型
		cout << "I love you " << i << endl;

	}
	cout << "I love you more than " << n << endl;
}

//递归调用
void loveyou1(int n)
{
	if(n > 1)
	{
		loveyou1(n - 1);
	}
	cout << "I love you " << n << endl;  //递归调用最后的输出结果为：从小到大输出  从上到下递归调用，然后再从下到上返回
}

//int main()
//{
//	//loveyou(3000);
//	loveyou1(5);
//	system("pause");
//	return 0;
//
//}