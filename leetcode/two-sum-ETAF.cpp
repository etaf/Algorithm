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
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> M;
        for(int i = 0; i<nums.size(); ++i){
            auto it = M.find(target-nums[i]);
            if(it != M.end()) return {it->second + 1, i+1};
            M.insert(pair<int,int>(nums[i],i));
        }
        return {0,0};
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    vector<int> nums({2,0,0,7,11,15});
    int target = 0;
    vector<int> ans = sol.twoSum(nums, target);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}


