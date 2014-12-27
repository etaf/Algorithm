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
        int ps[4];
        int cntp;
        vector<string> ans;
        vector<string> restoreIpAddresses(string s) {
            cntp=0;
            dfs(0,0,s);
            return ans;
        }
        void dfs(int u,int p,string &s){
            if(p==4){
                if(u==s.size()){
                    string ns;
                    for(int i=0,j=0;i<4;++i){
                        for(;j<ps[i];++j) ns.push_back(s[j]);
                        if(i!=3) ns.push_back('.');
                    }
                    ans.push_back(ns);
                }
                return;
            }
            if( u+1 <= s.size()){
                ps[cntp++]= u+1;
                dfs(u+1,p+1,s);
                --cntp;
            }
            if(u+2<=s.size() && s[u]!='0') {
                ps[cntp++]= u+2;
                dfs(u+2,p+1,s);
                --cntp;
            }
            if(u+3<=s.size() && 100*(s[u]-'0') + 10*(s[u+1]-'0') + s[u+2]-'0' < 256  && s[u]!='0' ){
                ps[cntp++] = u + 3;
                dfs(u+3,p+1,s);
                --cntp;
            }
        }
};
int main()
{
    Solution sol;
    //vector<string> ans = sol.restoreIpAddresses("25525511135");
    vector<string> ans = sol.restoreIpAddresses("010010");
    for(int i=0;i<ans.size();++i){
        cout<<ans[i]<<endl;
    }
    return 0;
}


