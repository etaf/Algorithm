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
    bool canJump(vector<int>& nums) {
        int rst = 0 ,i=0;
        for(; i<=rst && i<nums.size(); ++i){
            rst = max(rst, nums[i]+i);
        }
        return i == nums.size();
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    //vector<int> nums({2,3,1,1,4});
    vector<int> nums({3,2,1,0,4});
    cout<<sol.canJump(nums)<<endl;
    return 0;
}


