#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 0x3fffffff
using namespace std;
int n,r;
typedef struct Node
{
	int x,y,c;
	bool operator < (const Node& z)const
	{return c>z.c;}
}Node;
Node ns[24];
bool covs[24][24];
bool g[24][24];

bool vis[24];
int ans;

int get_dist(int i,int j)
{
	return  (ns[i].x-ns[j].x)*(ns[i].x-ns[j].x) + (ns[i].y-ns[j].y)*(ns[i].y-ns[j].y);
}

void dfs(int u,int cost,int cnt)
{
	if(cost > ans)return;
	if(cnt == n)
	{
		ans = ans<cost?ans:cost;
		return;
	}

	int i,j,vist[24];
	int t=cnt,t1=0;

	for(i=0;i<n;++i)
	{
		vist[i] = vis[i];
	}

	for(int v=u+1;v<n;++v)
	{
		t=cnt;
		for(i=0;i<n;++i)
		{
			if(!vis[i] && covs[v][i])++t;
		}
		if(t == n)
		{
			t1=cnt;

			for(i=0;i<n;++i)
			{
				if(g[v][i] && !vis[i])
				{
					vis[i]=1;
					++t1;
				}
			}

			dfs(v,cost+ns[v].c,t1);

			for(i=0;i<n;++i)
			{
				vis[i] = vist[i];
			}


		}

	}
}
int main()
{
//	freopen("in","r",stdin);
	int i,j;
	while(~scanf("%d",&n))
	{

		for(i=0;i<n;++i)
		{
			scanf("%d%d%d",&ns[i].x,&ns[i].y,&ns[i].c);
		}

		scanf("%d",&r);

		sort(ns,ns+n);
		memset(covs,0,sizeof(covs));
		memset(g,0,sizeof(g));
		for(i=0;i<n;++i)
		{
			g[i][i]=1;
			for(j=i+1;j<n;++j)
			{
				if(get_dist(i,j)<=r*r)
					g[i][j] = g[j][i] = 1;
			}
		}

		for(i=n-1;i>=0;--i)
		{
			for(j=0;j<n;++j)
			{
				if(g[i][j])
				{
					for(int k=0;k<=i;++k)
					{
						covs[k][j] = 1;
					}
				}
			}
		}

		ans = INF;
		memset(vis,0,sizeof(vis));			


		for(int v=0;v<n;++v)
		{
			int t=0;
			for(i=0;i<n;++i)
			{
				if(covs[v][i])++t;
			}
			if(t==n)
			{
				int t1=0;
				for(i=0;i<n;++i)
				{
					if( g[v][i])
					{
						vis[i] = 1;
						++t1;
					}
				}
				dfs(v,ns[v].c,t1);
				memset(vis,0,sizeof(vis));
			}
		}
		printf("%d\n",ans);

	}
	return 0;
}

