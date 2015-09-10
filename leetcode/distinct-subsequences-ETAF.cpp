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
class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n; ++i){
            dp[i][0] = 1;
        }
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                dp[i][j] = dp[i-1][j] + (s[i-1] == t[j-1] ? dp[i-1][j-1] : 0);
            }
        }
        return dp[n][m];
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    //cout<<sol.numDistinct("rabbbit","rabbit")<<endl;
    cout<<sol.numDistinct("1112222334344","1234")<<endl;

    return 0;
}


