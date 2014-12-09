#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
const int N = 3000;
#define INF 0x3fffffff
int n;
typedef struct Edge
{
	int v,next,c,w;
}Edge;
int ei;
Edge es[N+N+N+N+N];
int head [N];
int pre[N];
int pe[N];
int vis[N];
int g[64][64];
int gid[64][64];
int cost[N];
void addEdge(int u,int v,int c,int w)
{
	es[ei].v = v; es[ei].c = c; es[ei].w = w; es[ei].next = head[u]; head[u] = ei++;
	es[ei].v = u; es[ei].c = 0; es[ei].w = -w; es[ei].next = head[v]; head[v] = ei++;
}

int bfs(int s,int t,int& res)
{
	for(int i=0;i<n;++i)
	{
		cost[i] = INF;
	}
	std::queue<int > Q;
	Q.push(s);
	vis[s] = 1;
	cost[s] = 0;
	int u,v;
	pre[t] = -1;
	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();
		vis[u] = 0;

		for(int p = head[u];p!=-1;p=es[p].next)
		{
			v = es[p].v;
			if(es[p].c>0 && cost[v]>cost[u]+es[p].w)
			{
				pre[v] = u;
				pe[v] = p;
				cost[v] = cost[u]+es[p].w;
				if(!vis[v])
				{
					Q.push(v);
					vis[v] =1;
				}
			}
		}
	}

	if(pre[t] == -1)return 0;
	for(v=t;v!=s;v=pre[v])
	{
		es[pe[v]].c -= 1;
		es[pe[v]^1].c += 1;
	}
	res+=cost[t];
	return 1;
}

int maxflow(int s,int t)
{
	int res=0;
	while(bfs(s,t,res));
	return res;
}
int main()
{
	int i,j,l,h,k;
	int mx = -INF;
	scanf("%d%d%d",&h,&l,&k);
	int cnt = 0;
	for(i=0;i<h;++i)
	{
		for(j=0;j<i+l;++j)
		{
			scanf("%d",&g[i][j]);
			gid[i][j] = cnt++;
			mx = mx>g[i][j]?mx:g[i][j];
		}
	}
	memset(head,-1,sizeof(head));
	int s= cnt+cnt;
	int ss = s+1;
	int t= ss+1;
	n = t+1;

	addEdge(s,ss,k,0);

	for(j=0;j<l;++j)
	{
		addEdge(ss,gid[0][j],INF,0);
	}
	
	for(i=0;i<h-1;++i)
	{
		for(j=0;j<l+i;++j)
		{
			addEdge(gid[i][j],gid[i][j]+cnt,1,mx-g[i][j]);
			addEdge(gid[i][j],gid[i][j]+cnt,INF,mx);

			addEdge(gid[i][j]+cnt,gid[i+1][j],1,mx);
			addEdge(gid[i][j]+cnt,gid[i+1][j+1],1,mx);
		}
	}	

	for(j=0;j<h-1+l;++j)
	{
		addEdge(gid[i][j],gid[i][j]+cnt,1,mx-g[i][j]);
		addEdge(gid[i][j],gid[i][j]+cnt,INF,mx);

		addEdge(gid[i][j]+cnt,t,INF,0);
	}
	printf("%d\n",k*mx*(h+h-1) - maxflow(s,t));
	return 0;
}