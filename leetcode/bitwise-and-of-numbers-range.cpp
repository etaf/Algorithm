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
    int rangeBitwiseAnd(int m, int n) {
        int f = 0;
        while(n!=m){
            n>>=1;
            m>>=1;
            ++f;
        }
        return n<<f;
    }
};

class Solution_mine {
public:
    int rangeBitwiseAnd(int m, int n) {
        int t = n ^ m;
        int x = (1 << 30);
        int i= 0;
        for(i=31;i>0;--i, x = x | ( x >> 1)){
            if(x&t){
                break;
            }
        }
        if(i==0){
            return n;
        }
        else{
            return m & (x<<1);
        }
    }
};
int main()
{
    Solution sol;
    cout<<sol.rangeBitwiseAnd(1,3)<<endl;
    return 0;
}


