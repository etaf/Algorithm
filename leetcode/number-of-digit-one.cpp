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
typedef long long llong;
class Solution {
public:
    int countDigitOne(int n) {
        llong  dp[12];
        llong p10[12];
        dp[0] = 0;
        p10[0] = 1;
        for(int i=1; i<11; ++i){
            dp[i] = dp[i-1]*10 + p10[i-1];
            p10[i] = p10[i-1] * 10;
        }
        int ns[12], cnt=1, nn[12];
        while(n){
            ns[cnt++] = n%10;
            n/=10;
        }
        nn[0] = 0;
        for(int i=1; i<cnt; ++i){
            nn[i] = ns[i] * p10[i-1]  + nn[i-1];
        }
        int ans = 0;
        for(int i=cnt-1; i>0; --i){
            ans += dp[i-1] * ns[i] + (ns[i] > 1 ? p10[i-1] : ns[i] == 1 ? nn[i-1] + 1: 0);
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    cout<<sol.countDigitOne(101)<<endl;
    cout<<sol.countDigitOne(1)<<endl;
    cout<<sol.countDigitOne(0)<<endl;
    cout<<sol.countDigitOne(10)<<endl;
    return 0;
}


