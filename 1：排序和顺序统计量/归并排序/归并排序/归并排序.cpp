
/*
MERGE(A,p,q,r)
    n1=q-p-1
	n2=r-q
	let L[1,2...n1+1] and R[1,2...n2+1] be new array
	for i=1 to n1
	    L[i]=A[p+i]
	for j=1 to n2
	    R[j]=A[q+j]
    L[n1+1]=unlimited
	R[n2+1]=unlimited
	i=1,j=1
	for k=p to r
	    if L[i]<=R[j]
		    A[k]=L[i]
		    i=i+1
	    else
		    A[k]=R[j]
			j=j+1

MERGE_SORT(A,p,r)
    q=(p+r)/2
	MERGE_SORT(A,p,q)
	MERGE_SORT(A,q+1,r)
	MERGE(A,p,q,r)

*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

void PrintArr(int *pnArr, int nLen)
{
	for (int i = 0; i < nLen; i++)
	{
		printf("%d ", pnArr[i]);
	}
	printf("\n");
}
//合并两个数组
void Merge(int data[], int nLpos, int nRpos, int nRightEnd)
{
	int i;
	int k = nLpos;
	int nLeftEnd = nRpos;
	int nTmpPos = 0;
	int nLen = nRightEnd - nLpos + 1;
	int *pnArr = (int *)malloc(sizeof(int) * nLen);
	++nRpos;
	while (nLpos <= nLeftEnd && nRpos <= nRightEnd)
	{
		if (data[nLpos] <= data[nRpos])
		{
			pnArr[nTmpPos++] = data[nLpos++];
		}
		else
		{
			pnArr[nTmpPos++] = data[nRpos++];
		}
	}
	while (nLpos <= nLeftEnd)
	{
		pnArr[nTmpPos++] = data[nLpos++];
	}
	while (nRpos <= nRightEnd)
	{
		pnArr[nTmpPos++] = data[nRpos++];
	}

	nTmpPos = 0;
	for (i = k; i <= nRightEnd; i++)
	{
		data[i] = pnArr[nTmpPos++];
	}

	free(pnArr);
}
void MergeSort(int *pnArr, int nLeft, int nRight)
{
	if (nLeft > nRight)
	{
		return;
	}
	if (nRight > nLeft)
	{
		//1分解
		int nMid = (nLeft + nRight) / 2;

		//2解决
		MergeSort(pnArr, nLeft, nMid);
		MergeSort(pnArr, nMid + 1, nRight);

		//3合并
		Merge(pnArr, nLeft, nMid, nRight);
	}
}
int main()
{
	srand(time(NULL));
	int nArr[10];
	for (int i = 0; i < 10; i++)
	{
		nArr[i] = rand() % 100;
	}

	printf("排序前:");
	PrintArr(nArr, 10);

	MergeSort(nArr, 0, 9);
	printf("排序后:");
	PrintArr(nArr, 10);

	system("pause");
	return 0;
}