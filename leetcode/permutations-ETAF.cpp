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
class Solution_old {
public:
    vector<vector<int> > ans;
    vector<vector<int> > permute(vector<int>& nums) {
        dfs(0, nums);
        return ans;
    }
    void dfs(int u, vector<int>& nums){
        if( u == nums.size()){
            ans.push_back(nums);
        }
        for(int i=u; i<nums.size(); ++i){
            std::swap(nums[i], nums[u]);
            dfs(u+1, nums);
            std::swap(nums[i], nums[u]);
        }
    }
};
class Solution{
    public:
    vector<vector<int> > permute(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        ans.push_back(nums);
        while (next_permutation(nums.begin(), nums.end()))
        {
            ans.push_back(nums);
        }
        return ans;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    vector<int> nums({1,2,3});
    vector<vector<int> > ans = sol.permute(nums);
    for(int i = 0; i<ans.size(); ++i){
        for(int j=0; j<ans[i].size(); ++j){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


