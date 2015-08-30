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
    int divide(int dividend, int divisor) {
        long long _dividend = dividend, _divisor = divisor;
        _dividend = abs(_dividend);
        _divisor = abs(_divisor);
        int f;
        if(dividend < 0 && divisor < 0 || dividend > 0 && divisor > 0) f = 1;
        else f = -1;
        if(_dividend < _divisor) return 0;
        long long ress[32], ans = 0;
        ress[0] = _divisor;
        int i = 0;
        for(; i<32; ++i){
            if(ress[i] >= _dividend) break;
            ress[i+1] = ress[i] + ress[i];
        }
        for(;i>=0; --i){
            if(_dividend - ress[i] >=0 ){
                _dividend -= ress[i];
                ans += (1ll<<i);
            }
        }
        //cout<<"ans="<<ans<<endl;
        if(f==1){
            return min(ans, (long long)INT_MAX);
        }else{
            return max(-ans, (long long)INT_MIN);
        }
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    cout<< sol.divide(-2147483648, -1)<<endl;
    cout<< sol.divide(100, -2)<<endl;

    return 0;
}


