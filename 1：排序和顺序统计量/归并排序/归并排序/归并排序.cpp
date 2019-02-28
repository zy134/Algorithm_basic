
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
原理：
    就像两幅已排序的扑克牌，要将他们和成一副扑克牌。应当翻开两个牌顶，取小的那张扑克放入新牌堆。
	然后刚刚堆顶牌比较小的牌堆再翻开张新牌，再比较两个牌堆的堆顶牌。以此往复。

	归并排序先分后治再合，先将数组不断二分直至不能再分，然后将小数组按上诉规则不断合一，最后得出
	的合数组就是排序成功的
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
//�ϲ���������
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
		//1�ֽ�
		int nMid = (nLeft + nRight) / 2;

		//2���
		MergeSort(pnArr, nLeft, nMid);
		MergeSort(pnArr, nMid + 1, nRight);

		//3�ϲ�
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

	printf("����ǰ:");
	PrintArr(nArr, 10);

	MergeSort(nArr, 0, 9);
	printf("�����:");
	PrintArr(nArr, 10);

	system("pause");
	return 0;
}