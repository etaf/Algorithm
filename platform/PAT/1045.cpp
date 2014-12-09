#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;

int dp[10010];
int a[10010];
int main()
{
	int n,m,k,i,j,c;
	scanf("%d%d",&n,&m);

	map<int,int> M;
	for( i=0;i<m;++i)
	{
		scanf("%d",&c);
		if(c<=n)
			M[c]=i;
	}
	scanf("%d",&k);
	int ca=0;
	for(i=0;i<k;++i)
	{
		scanf("%d",&c);
		if(M.find(c)!=M.end())
			a[ca++] = M[c];
	}
	if(ca == 0)
	{
		printf("0\n");
		return 0;
	}
	int maxn = 1;
	dp[0] = 1;
	for(i=1;i<ca;++i)
	{
		dp[i] = 1;
		for(j=0;j<i;++j)
		{
			if(a[i]>=a[j])
			{
				dp[i] = dp[i]>dp[j]+1?dp[i]:dp[j]+1;
			}
		}
		maxn = maxn>dp[i]?maxn:dp[i];

	}

	printf("%d\n",maxn);
	return 0;
}