#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
#define INF 0x3fffffff
const int N = 1011;

int a[N],r[N],nr[N],Rank[N];
vector<int> level[N];
int main()
{
	int i,j;
	int n,m;
	scanf("%d%d",&n,&m);
	for( i=0;i<n;++i)
		scanf("%d",&a[i]);
	for(i=0;i<n;++i)
		scanf("%d",&r[i]);
	int len = n;
	int lev = 1;
	int *p = r;
	int *q = nr;
	int *swapt;
	int maxn=-INF;
	int maxp;
	int cnt;
	while(len>1)
	{

		cnt = 0;
		for(i=0;i+m-1<len;i+=m)
		{
			maxn = -INF;
			for(j=i;j<i+m;++j)
			{
				if(a[ p[j] ]>maxn)
				{
					maxn = a[p[j]];
					maxp = p[j];
				}
			}
			for(j=i;j<i+m;++j)
			{
				if(p[j]!=maxp)
					level[lev].push_back(p[j]);
			}
			q[cnt++] = maxp;
		}
		if(i<len)
		{
			maxn = -INF;
			for(j=i;j<len;++j)
			{
				if(a[ p[j] ]>maxn)
				{
					maxn = a[p[j]];
					maxp = p[j];
				}

			}
			for(j=i;j<len;++j)
			{
				if(p[j]!=maxp)
					level[lev].push_back(p[j]);
			}
			q[cnt++] = maxp;
		}

		swapt = p;
		p = q;
		q = swapt;

		++lev;
		
		len = cnt;
		

		
	}
	level[lev].push_back(p[0]);

	int r=1;
	for(i=lev;i>0;--i)
	{
		for(j=0;j<level[i].size();++j)
		{
			Rank[ level[i][j] ] = r;
		}
		r+=level[i].size();
	}
	
	printf("%d",Rank[0]);
	for(int i=1;i<n;++i)printf(" %d",Rank[i]);

	printf("\n");

	return 0;
}
/*
11 3
25 18 0 46 37 3 19 22 57 56 10
6 0 8 7 10 5 9 1 4 2 3

11 100
25 18 0 46 37 3 19 22 57 56 10
6 0 8 7 10 5 9 1 4 2 3

11 1
25 18 0 46 37 3 19 22 57 56 10
6 0 8 7 10 5 9 1 4 2 3



*/