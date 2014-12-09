#include<iostream>
#include<set>
#include<algorithm>
#include<cstring>
using namespace std;
#define INF 0x3fffffff


typedef struct Node{
	
	int ad,v,next;
	bool operator<(const Node& z)const 
	{ return v<z.v;}
}Node;

Node ns[100010];
Node nns[100010];
int nad[100010];
int main()
{
	int p,v,q;
	int n,st;
	scanf("%d%d",&n,&st);
	for(int i=0;i<n;++i)
	{
		scanf("%d%d%d",&ns[i].ad,&ns[i].v,&ns[i].next);
		nad[ ns[i].ad ] = i;
	}
	int nnt = 0;
	if(st == -1)
	{
		printf("0 -1\n");
		return 0;
	}
	while(st!=-1)
	{
		nns[nnt++] = ns[ nad[st] ] ;
		st = ns[ nad[st]].next;
	}
	
	sort(nns,nns+nnt);

	printf("%d %05d\n",nnt,nns[0].ad);
	for(int i=0;i<nnt-1;++i)
	{
		printf("%05d %d %05d\n",nns[i].ad,nns[i].v,nns[i+1].ad);
	}
	printf("%05d %d -1\n",nns[nnt-1].ad,nns[nnt-1].v);
	return 0;
}
/*
6 12
12 0 -1
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345
*/