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
    int ans;
    vector<int> qs;
    int _n;
    int totalNQueens(int n) {
        _n = n;
        ans = 0;
        qs.resize(n);
        for(int i=0;i<n;++i){
            qs[i] = -1;
        }
        dfs(0);
        return ans;
    }
    bool vaild_p(int x,int y){
        for(int i=0;i<x;++i){
            if(qs[i] == y || x-i == abs(y-qs[i]) )return false;
        }
/*        for(int i=x-1,j=y-1;i>=0 && j>=0;--i,--j){*/
            //if(qs[i] == j)return false;
        //}
        //for(int i=x-1,j=y+1;i>=0 && j<_n;--i,++j){
            //if(qs[i] == j) return false;
        /*}*/
        return true;
    }
    void dfs(int u){
        if(u == _n){
            ++ans;
            return;
        }
        for(int i=0;i<_n;++i){
            if(vaild_p(u,i))
            {
                qs[u] = i;
                dfs(u+1);
                qs[u] = -1;
            }
        }
    }
};
int main()
{
    Solution sol;
    cout<<sol.totalNQueens(8)<<endl;
    return 0;
}


