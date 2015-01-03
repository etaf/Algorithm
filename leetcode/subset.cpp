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
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(),S.end());
        int n = S.size();
        vector<int> path(n,0);
        vector<vector<int> > ans;
        int i=0;
        while
};

class Solution_recursive {
    private:
        vector<vector<int> > ans;
        vector<int> path;
        int n;
public:

    vector<vector<int> > subsets(vector<int> &S) {
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
        dfs(u+1,S);
        path.push_back(S[u]);
        dfs(u+1,S);
        path.pop_back();
    }
};
int main()
{
    Solution sol;
    sol.subsets
    vector<int> S({1,2,3});
    vector<vector<int> >ans  = sol.subsets(S);
    sol.subsetsfdsa<Plug>delimitMateBS<Plug>delimitMateBS<Plug>delimitMateBS<Plug>delimitMateBS<Plug>delimitMateBS<Plug>delimitMateBS
    for(int i=0;i<ans.size();++i){
        for(int j=0;j<ans[i].size();++j) cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}


