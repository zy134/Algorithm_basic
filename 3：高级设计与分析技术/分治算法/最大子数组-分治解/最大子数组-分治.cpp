#include<iostream>
#include<Windows.h>
using namespace std;
constexpr int UNLIMITED=-999999;
class  ArrayMsg{
public:
    ArrayMsg(int x,int y,int z):sum(x),left(y),right(z){}
	ArrayMsg():sum(0),left(0),right(0){}
	ArrayMsg& operator=(const ArrayMsg&m) {
		this->left=m.left;
		this->right=m.right;
		this->sum=m.sum;
		return *this;
	}
	int sum;
	int left;
	int right;
};
ArrayMsg Find_Cross_Max(int A[], ArrayMsg m)
{
    int mid=(m.left+m.right)/2;
	int left=m.left,right=m.right;
    int left_sum,right_sum,sum;
	left_sum=right_sum=UNLIMITED;
	sum=0;
	for (int i=mid;i>=left;i--) {
		sum+=A[i];
		if (left_sum < sum) {
			left_sum=sum;
			m.left=i;
		}
	}
	sum=0;
	for (int j = mid + 1; j<=right; j++) {
	    sum+=A[j];
		if (right_sum < sum) {
			right_sum=sum;
			m.right=j;
		}
	}
	m.sum=left_sum+right_sum;
	return m;
}

ArrayMsg Find_Max_Subarray(int A[], int low, int high)
{
	if(low==high)
	    return ArrayMsg(A[low],low,high);
	else {
		int mid=(low+high)/2;
		ArrayMsg m1,m2,m3;
		m1=Find_Cross_Max(A,ArrayMsg(0,low,high));
		m2=Find_Max_Subarray(A,low,mid);
		m3=Find_Max_Subarray(A,mid+1,high);
		if(m1.sum>=m2.sum&&m1.sum>=m3.sum)
		    return m1;
		else if(m2.sum>=m1.sum&&m2.sum>=m3.sum)
		    return m2;
		else return m3;
	}
}
int main()
{
	int A[] = { 13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7 };
	int low=0,high=15;
	ArrayMsg m;
	m=Find_Max_Subarray(A,low,high);
	cout<<"left:"<<m.left<<endl
	    <<"right:"<<m.right<<endl
		<<"sum:"<<m.sum<<endl;
	system("pause");
	return 0;
}