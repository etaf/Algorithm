
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
    int rob(vector<int>& nums) {
        int dp1 = 0, dp2 = 0, dp3 = 0, tmp;
        for(int i=0; i<nums.size(); ++i){
            tmp = dp3;
            dp3 = nums[i] + max(dp1,dp2);
            dp1 = dp2;
            dp2 = tmp;
        }
        return max(dp3,dp2);
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    vector<int> num({1000,1,2,100});
    cout<<sol.rob(num)<<endl;

    return 0;
}


