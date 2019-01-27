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
void Find_Min_Left(int **A,int m,int n, int pos[], int row[])
/*
pos[i]表示第i行最左最小元素的位置
row[]用以表示子矩阵A'
*/
{
	for (int i = 0; i != m; i = 2 * i) {
		row[i]=true;
	}
	Find_Min_Left(A,m,n,pos,row);
	for (int j = 0; j != m; j++) {
		if (row[j] == true) {
			for (int temp=0,int k = pos[j - 1], int end = pos[j + 1]; k != end; k++) {
				if (A[j][k] <= temp) {
					temp=A[j][k];
					pos[j]=k;
				}
			}
		}
	}

}