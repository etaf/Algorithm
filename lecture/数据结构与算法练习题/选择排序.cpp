#include<iostream>
using namespace std;
//及时终止的冒泡排序法
template<typename T>
void BubbleSort(T* a,int n)
{
	int i,j;
	bool sorted=false;
	for(i=1;i<n && !sorted;i++)
	{
		sorted=true;
		for(j=0;j<n-i;j++)
			if(a[j]>a[j+1])
			{
				Swap(a[j],a[j+1]);
				sorted=false;	
			}
	}
}
template<typename T>
void Swap(T& a,T& b)
{
	T t;
	t=a;a=b;b=t;
}

int main()
{
	int i,n;
	cin>>n;
	int* a=new int[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	BubbleSort(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}