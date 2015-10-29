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
    int get_sum(int n){
        int res = 0,tmp;
        while(n){
            tmp = n%10;
            n/=10;
            res += tmp*tmp;
        }
        return res;
    }
    bool isHappy(int n) {
        bool f[654];
        memset(f,0,sizeof(f));
        while(n!=1){
            n = get_sum(n);
            if(f[n]) return false;
            f[n] = true;
        }
        return true;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    cout<<sol.isHappy(130)<<endl;
    return 0;
}


