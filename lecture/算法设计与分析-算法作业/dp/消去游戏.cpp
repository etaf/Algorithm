 /*
 dp[i][j]  表示 前i个至少还要放入j个才能全部消除 的方案数
 dp[i][j] = dp[i-1][j+1] + dp[i-1][j-k+1]*(h-1)    (j != k-1)
						 + dp[i-1][j-k+1]*h        (j == k-1)
 */
#include<iostream>
#include<cstring>
using namespace std;
const int N= 1001;
const int MOD = 1000000007;
typedef __int64 llong;
int a[N];
int dp[2][N];
int n,m,h,k;
void solve()
{
	int i;
	for(i=1;i<=n;++i)
	{
		scanf("%d",a+i);
	}
	int cnt=0;
	for(i=1;i<=n;++i)
	{
		cnt+=k-1;
		while(i+1<=n && a[i]==a[i+1])
		{
			++i;
			--cnt;
		}
	}
	dp[0][cnt]=1;
	int len = n+m;
	int c=1;
	llong hh=h;
	for(i=n+1;i<len;++i,c=1-c)
	{
		for(int j=0;j<=len-i;++j)
		{
			dp[c][j] = dp[1-c][j+1];
			if(j==k-1)
			{
				dp[c][j]= (dp[c][j]+dp[1-c][j-k+1]*(hh) )%MOD;
			}else if(j>k-1)
			{
				dp[c][j]=(dp[c][j] + dp[1-c][j-k+1]*(hh-1))%MOD;
			}
		}
	}
	
	printf("%d\n",dp[1-c][1]);
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&h,&k);
	memset(dp,0,sizeof(dp));
	solve();
	return 0;
}
        