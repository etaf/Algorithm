#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
#define INF 0x3fffffff

const int N = 110;
vector<int> ns[N];
int w[N];
int n,m,k;
typedef struct Path
{
	int path[N],len;
	Path(){}
	Path(int * p,int l)
	{
		for(int i=0;i<l;++i)
			path[i] = p[i];
		len = l;
	}
	bool operator<(const Path &z)const
	{
		int n = len<z.len?len:z.len;
		int i;
		for(i=0;i<n && path[i] == z.path[i];++i);
		if(i<n && path[i]>z.path[i])return true;
		return false;
	}
};

vector<Path> ps;

int tmpp[N],tmpc;
void dfs(int u,int sum)
{
	if(ns[u].size() == 0)
	{
		if(sum == k)
		ps.push_back(Path(tmpp,tmpc));
		return;
	}
	for(int i=0,v; i<ns[u].size();++i)
	{
		v= ns[u][i];
		tmpp[tmpc++] = w[v];
		dfs(v,sum+w[v]);
		--tmpc;
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;++i)
	{scanf("%d",&w[i]);}
	int t,u,v;
	for(int i=0;i<m;++i)
	{
		scanf("%d%d",&u,&t);
		for(int j=0;j<t;++j)
		{
			scanf("%d",&v);
			ns[u].push_back(v);
		}
	}
	tmpc = 0;
	tmpp[tmpc++] = w[0];
	dfs(0,w[0]);
	sort(ps.begin(),ps.end());
	for(int i=0;i<ps.size();++i)
	{
		printf("%d",ps[i].path[0]);
		for(int j=1;j<ps[i].len;++j)
		{
			printf(" %d",ps[i].path[j]);
		
		}
		printf("\n");
	}

	return 0;

}