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
class Solution { // {a,......} = {a} + {....}
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(),S.end());
        int n = S.size();
        vector<vector<int> > ans({{}});
        int ans_size = 0;
        for(int i=0;i<n;++i){
            ans_size = ans.size();
            for(int j=0;j<ans_size;++j){
                vector<int> path = ans[j];
                path.push_back(S[i]);
                ans.push_back(path);
            }
        }
        return ans;
    }
};
class Solution_bit {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(),S.end());
        int n = S.size();
        vector<vector<int> > ans;
        int m = (1<<(n));
        int x;
        for(int i=0;i<m;++i){
            x = i;
            vector<int> path;
            for(int j=0;j<n;++j){
                if(x&1)path.push_back(S[j]);
                x >>=1;
            }
            ans.push_back(path);
        }
        return ans;
    }
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
    vector<int> S({1,2,3});
    vector<vector<int> >ans  = sol.subsets(S);
    for(int i=0;i<ans.size();++i){
        for(int j=0;j<ans[i].size();++j) cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
