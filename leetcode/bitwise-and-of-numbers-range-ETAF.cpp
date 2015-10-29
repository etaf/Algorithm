
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
class Solution{
public:
    int rangeBitwiseAnd(int m, int n) {
        while(n>m) n &= (n-1);
        return n;
    }
};

class Solution_old {
public:
    int rangeBitwiseAnd(int m, int n) {
        m^=n;
        int msk = 1<<30;
        if(!m) return n;
        while( (m&msk) == 0){
            msk |= (msk >> 1);
        }
        msk <<= 1;
        return n & msk;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    cout<<sol.rangeBitwiseAnd(5,7)<<endl;
    cout<<sol.rangeBitwiseAnd(1,1)<<endl;
    return 0;
}


