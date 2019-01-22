#include<iostream>
#include<Windows.h>
using namespace std;
void Insert_sort(int A[], int p, int r) 
{
	for (int j = p + 1; j != r + 1; j++)
	{
		int key=A[j];
		int i=j-1;
		while (A[i] >key && i >= 0)
		{
			A[i+1]=A[i];
			i=i-1;
		}
		A[i+1]=key;
	}
}

void Merge(int A[], int p, int q, int r)
{
    int length=r-p+1;
	int *Temp=new int[length];
	int i=p,j=q+1,k;
	for (k = 0; k != length,i<=q,j<=r; k++)
	{
		if (A[i] < A[j])
		{
			Temp[k]=A[i];
			i++;
		}
		else
		{
			Temp[k]=A[j];
			j++;
		}
	}
	if(i<=q)
	while(i!=q+1)
	    Temp[k++]=A[i++];
	else
	while(j!=r+1)
	    Temp[k++]=A[j++];

	for(k=0;k!=length-1;k++)
	    A[p+k]=Temp[k];
	delete Temp;

}
void Merge_Sort(int A[], int p, int r)
{
	if (p < r)
	{
		if(p-r<4)
		Insert_sort(A,p,r);
		else 
		{
			int q=(p+r)/2;
			Merge_Sort(A,p,q);
			Merge_Sort(A,q+1,r);
			Merge(A,p,q,r);
		}
	}
}
int main()
{
    int A[]={3,21,4,5,67,45,222,8,98};
	int p=0,r=8;
	Merge_Sort(A,p,r);
	for(auto elem:A)
	    cout<<"  "<<elem;
	system("pause");
	return 0;
}