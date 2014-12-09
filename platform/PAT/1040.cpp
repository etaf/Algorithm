#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;


const int N = 1001;
int dp[N][N];
int lss(char* s)
{
	int ans = 1;
	int n = strlen(s);
	for(int i=0;i<n; ++i)
	{
		dp[i][i] = 1;
	}

	for(int i=0;i+1<n;++i)
		if(s[i] == s[i+1])
		{
			dp[i][i+1] = 1;
			ans = 2;
		}
	for(int len = 2;len<n;++len)
	{
		for(int i=0,j;i+len<n;++i)
		{
			j=i+len;
			dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
			if(dp[i][j])
				ans = ans>len+1?ans:len+1;
		}
	}
	return ans;
}
int main()
{
	char s[1010];
	gets(s);
	printf("%d\n",lss(s));
	return 0;
}