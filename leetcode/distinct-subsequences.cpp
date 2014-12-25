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
    int numDistinct(string S, string T) { //dp[i][j] means first i char of S cantain dp[i][j] of the first j char of T
        int m = S.size(), n = T.size();
        int  dp[2][100010];
        memset(dp,-1,sizeof(dp));
        dp[0][0] = dp[1][0]= 1;
        int c = 1;
        for(int i=1;i<=m;++i,c^=1){
            for(int j=1;j<=n;++j){
                if(dp[c^1][j] != -1){
                    dp[c][j] = dp[c^1][j] + (S[i-1] == T[j-1] ? dp[c^1][j-1] : 0);
                }
                else if(dp[c^1][j-1] !=-1 && S[i-1] == T[j-1]){
                    dp[c][j] = dp[c^1][j-1];
                }

            }
        }
        /*for(int i=0;i<=m;++i){*/
            //for(int j=0;j<=n;++j)cout<<dp[i][j]<<" ";
            //cout<<endl;
        /*}*/

        return dp[c^1][n] == -1 ? 0 : dp[c^1][n];
    }
};
int main()
{
    Solution sol;
    //cout<<sol.numDistinct("rabbbit","rabbit")<<endl;
    cout<<sol.numDistinct("1112222334344","1234")<<endl;
    return 0;
}


