#include<iostream>
using namespace std;
int main()
{
	int n,v=1,i;
	s[10];
	s[0]=1;
	for(i=1;i<n;i++)
	{
		v*=i;
		s[i]=v;
	}
	while(cin>>n)
	{
		for(i=9;i>=0;i--)
		{
			if(s[i]<n)
			{
				n-=s[i];
			}
			if(n==0)
			{
				cout<<'YES';
				break;
			}
			else
				if(n<0)
				{
					cout<<'NO';
					break;
				}
		}
		if(i<0)
			cout<<'NO';
		cout<<endl;
	}
	return 0;
}