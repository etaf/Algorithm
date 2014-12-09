#include<iostream>                                                                                                                                             
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
typedef long long LL;
const int N = 5001;
const int MOD = 1000000007;
const int INF = 0x3fffffff;
int a[N];

int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 0;i<m;++i)
	{
		scanf("%d",a+i);
	}
	sort(a,a+m);
	int ans = INF;
	for(int i=0;i+n-1<m;++i)
	{
		ans = min(ans, a[i+n-1]-a[i]);
	}

	printf("%d\n",ans);
	return 0;
}