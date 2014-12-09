/*
算法实验作业6-1 色子游戏问题
?问题描述：
色子游戏是一个在 N*M 的方格上进行的棋盘游戏。棋盘的每行从北向南被标记为 0 到
N-1，每列从西到东被标记为 0 到 M-1。如下图所示：
棋盘上的每一个方格可以用一个坐标(x，y)表示，x 是行标记，y 是列标记。
每一个色子都是一个立方体，它的六个面分别被标记为 1，2，3，4，5 和 6。其中标记
为 1，2 和 3 的面两两相邻，标记为 6 的面与标记为 1 的面相反，标记为 5 的面与标记为 2 的面相反，标记为 4 的面与标记为 3 的面相反。
色子游戏规则：
色子初始时被放在一个方格上，要移动色子，玩家可以水平或垂直滚动色子到相邻的方
格上。游戏的目的是要求用最少的移动步数，让色子从初始位置移动到目标位置。色子的状
态必须与目标位置的状态相一致。
?编程任务：
用最少的移动步数，让色子从初始位置移动到目标位置并且使得色子的状态与目标位置
的状态相一致。
?数据输入：
输入数据的第一行为两个正整数 N 和 M（1≤N，M≤100），以下 N 行，每行包含 M个字符，字符是'#'或者是'.'，如果是'#'，表示这个方格是一个障碍物，色子无法翻转到这个
方格，如果是'.'，表示这个方格是一个空格，色子可以翻转到这个方格。以上 N*M 个字符
表示 N*M 的方格棋盘，色子不能移动到棋盘之外。
以下一行有四个整数 x1，y1，x2，y2，(x1，y1)和(x2，y2)分别表示初始位置坐标和目
标位置坐标。初始位置坐标和目标位置坐标可以看成是'.'的方格。以下两行分别表示初始位
置时色子的状态和目标位置时色子的状态。色子的状态用色子的六个面来表示，每行的六个
数字分别表示色子的上，下，北，南，西，东面。
输入数据有多组，当 N=0 并且 M=0 时，表示输入数据结束。
?结果输出: 将求出的最少的移动步数输出，如果无法从初始点到目标点，输出“-1”。
*/


#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int N= 110;
const int M= 110;
#define INF 0x3fffffff
int n,m;
char g[N][M];
int gg[N][N][7][7];
typedef struct Node
{
	int u,d,n,s,e,w,x,y,v;
	bool operator<(const Node& z)const
	{
		return v>z.v;
	}
}Node;
Node s_node,t_node;
Node change_pos(int direct,Node s)
{
	Node t = s;

	if(direct == 0)
	{
		t.x = s.x-1;

		t.u = s.s;
		t.d = s.n;
		t.n = s.u;
		t.s = s.d;
		t.e = s.e;
		t.w = s.w;
	}

	if(direct == 1)
	{
		t.y = s.y+1;

		t.u = s.w;
		t.d = s.e;
		t.n = s.n;
		t.s = s.s;
		t.e = s.u;
		t.w = s.d;
	}

	if(direct == 2)
	{
		t.x = s.x+1;

		t.u = s.n;
		t.d = s.s;
		t.n = s.d;
		t.s = s.u;
		t.e = s.e;
		t.w = s.w;
	}

	if(direct == 3)
	{
		t.y = s.y-1;

		t.u = s.e;
		t.d = s.w;
		t.n = s.n;
		t.s = s.s;
		t.e = s.d;
		t.w = s.u;
	}
	return t;
}


void bfs()
{
	int i,j,c,k;
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			for(c=1;c <= 6;++c)
				for( k=1;k<=6;++k)
					gg[i][j][c][k] = INF;
	

	gg[s_node.x][s_node.y][s_node.u][s_node.n] = 0;
	priority_queue<Node> Q;
	Node u,v;
	s_node.v = 0;
	Q.push(s_node);
	while(!Q.empty())
	{
		u = Q.top();
		Q.pop();

		for(i=0;i<4;++i)
		{
			v = change_pos(i,u);
			if( g[v.x][v.y]!='#' && gg[v.x][v.y][v.u][v.n] > gg[u.x][u.y][u.u][u.n]+1 )
			{
				gg[v.x][v.y][v.u][v.n] =  gg[u.x][u.y][u.u][u.n]+1;
				v.v = gg[v.x][v.y][v.u][v.n];
				Q.push(v);			
			}

		}
	}

}
void solve()
{
	int i,j;
	for(i=0;i<n+2;++i)
		g[i][0] = g[i][m+1] = '#';
	for(j=0;j<m+2;++j)
		g[0][j] = g[n+1][j] = '#';
	for(i=1;i<n+1;++i)
	{
		for(j=1;j<m+1;++j)
		{
			scanf(" %c",&g[i][j]);
		}
	}

	scanf("%d%d%d%d",&s_node.x,&s_node.y,&t_node.x,&t_node.y);
	s_node.x+=1;s_node.y+=1;
	t_node.x+=1;t_node.y+=1;
	scanf("%d%d%d%d%d%d",&s_node.u,&s_node.d,&s_node.n,&s_node.s,&s_node.w,&s_node.e);
	scanf("%d%d%d%d%d%d",&t_node.u,&t_node.d,&t_node.n,&t_node.s,&t_node.w,&t_node.e);

	bfs();

	if(gg[t_node.x][t_node.y][t_node.u][t_node.n] >= INF)
		printf("-1\n");
	else
		printf("%d\n",gg[t_node.x][t_node.y][t_node.u][t_node.n]);
	
}

int main()
{
	//freopen("in","r",stdin);
	while(scanf("%d%d",&n,&m) && n!=0 && m!=0)
	{
		solve();
	}
	return 0;
}
        