
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
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long l = 0, r = n,mid;
        while(l+1<r){
            mid = (l+r)>>1;
            if(isBadVersion(mid)) r = mid;
            else l = mid;
        }
        return r;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    return 0;
}


