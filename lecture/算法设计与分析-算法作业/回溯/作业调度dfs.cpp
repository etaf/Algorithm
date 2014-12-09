#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x3fffffff
typedef struct Node
{
	int t,w;
	bool operator<(const Node& z)
	{
		return t*1.0/w < z.t*1.0/z.w ;
	}
}Node;

Node ns[10000];

int n;

int ans;
int mint,minw;
bool vis[10000];

void dfs(int t,int sum,int step)
{
	if(sum>ans)return;
	if(step == n)
	{
		ans = ans<sum?ans:sum;
		return;
	}
	int k = n-step;
	for(int v=0;v<n;++v)
	{
		if(!vis[v] && sum+minw*(k*t+(k+1)*k/2*mint)<ans )
		{
			vis[v] =1;
			dfs(t+ns[v].t,sum+(t+ns[v].t)*ns[v].w,step+1);
			vis[v] = 0;
		}
	}
}

int main()
{
	freopen("in","r",stdin);
	scanf("%d",&n);
	int i,j;
	mint = INF;
	minw = INF;
	for(i=0;i<n;++i)
	{
		scanf("%d",&ns[i].t);
		mint = mint<ns[i].t?mint:ns[i].t;	
	}
	for(i=0;i<n;++i)
	{
		scanf("%d",&ns[i].w);
		minw = minw<ns[i].w?minw:ns[i].w;
	}
	std::sort(ns,ns+n);
	ans = INF;
	dfs(0,0,0);
	printf("%d\n",ans);
	return 0;
}