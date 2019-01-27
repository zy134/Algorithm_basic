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
void Find_Min_Left(int **A,int m,int n, int pos[], int row[])
/*
pos[i]��ʾ��i��������СԪ�ص�λ��
row[]���Ա�ʾ�Ӿ���A'
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