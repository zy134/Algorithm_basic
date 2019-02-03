#include"HeapSort.h"
#include<Windows.h>
using namespace std;
int main()
{
    Heap h(30);
	h.Sort();
	h.Print();
	system("pause");
	return 0;
}