 
            /*
±à¼­¾àÀë
1. É¾³ı
2. ²åÈë
3. ĞŞ¸Ä

dp[i][j] = min ( dp[i][j-1] + 1, dp[i-1][j]+1,dp[i-1][j-1]+(a[i] == b[j])

abcab
abab


*/

#include<stdio.h>
#include<string.h>

const int N = 2011;
int dp[N][N];
char s1[N],s2[N];

inline int min(int x,int y)
{return x<y?x:y;}
int main()
{
	int i,j;
	scanf("%s%s",s1,s2);
	int n,m;
	n = strlen(s1);
	m = strlen(s2);
	for(i=0;i<=n;++i)dp[i][0] = i;
	for(j=0;j<=m;++j)dp[0][j] = j;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j)
		{
			dp[i][j]= min(min(dp[i][j-1]+1,dp[i-1][j]+1),dp[i-1][j-1]+!(s1[i-1] == s2[j-1]));
		}
	}
	printf("%d\n",dp[n][m]);
	return 0;
}

        