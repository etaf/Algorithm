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
class Solution { //dp[i][j] means start from point (i,j) end at point (n-1,m-1) need at least dp[i][j] health.
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;--i){
            for(int j=m-1; j>=0; --j){
                if(i+1==n && j+1 == m){
                    dp[i][j] = max(1-dungeon[i][j],1);
                    continue;
                }
                if(j+1<m){
                    dp[i][j] = max(dp[i][j+1] - dungeon[i][j],1);
                }
                if(i+1<n){
                    if(dp[i][j])
                        dp[i][j] = min(dp[i][j],max(dp[i+1][j] - dungeon[i][j],1));
                    else
                        dp[i][j] = max(dp[i+1][j]-dungeon[i][j],1);
                }
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j)cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        return dp[0][0];
    }
};
int main()
{
    vector<vector<int> > g({{-2,-3,3},{-5,-10,1},{10,30,-5}});
    Solution sol;
    cout<<sol.calculateMinimumHP(g)<<endl;

    return 0;
}


