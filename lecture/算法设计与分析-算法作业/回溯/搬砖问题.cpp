/*
ËÑË÷ + ¼ôÖ¦
*/


#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef int llong ;

int n;
int a[64];
llong sum;
llong maxn;
void dfs(int u,llong ns)
{
	ns+=a[u];
	if(ns > sum)return;
	maxn = maxn>ns?maxn:ns;
	if(maxn == sum)return;

	if(ns+a[0]>sum)return;

	for(int i=u-1;i>=0;--i)
	{
		dfs(i,ns);	
	}


}
int main()
{
	scanf("%d",&n);
	sum=0;
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	llong tmp = sum;
	sum/=2;
	maxn = 0;
	sort(a,a+n);
	
	dfs(n,0);
	//printf("%I64d %I64d\n",maxn,tmp-maxn);
	printf("%d %d\n",maxn,tmp-maxn);
	return 0;
}
/*
4
100
90
200
100

3
1
1
1
*/