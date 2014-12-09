#define M 10000
#define N 10000
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{

	int n;
	cin>>n;
	while(n--)
	{
		int m;
		cin>>m;
		int a[M]={0};
		a[0]=1;
		int i,k=1,v;
		for(v=1;v<=m;v++)
		{
			for(i=0;i<k;i++)
			{
				a[i]*=v;
			}
			for(i=0;i<k;i++)
			{
				if(a[i]>=N)
				{
					a[i+1]+=a[i]/N;
					a[i]=a[i]%N;
				}
				if(a[k])
					k++;
			}
		}
		cout<<a[k-1];
		if(k>1)
		{
			for(i=k-2;i>=0;i--)
			cout<<setw(4)<<setfill('0')<<a[i];

		}
		cout<<endl;

	}

	return 0;
}
n=?
200!=7.88657867364855e374
Press any key to continue