#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
#define INF 0x3fffffff
const int N = 410;

typedef struct Edge
{
	int v,next,c;
}Edge;
int ei;
Edge es[60000];
int head[N];


void addEdge(int u,int v,int c)
{
	es[ei].v = v;es[ei].c = c;es[ei].next = head[u]; head[u]=ei++;
	es[ei].v = u;es[ei].c = 0;es[ei].next = head[v]; head[v]=ei++;
}


int n,mf,md,nn;

int pre[N];
int pe[N];
int vis[N];
int bfs(int s,int t)
{
	queue<int> Q;
	memset(vis,0,sizeof(vis));
	Q.push(s);
	vis[s]= 1;
	int u,v;
	pre[t] = -1;
	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();
		if(u == t)break;
		for(int p = head[u];p!=-1;p=es[p].next)
		{
			v = es[p].v;
			if(!vis[v] && es[p].c > 0)
			{
				pre[v]=u;
				pe[v] = p;
				Q.push(v);
				vis[v]=1;
			}
		}
	}
	if(pre[t]==-1)return 0;
	int inc = INF;
	for(v=t;v!=s;v=pre[v])
	{
		inc = inc<es[pe[v]].c?inc:es[pe[v]].c;
	}
	for(v=t;v!=s;v=pre[v])
	{
		es[pe[v]].c -= inc;
		es[pe[v]^1].c += inc;
	}
	return inc;
}
int maxflow(int s,int t)
{
	int f = 0,inc;
	while(1)
	{
		inc = bfs(s,t);
		if(inc == 0)return f;
		f+=inc;
	}
	return f;
}
int main()
{
	int i,j,fi,di,x;
	while(scanf("%d%d%d",&n,&mf,&md)!=EOF)
	{
		memset(head,-1,sizeof(head));
		int s= 0,t=mf+n+n+md+1;
		nn = t+1;
		ei = 0;
		for(i=1;i<=mf;++i)
		{
			addEdge(s,i,1);
		}
		for(i=1;i<=n;++i)
		{
			scanf("%d%d",&fi,&di);
			for(j=0;j<fi;++j)
			{
				scanf("%d",&x);
				addEdge(x,mf+i,1);
			}
			addEdge(i+mf,i+mf+n,1);
			for(j=0;j<di;++j)
			{
				scanf("%d",&x);
				addEdge(i+mf+n,mf+n+n+x,1);
			}
		}
		for(i=1;i<=md;++i)
			addEdge(mf+n+n+i,t,1);
		printf("%d\n",maxflow(s,t));
	}
	return 0;
}