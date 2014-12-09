#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int N = 10010;
int n;
int sum[N][2];
int a[N];
int ans[N],cta;
int dfs(int u)
{
	int l = u<<1;
	int r = (u<<1)+1;
	if(l<=n)
	{
		sum[u][0]=dfs(l);
	}
	if(r<=n)
	{
		sum[u][1]=dfs(r);
	}
	return sum[u][0]+sum[u][1]+1;
}

int find_root(int l,int p)
{
	return a[ l+sum[p][0]+1 ];
}
typedef struct Node
{
	int id,l;
	Node(){}
	Node(int _id,int _l):id(_id),l(_l){}
}Node;

void bfs()
{
	
	queue<Node> Q;
	Q.push(Node(1,1));
	int u,ll,l,r;

	while(!Q.empty())
	{
		u = Q.front().id;
		ll = Q.front().l;
		Q.pop();
		ans[cta++] = a[ll + sum[u][0] ];
		l = u<<1;
		r = (u<<1)+1;
		if(l<=n)
			Q.push(Node(l,ll));
		if(r<=n)
			Q.push(Node(r,ll+sum[u][0]+1));
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
	}
	dfs(1);
	sort(a+1,a+n+1);
	bfs();
	printf("%d",ans[0]);
	for(int i=1;i<cta;++i)
		printf(" %d",ans[i]);
	printf("\n");
	return 0;

}