#include<iostream>
using namespace std;
int main()
{
	int n,k,i,j,t;
	while(cin>>n>>k)
	{
		int *a=new int[n];
		int *b=new int[n];
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=1;i<n;i++)
			for(j=0;j<n-i;j++)
			{
				if(a[j]<a[j+1])
				{t=a[j];a[j]=a[j+1];a[j+1]=t;}
			}

			b[0]=a[0];
		for(i=1,j=1;i<n;i++)
		{
			if(j==k)break;
			if(a[i]!=a[i-1])
			{
				b[j]=a[i];
				j++;
			}
		}
		if(j<k)
			cout<<"-1"<<endl;
		else
		{
			cout<< b[k-1];
			for(i=k-2;i>=0;i--)
				cout<<" "<<b[i];
			cout<<endl;
		}
	}
	return 0;
}