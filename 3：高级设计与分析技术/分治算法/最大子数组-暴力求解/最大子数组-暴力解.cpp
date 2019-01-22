#include<iostream>
#include<Windows.h>
using namespace std;
int main()
{
    int left,right,sum=0;
	int A[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	int i,j;
	for(i=0;i!=16;i++)
		for (j = i+1; j != 16; j++) {
			int temp=0;
			for(int k=i;k!=j;k++)
			    temp+=A[k];
			if (temp > sum) {
				sum=temp;
				left=i;
				right=j;
			}
		}
	for(int p=left;p<=right;p++)
	    cout<<A[p]<<"  ";
	system("pause");
	return 0;
}