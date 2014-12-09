#include<stdio.h>
int main()
{

	long n,sum,x;
	while(scanf("%ld",&n)!=EOF)
	{
		sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%ld",&x);
			sum+=x;
		}
		printf("%d\n",sum+n-n*(n+1)/2);
	}
	return 0;
}
