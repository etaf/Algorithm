#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,k,i,j;
	while(cin>>n>>k)
	{
		int *a=new int[n];
		int *b=new int[n];
		for(i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
			b[0]=a[n-1];
		for(i=n-2,j=1;i>=0;i--)
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