#include"Rand_Seq.h"
#include<iostream>
#include<Windows.h>
using namespace std;
//A是输入序列
//利用随机数将输入序列随机排列
int main()
{
	int A[]={12,4,56,2,35,76,343,6,8};
	const int n=9;
	Random_Sequence r(9,1,9*9*9);
	int *P=r.return_seq();
	int i, j;

	for (j = 1; j != n; j++) 
	{
		i = j - 1;
		int key = P[j];
		int temp=A[j];
		while (i >= 0 && P[i] > key)
		{
			P[i + 1] = P[i];
			A[i+1]=A[i];
			i = i - 1;
		}
		P[i + 1] = key;
		A[i+1]=temp;
	}
	for(auto elem:A)
	    cout<<elem<<"  ";
	cout<<endl;
	for(int k=0;k!=n;k++)
	    cout<<P[k]<<"  ";
	system("pause");
	return 0;
}