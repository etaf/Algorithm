#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
const int N = 100010;
int a1[N],a2[N],b1[N],b2[N];
int ca1,ca2,cb1,cb2;

bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	int n,m,x;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&x);
		if(x>=0) a1[ca1++] = x;
		else a2[ca2++] = x;
	}
	scanf("%d",&m);
	for(int i=0;i<m;++i)
	{
		scanf("%d",&x);
		if(x>=0) b1[cb1++] = x;
		else b2[cb2++] = x;
	}

	sort(a1,a1+ca1,cmp);
	sort(b1,b1+cb1,cmp);
	sort(a2,a2+ca2);
	sort(b2,b2+cb2);
	long long ans = 0;
	for(int p=0,q=0;p<ca1 && q<cb1;++p,++q)
	{
		ans+=a1[p]*b1[q];
	}
	for(int p=0,q=0;p<ca2 && q<cb2; ++p,++q)
	{
		ans+=a2[p]*b2[q];
	}
	printf("%ld\n",ans);
	return 0;
}