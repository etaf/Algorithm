
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
        int dp[12];
        dp[0] = 0;
        int p10[12];
        p10[0] = 1;
        for(int i=1;i<11;++i){
            dp[i] = dp[i-1]*10 + p10[i-1];
            p10[i] =p10[i-1] * 10;
        }
        int num[12], cnt=0;
        while(n){
            num[cnt++] = n%10;
            n/=10;
        }
        int sum[12];
        sum[0] = 0;
        for(int i=1; i<=cnt;++i){
            sum[i] = sum[i-1] + num[i-1] * p10[i-1];
        }
        int res = 0;
        for(int i=cnt-1;i>=0;--i){
            res += num[i]*dp[i] +(num[i]>1 ? p10[i] : num[i]==1 ? sum[i]+1: 0);
        }
        return res;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    cout<<sol.countDigitOne(101)<<endl;
    cout<<sol.countDigitOne(1)<<endl;
    cout<<sol.countDigitOne(0)<<endl;
    cout<<sol.countDigitOne(10)<<endl;
    return 0;
}


