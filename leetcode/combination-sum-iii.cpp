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
    vector<vector<int> > combinationSum3(int k, int n) {
        path.resize(k);
        for(int i=1;i<=9;++i)
        {
            path[0] = i;
            dfs(1,i,k,n);
        }
        return ans;
    }
    void dfs(int len, int sum, int k, int n ){
        if(len == k ){
            if(sum == n)
                ans.push_back(path);
            return;
        }
        if(( ((path[len-1]+1 + 9)*(9-path[len-1])) >> 1) < n-sum)
            return;
        for(int i= path[len-1] + 1; i<=9; ++i)
        {
            path[len] = i;
            dfs(len+1, sum + i, k, n);
        }

    }
};
int main()
{
    Solution sol;
    vector<vector<int> > ans = sol.combinationSum3(3,9);
    for(int i=0; i<ans.size(); ++i ){
        for(int j=0;j<ans[i].size(); ++j){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}


