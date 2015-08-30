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
    vector<int> path;
    int sum;
    int _target;
    int _K;
    vector<vector<int> > ans;
    int ss[4];
    unordered_map<int,int> M;
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        _K = 4;
        if(nums.size()<4) return ans;

        sort(nums.begin(), nums.end());

        memset(ss,0,sizeof(ss));
        ss[1] = nums[nums.size()-1];
        ss[2] = nums[nums.size()-2] + ss[1];
        ss[3] = nums[nums.size()-3] + ss[2];
        sum = 0;
        
        for(int i=0; i<nums.size(); ++i){
            M[nums[i]] = i;
        }
        path.resize(_K);
        _target = target;
        dfs(0,0, nums);
        return ans;
    }
    void dfs(int cnt, int u, const vector<int>& nums){
        if(cnt == _K-1)
        {
            //cout<<sum<<endl;
            auto it = M.find(_target - sum);
            if(it != M.end() && it->second >= u)
            {
/*                for(auto x : path) cout<<x<<" ";*/
                /*cout<<endl;*/
                path[cnt] = _target-sum;
                ans.push_back(path);
            }
            return;
        }
        int rest = _K-cnt-1;
        for(int i=u; i<nums.size()-rest; ++i)
        {
            path[cnt] = nums[i];
            sum += nums[i];
            if(sum + ss[rest] >= _target && sum + rest*nums[i] <= _target)
                dfs(cnt+1, i+1, nums);
            sum-=nums[i];
            while(i+1<nums.size() && nums[i] == nums[i+1]) ++i;
        }
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    //vector<int> num({1,0,-1,0,-2,2});int t = 0;
    //vector<int> num({1,1,1,1,1,1,1,1});int t =4;
    //vector<int> num({2,1,0,-1}); int t =2;
    Solution sol;
    vector< vector<int> > ans =  sol.fourSum(num,t);
    for(int i=0;i<ans.size();++i){
        for(int j=0;j<ans[i].size();++j)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}


