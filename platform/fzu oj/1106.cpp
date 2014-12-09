#include<iostream>
using namespace std;
int main()
{
	int n,i,t;
	while(cin>>n)
	{
		int *a=new int[n];
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=1;i<n;i++)
			for(j=0;j<n-i;j++)
			{
				if(a[j]<a[j+1])
				{t=a[j];a[j]=a[j+1];a[j+1]=t;}
			}
		cout<<a[0];
		for(i=1;i<n;i++)
			cout<<" "<<a[i];
		cout<<endl;
	}
	return 0;
}