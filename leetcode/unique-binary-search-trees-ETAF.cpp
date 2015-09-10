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
    int numTrees(int n) {
        int dp[n+1];
        dp[0] = 1;
        for(int i=1; i<=n; ++i){
            dp[i] = 0;
            for(int j=0;j<i; ++j){
                dp[i]+= dp[j] * dp[i-1-j];
            }
        }
        return dp[n];
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    for(int i=1; i<=5; ++i)
        cout<<sol.numTrees(i)<<endl;
    return 0;
}


