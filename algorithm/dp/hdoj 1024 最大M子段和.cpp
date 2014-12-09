#include<stdio.h>
#include<string.h>
#define INF 0x3fffffff
typedef __int64 llong;
const int N=1000001;
llong dp[2][N];
llong a[N];

/*
dp[i][j] = max(
				dp[i][j-1]+a[j],			(j-1>=i)
				dp[i-1][i-1:j-1]+a[j];		
				)
*/

int main()
{
	int n,m,c,i,j;
	llong maxn;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		for(i=1;i<=n;++i)
		{
			scanf("%I64d",&a[i]);
		}
		memset(dp,0,sizeof(dp));
		for(i=1,c=1;i<=m;++i,c=1-c)
		{
			dp[c][i] = dp[1-c][i-1]+a[i];
			maxn = dp[1-c][i-1];
			for(j=i+1;j<=n-m+i;++j)
			{
				maxn = maxn>dp[1-c][j-1]?maxn:dp[1-c][j-1];
				dp[c][j] =a[j]+ (dp[c][j-1]>maxn?dp[c][j-1]:maxn);
			}
		}
		maxn = -INF;
		for(j=m;j<=n;++j)
		{
			maxn = maxn>dp[1-c][j]?maxn:dp[1-c][j];
		}
		printf("%I64d\n",maxn);
	}
	return 0;
}