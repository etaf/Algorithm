#include <iostream>
#include <cstdio>
using namespace std;
#define INF  0x3fffffff
const int N= 210;
int m,n;
int Cap[N][N];
int pre[N];
int vis[N];

inline int min(int x,int y)
{
	return x<y?x:y;
}
int bfs(int s,int t)
{
	int nf[N];
	int que[N]; int qtop=0,qrear=0;
	int u,v;

	nf[s]= INF ; nf[t]=0;			//nf[x] : flows in node x 

	memset(vis,0,sizeof(vis));
	que[qrear++]=s;
	vis[s]=1;
	while(qtop<qrear)
	{
		u = que[qtop++];

		if(u == t)break;
		for(v=1;v<=n;++v)
		{
			if(!vis[v] && Cap[u][v]>0)
			{
				que[qrear++] = v;
				vis[v] = 1;
				pre[v] = u;
				nf[v] = min(nf[u],Cap[u][v]);
			}
		}
	}

	return nf[t];

}
int  FF(int s,int t)					//Ford-Fulkerson
{
	int flow=0,inc;
	while(1)
	{
		inc = bfs(s,t);
		if(inc==0)return flow;
		flow+=inc;
		for(int i=t;i!=s;i=pre[i])
		{
			Cap[i][ pre[i] ] += inc;
			Cap[ pre[i] ][i] -= inc;
		}
	}
	return flow;
}

int main()
{

	int u,v,c;
	scanf("%d%d",&m,&n);


	for(int i=0;i<m;++i)
	{
		scanf("%d%d%d",&u,&v,&c);
		Cap[u][v] += c;
	}
	printf("%d\n",FF(1,n));

	return 0;
}
        