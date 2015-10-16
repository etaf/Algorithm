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
typedef long long llong;
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        int dp[n];
        dp[0] = 0;
        for(int i=1;i<=n; ++i){
            dp[i] = dp[i-1]+1;
            for(int j=2; j*j<=i; ++j){
                dp[i] = min(dp[i], 1+dp[i-j*j]);
            }
        }
        return dp[n];
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    for(int i=1;i<=50; ++i)
        cout<<i<<" : "<<sol.numSquares(i)<<endl;

    return 0;
}


