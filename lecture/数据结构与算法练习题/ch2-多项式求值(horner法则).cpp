#include<iostream>
using namespace std;
int main()
{
	int n,i;
	double x,sum;
	cin>>n>>x;
	double *a=new double[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	sum=a[n-1];
	for(i=1;i<n;i++)
		sum=sum*x+a[n-i-1];
	cout<<sum<<endl;
	return 0;
}