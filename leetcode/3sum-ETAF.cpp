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
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        sort(nums.begin(), nums.end());
        int target,  l , r;
        for(int i=0; i<nums.size(); ++i)
        {
            target = 0 - nums[i];
            l = i+1;
            r = nums.size()-1;
            while(l<r){
                if(nums[l] + nums[r] == target){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while(l+1<r && nums[l] == nums[l+1]) ++l;
                    ++l; --r;
                    //break;
                }
                else if(nums[l] + nums[r] > target) --r;
                else ++l;
            }
            while(i+1 < nums.size() && nums[i] == nums[i+1]) ++i;
        }
        return ans;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    //vector<int> num({-1,0,1,2,-1,2,-4,0,0});
    vector<int> num({-2,0,0,2,2});
    vector<vector<int> > ans = sol.threeSum(num);
    sort(num.begin(),num.end());
    for(int i=0;i<ans.size();++i){
        for(int j=0;j<ans[i].size();++j){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}


