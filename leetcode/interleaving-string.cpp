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
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<cstdlib>
using namespace std;
/*
 * dp[i][j] meads whether  first i char of s1 and first j char of s2 can form first (i+j)char of s3
 *
 */
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        bool dp[1010];
        memset(dp,0,sizeof(dp));
        int n = s1.size(), m = s2.size();
        if(n+m != s3.size())return false;
        dp[0]= 1;
        for(int j=1;j<=m;++j){
            if(s3[j-1] == s2[j-1]) dp[j] = dp[j-1];
            else break;
        }
        /*for(int j=0;j<=m;++j)cout<<dp[j]<<" ";*/
        /*cout<<endl;*/
        for(int i=1;i<=n;++i){
            if(s3[i-1] != s1[i-1]) dp[0]=0;
            for(int j=1;j<=m; ++j){
                if(s3[i+j-1] != s1[i-1] && s3[i+j-1] != s2[j-1])
                    dp[j] = 0;
                else if(s3[i+j-1] == s1[i-1] && s3[i+j-1] == s2[j-1])
                    dp[j] = dp[j-1] || dp[j];
                else if(s3[i+j-1] == s2[j-1]) dp[j] = dp[j-1];
            }
            /*for(int j=0;j<=m;++j)cout<<dp[j]<<" ";*/
            /*cout<<endl;*/
        }
        return dp[m];
    }
};
class Solution_n2space {
public:
    bool isInterleave(string s1, string s2, string s3) {
        bool dp[1010][1010];
        memset(dp,0,sizeof(dp));
        int n = s1.size(), m = s2.size();
        if(n+m != s3.size())return false;
        dp[0][0]= 1;
        for(int j=1;j<=m;++j){
            if(s3[j-1] == s2[j-1]) dp[0][j] = dp[0][j-1];
        }
        for(int i=1;i<=n;++i){
            if(s3[i-1] == s1[i-1]) dp[i][0] = dp[i-1][0];
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m; ++j){
                if(s3[i+j-1] == s1[i-1])
                    dp[i][j] = dp[i-1][j];
                if(s3[i+j-1] == s2[j-1] && dp[i][j] == 0)
                    dp[i][j] = dp[i][j-1];
            }
        }
        for(int i=0;i<=n;++i){
            for(int j=0;j<=m;++j)cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        return dp[n][m];
    }
};
int main()
{
    Solution sol;
    Solution_n2space sol2;
    //cout<<(sol.isInterleave("aabcc","dbbca","aadbbcbcac")?"true":"false")<<endl;
    //cout<<(sol.isInterleave("aabcc","dbbca","aadbbbaccc")?"true":"false")<<endl;
    //cout<<(sol.isInterleave("ab","bc","babc")?"true":"false")<<endl;
    cout<<(sol.isInterleave("aacaac","aaeaac","aaeaaeaacaac")?"true":"false")<<endl;
    cout<<(sol2.isInterleave("aacaac","aaeaac","aaeaaeaacaac")?"true":"false")<<endl;
    return 0;
}


