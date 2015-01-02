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
class Solution { //dp
public:
    bool isMatch(const char *s, const char *p) {
        int n = strlen(s),m = strlen(p);
        bool dp[2][m+1];
        cout<<sizeof(dp)<<endl;
        //bool dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        int c = 1;
        for(int j=1;j<=m;++j){
            if(p[j-1] == '*'){
                dp[0][j] = dp[0][j-1];
                if(j>1) dp[0][j] = dp[0][j] || dp[0][j-2];
            }
        }
        /*for(int j=0;j<=m;++j)cout<<dp[0][j]<<" ";*/
        /*cout<<endl;*/
        for(int i=1;i<=n;++i,c^=1){
            dp[c][0] = 0;
            for(int j=1;j<=m;++j){
                if(p[j-1] == '.' || p[j-1] == s[i-1]){
                    dp[c][j] = dp[c^1][j-1];
                }
                else if(p[j-1] == '*'){
                    dp[c][j] = dp[c][j-1];
                    if(j>1)dp[c][j] = dp[c][j] || dp[c][j-2];
                    if(j>1 && i>1 && (p[j-2] == '.' || s[i-1]==p[j-2] )) dp[c][j] = dp[c][j] || dp[c^1][j];
                }else{
                    dp[c][j] = 0;
                }

            }
          /*  for(int j=0;j<=m;++j)cout<<dp[c][j]<<" ";*/
            /*cout<<endl;*/
        }
        return dp[c^1][m];
    }
};
int main()
{
    Solution sol;
    //cout<<sol.isMatch("aab","c*a*b")<<endl;
    //cout<<sol.isMatch("","a*")<<endl;
    cout<<sol.isMatch("aaa",".*fjasklfjdklsafjls")<<endl;
    return 0;
}


