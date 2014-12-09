#include<iostream>
using namespace std;
int main()
{
	int n,i;
	double x,y,sum;
	cin>>n>>x;
	double *a=new double[n];
	for(i=0;i<n;i++)
		cin>>a[n];
	sum=0;
	for(i=0;i<n;i++)
		sum+=a[n-i]*x+a[n-i-1];
	cout<<sum;
	return 0
}