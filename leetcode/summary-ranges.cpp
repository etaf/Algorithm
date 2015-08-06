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
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.empty()) return ans;
        int l = 0;
        for(int i=0; i<nums.size(); ++i){
            if(i+1 == nums.size() ||  nums[i] + 1 != nums[i+1] )
            {
                if(i==l)
                    ans.push_back(std::to_string(nums[i]));
                else
                    ans.push_back(std::to_string(nums[l])+"->"+std::to_string(nums[i]));
                l = i+1;
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> nums({-2147483648,-2147483647,2147483647});
    Solution sol;
    vector<string> ans = sol.summaryRanges(nums);
    for(int i=0; i<ans.size(); ++i){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}


