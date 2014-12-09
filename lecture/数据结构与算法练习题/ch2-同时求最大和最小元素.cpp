#include<iostream>
using namespace std;
//查找最大和最小元素
/*
template<typename T>
bool MinMax(T a[],int n,int& min,int& max)
{
	if(n<1)
		return false;
	min=max=0;
	for(int i=1;i<n;i++)
	{
		if(a[i]<a[min])
			min=i;
		if(a[i]>a[max])
			max=i;

	}
	return true;
}
*/
template<typename T>
bool MinMax(T a[],int n,int& min,int& max)
{
	if(n<1)
		return false;
	min=max=0;
	for(int i=1;i<n;i++)
		if(a[i]<a[min])
			min=i;
		else
			if(a[i]>a[max])
				max=i;
	return true;
}
int main()
{
	int n,i;
	cin>>n;
	int* a=new int[n];
	
	for(i=0;i<n;i++)
		cin>>a[i];
	int max,min;
	MinMax(a,n,max,min);
	cout<<"Max is "<<a[max]<<endl;
	cout<<"Min is "<<a[min]<<endl;
	return 0;
}