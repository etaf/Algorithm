#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
using namespace std;

char s[100010];

void reverse(int l,int r)
{
	while(l<r)
	{
		s[l]^=s[r];
		s[r]^=s[l];
		s[l]^=s[r];
		++l;--r;
	}
}
void solve(int ca)
{
	gets(s);
	int l,r;
	int n = strlen(s);
	for(int i=0;i<n;++i)
	{
		l = i;
		while(i<n && s[i]!=' ')++i;
		reverse(l,i-1);;
		if(i == n)break;
	}
	reverse(0,n-1);
	printf("Case #%d: %s\n",ca,s);
}
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int T;
	scanf("%d",&T);
	getchar();
	for(int i=0;i<T;++i)
	{

		solve(i+1);
	}
	return 0;
}