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

class Solution_recursive {
public:
    vector<vector<int> > ans;
    vector<int> path;
    int _target;
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
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
        for(;u<candidates.size();++u){
            if(sum+candidates[u]<=_target){
                path.push_back(candidates[u]);
                dfs(u+1,sum+candidates[u],candidates);
                path.pop_back();
                while(u+1<candidates.size() &&candidates[u+1] == candidates[u])++u;
            }
            else break;
        }
    }
};
int main()
{
    vector<int> candidates({10,1,2,7,6,1,5});
    Solution sol;
    vector<vector<int> > ans = sol.combinationSum2(candidates,8);
    for(int i=0;i<ans.size();++i){
        for(int j=0;j<ans[i].size();++j)cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}


