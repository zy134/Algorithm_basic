#include<iostream>
#include<Windows.h>
constexpr int UNILINITED=-99999;
/*
先找到A[1~j]的最大子数组，接下来寻找最大子数组A[i~j]
*/

using namespace std;
int main()
{
	int A[]={1,2,3,4,5,6,-9,-8,6,76,55,-767};
	int i,j;
	int left,right;
	int length=12;
	int sum=UNILINITED,temp=0;

	for (j = 0; j != length; j++) {
	    temp+=A[j];
		if (sum <= temp) {
			sum=temp;
			right=j;
		}
	}
	for (i = 0, temp = 0; i<=j; i++) {
		temp+=A[i];
		if (sum <= temp) {
			sum=temp;
			left=i;
		}
	}

	cout<<"sum:"<<sum<<endl
	    <<"left:"<<left<<"   right:"<<right<<endl;

	system("pause");
	return 0;
}