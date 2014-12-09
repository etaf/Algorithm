/*
dp[i][j] 表示前i个放j个A后最多能放多少个B
dp[i][j] = max（dp[i-1][j]，dp[i-3][j-1]	          当前 (i-3 ：i) 能放 A
		   max( dp[i-1][j], dp[i-3][j] + 1)		  当前 （i-3：i）能放 B
		   dp[i-1][j]							  不能放A或B							
*/

#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 1001;
char s[N];
int dp[N][N];
inline int max(int x,int y)
{
	return x>y?x:y;
}
inline int min(int x,int y)
{
	return x<y?x:y;
}
void solve()
{
	int ans,i,j;
	int n=strlen(s);
	if(n<6)
	{
		printf("0\n");
		return;
	}
	int cnt=0,t;
	 if(s[2]=='a' && s[1]=='c' && s[0] == 'b')
	{
			dp[2][0]=1;
	}
	
	for(i=3;i<n;++i)
	{
		if(s[i] == 'c' && s[i-1]=='b' && s[i-2] == 'a')
		{
			t=1;
		}
		else if(s[i]=='a' && s[i-1]=='c' && s[i-2] == 'b')
		{
			t=2;
		}
		else
		{
			t=0;
		}
		if(t==1)++cnt;
		
		for(j=0;j<=cnt;++j)
		{
			if(t==1)
			{//放A或不放
				dp[i][j] = dp[i-1][j];
				if(j>0)
					dp[i][j] = max(dp[i][j],dp[i-3][j-1]);
			}else if(t==2)
			{//放B或不放
				dp[i][j]=max(dp[i-3][j]+1,dp[i-1][j]);
			}else
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	ans = 0;

	for(i=0;i<=cnt;++i)
	{
		ans=max(ans,min(i,dp[n-1][i]));
	}

	printf("%d\n",ans*3);
}
int main()
{

	scanf("%s",s);
	memset(dp,0,sizeof(dp));
	solve();

return 0;
}
        