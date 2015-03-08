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
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i=0;i<32;++i){
            res = (res<<1)+ (n&1);
            n >>= 1;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    cout<<sol.reverseBits(43261596)<<endl;
    return 0;
}


