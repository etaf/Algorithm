#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
    private:
        vector<string> ans;
        string path;
        int _n;
public:
    vector<string> generateParenthesis(int n) {
        _n = n+n;
        path.resize(_n,'*');
        dfs(0,0);
        return ans;
    }
    void dfs(int now,int l)
    {
        if(now == _n){
            if(l==0)
                ans.push_back(path);
            return;
        }
        if(l==0){
            path[now] = '(';
            dfs(now+1,1);
        }
        else{
            path[now] = ')';
            dfs(now+1,l-1);
            if(_n-now-1 >= l+1){
                path[now] = '(';
                dfs(now+1,l+1);
            }
        }
    }
};
int main(){

    Solution sol;
    vector<string> ans = sol.generateParenthesis(4);
    for(int i=0;i<ans.size();++i)cout<<ans[i]<<endl;
    return 0;
}
