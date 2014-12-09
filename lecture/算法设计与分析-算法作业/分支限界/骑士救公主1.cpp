#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define INF 0x3fffffff
int n,m;
char g[222][222];

typedef struct Node
{
	int x,y,v;
	Node(){}
	Node(int _x,int _y,int _v):x(_x),y(_y),v(_v){}
	bool operator<(const Node& z)const
	{
		return v>z.v;
	}
};
int xdir[4]={-1,0,1,0};
int ydir[4]={0,1,0,-1};
bool vis[222][222];
int gg[222][222];
int bfs()
{
	int i,j;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j)
		{
			vis[i][j] = 0;
			gg[i][j] = INF;
		}
	}
	std::priority_queue<Node> Q;
	gg[1][1] = 0;
	Q.push(Node(1,1,0));
	
	Node u,v;
	
	while(!Q.empty())
	{
		u = Q.top();
		Q.pop();
		vis[u.x][u.y] = 1;			
		if(u.x == n && u.y == m)
			return gg[u.x][u.y];

		for(i=0;i<4;++i)
		{
			v.x = u.x+xdir[i];
			v.y = u.y+ydir[i];
			if( g[v.x][v.y] != '#' &&  !vis[v.x][v.y] &&  gg[v.x][v.y] > gg[u.x][u.y]+g[v.x][v.y]-'0'+1 )
			{
				gg[v.x][v.y] = gg[u.x][u.y] +g[v.x][v.y]-'0'+1;
				v.v = gg[v.x][v.y];
				Q.push(v);
			}
		}

	}
	return -1;

}
int main()
{
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=0;i<n+2;++i)
	{
		g[i][0]  = g[i][m+1] = '#';
	}
	for(j=0;j<m+2;++j)
	{
		g[0][j] = g[n+1][j] = '#';
	}
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j)
		{
			scanf(" %c",&g[i][j]);
			if(g[i][j] == '.')g[i][j] = '0';
		}
	}
	
	printf("%d\n",bfs());	
	//printf("==============================\n");
	//for(i=1;i<=n;++i)
	//{
	//	for(j=1;j<=m;++j)
	//	{
	//		printf("%d ",gg[i][j]);
	//	}
	//	printf("\n");
	//}
	//printf("==============================\n");

	//
	return 0;
}