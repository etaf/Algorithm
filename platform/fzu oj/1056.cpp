
#include<iostream>
using namespace std;
int main()
{
	char a[100][100];
	int n,m,i,j;
	while(cin>>n>>m)
	{
		if(n==0 && m==0)
			break;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				cin>>a[i][j];
			}
		}
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(a[i][j]=='.')
				{
						int sum=0;
	if(a[i-1][j-1]=='*' && i-1>=0 && j-1>=0)
		sum++;
	if(a[i-1][j]=='*' && i-1>=0)
		sum++;
	if(a[i-1][j+1]=='*' && i-1>=0 && j+1<m)
		sum++;
	if(a[i][j-1]=='*' && j-1>=0)
		sum++;
	if(a[i][j+1]=='*' && j+1<m)
		sum++;
	if(a[i+1][j-1]=='*' && i+1<n && j-1>=0)
		sum++;
	if(a[i+1][j]=='*' && i+1<n)
		sum++;
	if(a[i+1][j+1]=='*'&& i+1<n&&j+1<m)
		sum++;
	a[i][j]=sum+'0';
				}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				cout<<a[i][j];
			cout<<endl;
		}
		cout<<endl;

	}
	return 0;
}


