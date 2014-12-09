#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

char g[64][64];
const int N= 4;
bool check(char c)
{
	int cn=0,ct=0;
	for(int i=0;i<N;++i)
	{
		cn = 0;ct = 0;
		for(int j=0;j<N;++j)
		{
			if(g[i][j] == 'T')++ct;
			if(g[i][j] == c) ++cn;
		}
		if(cn == N)return true;
		if(cn == N-1 && ct == 1)return true;
	}
	for(int j=0;j<N;++j)
	{
		cn=0;ct=0;
		for(int i=0;i<N;++i)
		{
			if(g[i][j] == 'T')++ct;
			if(g[i][j] == c)++cn;
		}
		if(cn == N)return true;
		if(cn == N-1 && ct == 1)return true;
	}
	cn =0;ct = 0;
	for(int i=0;i<N;++i)
	{
		if(g[i][i] == 'T')++ct;
		if(g[i][i] == c)++cn;
	}
	if(cn == N || (cn == N-1 && ct == 1) )return true;
	cn = 0;ct = 0;
	for(int i=0;i<N;++i)
	{
		if(g[i][N-i-1] == 'T')++ct;
		if(g[i][N-i-1] == c) ++cn;
	}
	if(cn == N || (cn == N-1 && ct == 1))return true;
	return false;
}
void solve(int ca)
{
	int cnt = 0;
	for(int i=0;i<N;++i){
		scanf(" %s",g[i]);
	}
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<N;++j)
		{
			if(g[i][j] == '.')
				++cnt;
		}
	}
	bool f1 = false;
	bool f2 = false;
	f1 = check('X');
	f2 = check('O');
	if(f1 && !f2)
	{
		printf("Case #%d: X won\n",ca);
	}
	else if(!f1 && f2)
	{
		printf("Case #%d: O won\n",ca);
	}
	else if(cnt ==0 )
	{
		printf("Case #%d: Draw\n",ca);

	}else
	{
		printf("Case #%d: Game has not completed\n",ca);
	}
}
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		solve(i);
	}
	return 0;
}