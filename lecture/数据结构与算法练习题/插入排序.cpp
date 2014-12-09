#include<iostream>
using namespace std;
//≤Â»Î≈≈–Ú
template<typename T>
void InsertionSort(T* a,int n)
{
	int i,j;
	T t;
	for(i=1;i<n;i++)
	{
		t=a[i];
		for(j=i-1;j>=0 && a[j]>t;j--)
		{
			a[j+1]=a[j];

		}
		a[j+1]=t;
	}
}



int main()
{
	int i, n;
	cin>>n;
	int *a=new int[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	InsertionSort(a,n);
	cout<<"InsertionSorted: ";
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}