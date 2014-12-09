#include<iostream>
#include<cstdio>
using namespace std;
const int N = 100010;

typedef struct Node
{
	int pos,v,next;
}Node;
Node np[N],ns[N];

void reverse(int l,int r)
{
	Node tmp;
	while(l<r)
	{
		tmp = ns[l];
		ns[l] = ns[r];
		ns[r] = tmp;
		++l;--r;
	}

}
int main()
{
	int fn,n,k;
	scanf("%d%d%d",&fn,&n,&k);
	int pos,next,v;
	for(int i=0;i<n;++i)
	{
		scanf("%d%d%d",&pos,&v,&next);
		np[pos].pos = pos;
		np[pos].next = next;
		np[pos].v  = v;
	}
	int cnt = 0;
	while(fn != -1)
	{
		ns[cnt++] = np[fn];
		fn = np[fn].next;
	}
	for(int i=0;i+k<=cnt;i+=k)
	{
		reverse(i,i+k-1);
	}
	for(int i=0;i<cnt-1;++i)
	{
		printf("%05d %d %05d\n",ns[i].pos,ns[i].v,ns[i+1].pos);
	}
	printf("%05d %d -1\n",ns[cnt-1].pos,ns[cnt-1].v);
	return 0;
}