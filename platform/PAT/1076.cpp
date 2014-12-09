#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int n,maxl;
const int N = 1001;
typedef struct Edge
{
	int v,next;
}Edge;

Edge es[100010];
int head[N],cnte;

void addedge(int u,int v)
{
	es[cnte].v=  v; es[cnte].next = head[u]; head[u] = cnte++;
}

int dist[N];
#define INF 0x3fffffff
int bfs(int u)
{
	for(int i=1;i<=n;++i)
	{
		dist[i] = INF;
	}
	dist[u] = 0;
	queue<int> Q;
	Q.push(u);
	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();

		int v;
		for(int p=head[u];p!=-1;p=es[p].next)
		{
			v = es[p].v;
			if(dist[v]>dist[u]+1)
			{
				dist[v] = dist[u] + 1;
				if(dist[v]<maxl)
				{
					Q.push(v);
				}
			}
		}
	}
	int ans = 0;
	for(int i=1;i<=n;++i)if(dist[i] <= maxl)++ans;

	return --ans;
}
int main()
{
	cnte = 0;
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&maxl);
	int m,v;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&m);
		for(int j=0;j<m;++j)
		{
			scanf("%d",&v);
			addedge(v,i);
		}
	}
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d",&v);
	
		printf("%d\n",bfs(v));
	}
	return 0;
}