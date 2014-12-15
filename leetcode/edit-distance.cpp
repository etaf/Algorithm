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
#include<limits.h>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
       int dp[2][1001];
       int n = word1.size();
       int m = word2.size();
       if(n==0)return m;
       if(m == 0) return n;
       for(int i=0;i<=m;++i)dp[0][i] = i;
       int c = 1;
       for(int i=1;i<=n;++i,c^=1)
       {
           dp[c][0] = i;
           for(int j=1;j<=m;++j){
               dp[c][j] = min(min(dp[c][j-1]+1,dp[1-c][j]+1),dp[1-c][j-1]+ (word1[i-1]!=word2[j-1]));
           }
       }
       return dp[1-c][m];
    }
};

void test(){
    string word1 = "a";
    string word2 = "bcdfdfa";
    Solution sol;
    cout<<sol.minDistance(word1,word2);
}
int main()
{
    test();
	return 0;
}


