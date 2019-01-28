/*
Monge������һ��m*n��ʵ������������������:
    ��1<=i<=k<=m,1<=j<=l<=n,
    A[i,j]+A[k,l]<=A[i,l]+A[k,j]
	������A���Ӿ���������������Ԫ��֮����С�ڵ�������������Ԫ��֮��

Monge�������һ���ʣ�
    ��f(i)��ʾ��i�е�������СԪ�ص����±꣬��f(1)<=f(2)<=...f(m)
	����������ʿ��Է������monge���е�����������СԪ�ء�

*/
#include<iostream>
#include<Windows.h>
using namespace std;
//α�� 
/*
Find_Min_Left(A,pos)
    A'=Devide_Monge(A)
	Find_Min_Left(A',pos)
	for(i=1 to m)
	    for(j=pos[i-1] to pos[i+1])
		    pos[i]=the min pos j for A[i][j]
*/
void calculate(double **A, int r1, int r2, int min, int max, int *f)	//����f(r1)��f(r2)

{

	if (r1 > r2)return;

	int r = (r1 + r2) / 2;

	int result = min;

	int flag = A[r][min];

	for (int i = min + 1; i <= max; i++)	//Ѱ��������СԪ��flag�������ĵ��±�result

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



bool isMonge(double **A, int m, int n)	//�ж��Ƿ���Monge����

{

	for (int i = 0; i < m - 1; i++)for (int j = 0; j < n - 1; j++)if (A[i][j] + A[i + 1][j + 1] > A[i + 1][j] + A[i][j + 1])return false;

	return true;

}

int main()

{

	int m, n;

	while (cin >> m >> n && m > 1 && n > 1)

	{

		double **A = new double*[m];		//Monge����

		int *f = new int[m];	//����Ҫ��������������г�ʼ�������������calculate�������

		for (int i = 0; i < m; i++)

		{

			A[i] = new double[n];

			for (int j = 0; j < n; j++)cin >> A[i][j];

		}

		if (isMonge(A, m, n))

		{

			cout << "�����Monge����" << endl;

			calculate(A, 0, m - 1, 0, n - 1, f);

			for (int i = 0; i < m; i++)cout << "��" << i << "�е�������СԪ�ص����±���" << f[i] << endl;

		}

		else cout << "�������Monge����";

	}

	return 0;

}
