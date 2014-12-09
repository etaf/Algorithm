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
const int N = 1001;
int a[N],p[N][2];
void solve(int ca)
{
	memset(a,0,sizeof(a));
	memset(p,0,sizeof(p));
	int n,v,x;
	
	scanf("%d%d",&v,&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&x);
		a[x]++;
		if(p[x][0] == 0)p[x][0] = i;
		else if(p[x][1] == 0)p[x][1] = i;
		
	}
	int ans1,ans2;
	for(int i=1;i<v;++i)
	{
		if(a[i] && a[v-i])
		{
			ans1 = p[i][0];
			if(v-i == i)
			{
				if(a[i]<2)continue;
				ans2 = p[i][1];
			}
			else
			{
				ans2 = p[v-i][0];
			}
			if(ans1>ans2)
			{
				ans1^=ans2;
				ans2^=ans1;
				ans1^=ans2;
			}
			printf("Case #%d: %d %d\n",ca,ans1,ans2);
			return;
		}
	}				
}
int main()
{

	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;++i)
	{
		solve(i);
	}
	return 0;
}