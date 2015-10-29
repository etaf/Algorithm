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
        if(nums.empty()) return 0;
        if(nums.size()<2) return nums[0];
        return max(rob1(nums,0,nums.size()-1), rob1(nums,1,nums.size()));
    }
    int rob1(vector<int>& nums, int l, int r){
        unsigned int  a = 0, b =nums[l];
        for(int i=l+1;i<r; ++i){
            a = max(b,a+nums[i]);
            a^=b;
            b^=a;
            a^=b;
        }
        return max(a,b);

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


