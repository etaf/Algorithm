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
    int rob(vector<int> &num) {
        if(num.empty()) return 0;
        int n = num.size();
        unsigned int  a = 0, b =num[0];
        for(int i=1;i<n; ++i){
            a = max(b,a+num[i]);
            a^=b;
            b^=a;
            a^=b;
        }
        return max(a,b);
    }
};

class Solution_old {
public:
    int rob(vector<int> &num) {
        if(num.empty()) return 0;
        int n = num.size();
        unsigned int dp[n+1];
        dp[0] = 0;
        dp[1] = num[0];
        for(int i=2;i<=n; ++i){
            dp[i] = max(dp[i-1], dp[i-2] + num[i-1]);
        }
        return dp[n];
    }
};
int main()
{
    Solution sol;
    vector<int> num({1000,1,2,100});
    cout<<sol.rob(num)<<endl;
    return 0;
}


