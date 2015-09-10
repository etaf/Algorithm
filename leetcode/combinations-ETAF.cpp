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
    vector<vector<int> > ans;
    int _n, _k;
    vector<vector<int> > combine(int n, int k) {
        _n = n;
        _k = k;
        path.resize(k);
        dfs(0,0);
        return ans;
    }
    void dfs(int u, int cnt){
        if(cnt == _k){
            ans.push_back(path);
            return;
        }
        for(int i=u; i<_n-_k+cnt+1; ++i){
            path[cnt] = i+1;
            dfs(i+1, cnt+1);
        }
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    vector<vector<int> > ans=sol.combine(4,2);
    for(int i=0;i<ans.size();++i){
        for(int j=0;j<ans[i].size();++j){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}


