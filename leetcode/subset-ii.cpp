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
    private:
        vector<vector<int> > ans;
        vector<int> path;
        int n;
public:

    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(),S.end());
        n = S.size();
        path.reserve(n);
        dfs(0,S);
        return ans;
    }
    void dfs(int u,const vector<int>& S){
        if(u==n){
            ans.push_back(path);
            return;
        }
        int v;
        for(v=u+1;v<n && S[u] == S[v];++v);
        dfs(v,S);
        for(int i=u;i<v;++i){
            path.push_back(S[u]);
            dfs(v,S);
        }
        for(int i=u;i<v;++i){
            path.pop_back();
        }
    }
};
int main()
{
    Solution sol;
    vector<int> S({1,2,2});
    vector<vector<int> >ans  = sol.subsetsWithDup(S);
    for(int i=0;i<ans.size();++i){
        for(int j=0;j<ans[i].size();++j) cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}


