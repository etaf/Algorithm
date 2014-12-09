#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;

#define INF 0x3fffffff
const int N= 100010;
int pre[N][2];
int nextp[N];
int path1[N],path2[N];
int cp1,cp2;

int main()
{
	int n, u,v,st1,st2;
	scanf("%d%d%d",&st1,&st2,&n);
	char c;
	int endp = -1;
	int cnte = 0;
	for(int i=0;i<n;++i)
	{
		scanf("%d %c%d",&u,&c,&v);
		nextp[u] = v;
	}

	cp1 = cp2 = 0;
	if(st1 == -1 || st2 == -1)
	{
		printf("-1\n");
		return 0;
	}
	if(st1 == st2)
	{
		printf("%05d\n",st1);
		return 0;
	}
	memset(pre,-1,sizeof(pre));
	while(st1!=-1)
	{
		path1[cp1++] =st1;

		pre[ nextp[st1] ][0]  = st1 ;
		st1 = nextp[st1];
	}
	while(st2!=-1)
	{
		path2[cp2++] = st2;
		pre[ nextp[st2]][1] = st2;
		st2 = nextp[st2];
	}
	if(path1[cp1-1] != path2[cp2-1])
	{
		printf("-1\n");
		return 0;
	}
	endp = path1[cp1-1];
	while(pre[endp][0] == pre[endp][1] )
	{
		endp = pre[endp][0];
	}
	printf("%05d\n",endp);
	return 0;
}

/*
1 2 3
1 a -1
2 b 1
3 c 1
*/