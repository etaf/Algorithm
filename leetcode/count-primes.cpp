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

    int countPrimes(int n) {
        int ans = 0;
        bool not_prime[n];
        memset(not_prime,0,sizeof(not_prime));
        for(int i=2;i<n;++i){
            if(not_prime[i])continue;
            ans++;
            for(long long j=i+i;j<n;j+=i){
                not_prime[j] = 1;
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    cout<<sol.countPrimes(3)<<endl;
    return 0;
}


