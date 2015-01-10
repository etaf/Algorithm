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
    vector<vector<string> > ans;
    vector<string> ps;
    int _n;
    vector<vector<string> > solveNQueens(int n) {
        _n = n;
        for(int i=0;i<n;++i){
            ps.push_back(string(n,'.'));
        }
        dfs(0);
        return ans;
    }
    bool vaild_p(int x,int y){
        for(int i=0;i<x;++i){
            if(ps[i][y] !='.')return false;
        }
        for(int i=x-1,j=y-1;i>=0 && j>=0;--i,--j){
            if(ps[i][j] !='.')return false;
        }
        for(int i=x-1,j=y+1;i>=0 && j<_n;--i,++j){
            if(ps[i][j] != '.') return false;
        }
        return true;
    }
    void dfs(int u){
        if(u == _n){
            ans.push_back(ps);
            return;
        }
        for(int i=0;i<_n;++i){
            if(vaild_p(u,i))
            {
                ps[u][i] = 'Q';
                dfs(u+1);
                ps[u][i] = '.';
            }
        }
    }
};
int main()
{
    Solution sol;
    vector<vector<string> > ans = sol.solveNQueens(4);
    for(size_t i=0;i<ans.size();++i){
        for(size_t j=0;j<ans[i].size();++j){
            cout<<ans[i][j]<<endl;
        }
        cout<<endl<<endl;
    }
    return 0;
}


