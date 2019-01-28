/*
Monge阵列是一个m*n的实数矩阵，满足以下性质:
    对1<=i<=k<=m,1<=j<=l<=n,
    A[i,j]+A[k,l]<=A[i,l]+A[k,j]
	即对于A的子矩阵，其左上与右下元素之和总小于等于左下与右上元素之和

Monge矩阵的另一性质：
    令f(i)表示第i行的最左最小元素的列下标，则f(1)<=f(2)<=...f(m)
	利用这个性质可以分治求出monge阵列的所有最左最小元素。

*/
#include<iostream>
#include<Windows.h>
using namespace std;
//伪码 
/*
Find_Min_Left(A,pos)
    A'=Devide_Monge(A)
	Find_Min_Left(A',pos)
	for(i=1 to m)
	    for(j=pos[i-1] to pos[i+1])
		    pos[i]=the min pos j for A[i][j]
*/
void calculate(double **A, int r1, int r2, int min, int max, int *f)	//计算f(r1)到f(r2)

{

	if (r1 > r2)return;

	int r = (r1 + r2) / 2;

	int result = min;

	int flag = A[r][min];

	for (int i = min + 1; i <= max; i++)	//寻找最左最小元素flag，和它的的下标result

	{

		if (A[r][i] < flag)

		{

			flag = A[r][i];

			result = i;

		}

	}

	f[r] = result;

	calculate(A, r1, r - 1, min, result, f);

	calculate(A, r + 1, r2, result, max, f);

}



bool isMonge(double **A, int m, int n)	//判断是否是Monge矩阵

{

	for (int i = 0; i < m - 1; i++)for (int j = 0; j < n - 1; j++)if (A[i][j] + A[i + 1][j + 1] > A[i + 1][j] + A[i][j + 1])return false;

	return true;

}

int main()

{

	int m, n;

	while (cin >> m >> n && m > 1 && n > 1)

	{

		double **A = new double*[m];		//Monge矩阵

		int *f = new int[m];	//不需要在主函数里面进行初始化，这个工作由calculate函数完成

		for (int i = 0; i < m; i++)

		{

			A[i] = new double[n];

			for (int j = 0; j < n; j++)cin >> A[i][j];

		}

		if (isMonge(A, m, n))

		{

			cout << "这个是Monge矩阵" << endl;

			calculate(A, 0, m - 1, 0, n - 1, f);

			for (int i = 0; i < m; i++)cout << "第" << i << "行的最左最小元素的列下标是" << f[i] << endl;

		}

		else cout << "这个不是Monge矩阵";

	}

	return 0;

}
