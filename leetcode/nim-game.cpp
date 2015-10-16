
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
typedef long long llong;
using namespace std;
class Solution {
public:
    bool canWinNim(int n) {
        //if(n%4) return true;
        if(n&3) return true;
        return false;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    for(int i=1;i<20;++i){
        cout<<sol.canWinNim(i)<<endl;
    }
    return 0;
}


