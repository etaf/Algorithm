#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<string>
#include<queue>
using namespace std;
#define INF 0x3fffffff
const int N = 1024;
typedef struct Edge
{
	int v,next,d;
}Edge;

Edge es[20010];
int ecnt;
int head[1024];

void addedge(int u,int v,int d)
{
	es[ecnt].v = v;es[ecnt].d = d; es[ecnt].next = head[u];  head[u] = ecnt++;
	es[ecnt].v = u;es[ecnt].d = d; es[ecnt].next = head[v];  head[v] = ecnt++;
}

typedef struct Node
{
	int v,d;
	Node(int _v,int _d):v(_v),d(_d){}
	bool operator<(const Node& z)const
	{return d>z.d;}
}Node;
int dist[N];
int n,m,ds,k;
bool vis[N];
void Dijkstra(int s)
{
	int len = m+n;
	for(int i=1;i<=len;++i)
	{
		dist[i] = INF;
		vis[i] = 0;
	}
	dist[s] = 0;
	priority_queue<Node> Q;
	Q.push(Node(s,0));
	int u,v;
	 
	while(!Q.empty())
	{
		u = Q.top().v;

		Q.pop();
		if(vis[u])continue;
		vis[u] = 1;

		for(int p=head[u];p!=-1;p=es[p].next)
		{
			v = es[p].v;
			if( dist[v] > dist[u]+es[p].d)
			{
				dist[v] = dist[u]+es[p].d;
				Q.push(Node(v,dist[v] ));
			}
		}
	}

}
int get_id(char* s)
{
	int res = 0;
	if(s[0] == 'G')
	{
		for(int i=1;s[i];++i)
		{
			res = res*10 + s[i]-'0';
		}
		res+=n;
	}else
	{
		for(int i=0;s[i];++i)
		{
			res = res*10+s[i]-'0';
		}
	}
	return res;
}

bool get_mind(int& mind,int& sumd)
{
	mind = INF;sumd=0;
	for(int i=1;i<=n;++i)
	{
		if(dist[i]>ds)return false;
		sumd += dist[i];
		if(mind > dist[i])
		{
			mind = dist[i];
		}
	}
	return true;
}
int main()
{
	ecnt = 0;
	memset(head,-1,sizeof(head));
	scanf("%d%d%d%d",&n,&m,&k,&ds);
	char tmpa[64],tmpb[64];
	int u,v,d;
	for(int i=0;i<k;++i)
	{
		scanf(" %s %s %d",tmpa,tmpb,&d);
		u = get_id(tmpa);
		v = get_id(tmpb);
		addedge(u,v,d);
	}
	int maxn=-1,minsumd = INF,ansid = 0;
	int mind,sumd,tmpid;
	for(int i=1;i<=m;++i)
	{
		Dijkstra(i+n);
		if(get_mind(mind,sumd))
		{
			if(maxn < mind || (maxn == mind && minsumd>sumd) )
			{
				ansid = i;
				maxn = mind;
				minsumd = sumd;
			}
		}
	}
	if(ansid == 0)printf("No Solution\n");
	else
	{
		double ans1 = maxn;
		double ans2 = minsumd*1.0/n;
		printf("G%d\n%.1lf %.1lf\n",ansid,ans1,ans2);
	}
	return 0;
}