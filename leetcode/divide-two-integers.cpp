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
        int f = 1;
        long long _dividend = dividend;
        long long _divisor = divisor;
        if(_divisor<0){
            f*=-1;
            _divisor = - _divisor;
        }
        if(_dividend<0){
            f*=-1;
            _dividend = -_dividend;
        }
        if(_divisor == 0) return INT_MAX;
        if(_dividend == 2147483648LL && _divisor == 1){
            if( f == 1 ) return 2147483647;
            else return -2147483648;
        }
        int res = 0;
        long long tmp[32];
        tmp[0] = _divisor;
        int i;
        for(i=1;i<31;++i){
            tmp[i] = tmp[i-1]+tmp[i-1];
            if(tmp[i]>=_dividend) break;
        }
        for(;i>=0;--i){
            if(tmp[i]<=_dividend){
                res += (1<<i);
                _dividend -= tmp[i];
            }
        }
        return res*f;
    }
};
int main()
{
    Solution sol;
    cout<< sol.divide(-2147483648, -1)<<endl;
    cout<< sol.divide(100, -2)<<endl;
    return 0;
}


