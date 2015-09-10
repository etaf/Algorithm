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
class Solution_old {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n){
            res += (n&1);
            n>>=1;
        }
        return res;
    }
};
class Solution_old1 {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n){
            ++res;
            n&=(n-1);
        }
        return res;
    }
};
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        int a[16] = {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
        int x = 15;
        while(n){
            res += a[n&x];
            n>>=4;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    cout<<sol.hammingWeight(5)<<endl;
    return 0;
}


