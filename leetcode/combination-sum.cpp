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
    vector<vector<int> > ans;
    vector<int> path;
    int _target;
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
       sort(candidates.begin(),candidates.end()) ;
       _target = target;
       dfs(0,0,candidates);
       return ans;
    }
    void dfs(int u,int sum,vector<int> &candidates)
    {
        if(sum == _target){
            ans.push_back(path);
            return;
        }
        if(u == candidates.size() || _target-sum < candidates[u])return;
        for(int i=0;i*candidates[u] <= _target;++i){
            dfs(u+1,sum+i*candidates[u],candidates);
            path.push_back(candidates[u]);
        }
        for(int i=0;i*candidates[u] <= _target;++i)path.pop_back();
    }
};
int main()
{
    vector<int> candidates({2,3,6,7});
    Solution sol;
    vector<vector<int> > ans = sol.combinationSum(candidates,7);
    for(int i=0;i<ans.size();++i){
        for(int j=0;j<ans[i].size();++j)cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}


