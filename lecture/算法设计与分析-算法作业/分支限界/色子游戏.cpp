/*
�㷨ʵ����ҵ6-1 ɫ����Ϸ����
?����������
ɫ����Ϸ��һ���� N*M �ķ����Ͻ��е�������Ϸ�����̵�ÿ�дӱ����ϱ����Ϊ 0 ��
N-1��ÿ�д������������Ϊ 0 �� M-1������ͼ��ʾ��
�����ϵ�ÿһ�����������һ������(x��y)��ʾ��x ���б�ǣ�y ���б�ǡ�
ÿһ��ɫ�Ӷ���һ�������壬����������ֱ𱻱��Ϊ 1��2��3��4��5 �� 6�����б��
Ϊ 1��2 �� 3 �����������ڣ����Ϊ 6 ��������Ϊ 1 �����෴�����Ϊ 5 ��������Ϊ 2 �����෴�����Ϊ 4 ��������Ϊ 3 �����෴��
ɫ����Ϸ����
ɫ�ӳ�ʼʱ������һ�������ϣ�Ҫ�ƶ�ɫ�ӣ���ҿ���ˮƽ��ֱ����ɫ�ӵ����ڵķ�
���ϡ���Ϸ��Ŀ����Ҫ�������ٵ��ƶ���������ɫ�Ӵӳ�ʼλ���ƶ���Ŀ��λ�á�ɫ�ӵ�״
̬������Ŀ��λ�õ�״̬��һ�¡�
?�������
�����ٵ��ƶ���������ɫ�Ӵӳ�ʼλ���ƶ���Ŀ��λ�ò���ʹ��ɫ�ӵ�״̬��Ŀ��λ��
��״̬��һ�¡�
?�������룺
�������ݵĵ�һ��Ϊ���������� N �� M��1��N��M��100�������� N �У�ÿ�а��� M���ַ����ַ���'#'������'.'�������'#'����ʾ���������һ���ϰ��ɫ���޷���ת�����
���������'.'����ʾ���������һ���ո�ɫ�ӿ��Է�ת������������� N*M ���ַ�
��ʾ N*M �ķ������̣�ɫ�Ӳ����ƶ�������֮�⡣
����һ�����ĸ����� x1��y1��x2��y2��(x1��y1)��(x2��y2)�ֱ��ʾ��ʼλ�������Ŀ
��λ�����ꡣ��ʼλ�������Ŀ��λ��������Կ�����'.'�ķ����������зֱ��ʾ��ʼλ
��ʱɫ�ӵ�״̬��Ŀ��λ��ʱɫ�ӵ�״̬��ɫ�ӵ�״̬��ɫ�ӵ�����������ʾ��ÿ�е�����
���ֱַ��ʾɫ�ӵ��ϣ��£������ϣ��������档
���������ж��飬�� N=0 ���� M=0 ʱ����ʾ�������ݽ�����
?������: ����������ٵ��ƶ��������������޷��ӳ�ʼ�㵽Ŀ��㣬�����-1����
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
        