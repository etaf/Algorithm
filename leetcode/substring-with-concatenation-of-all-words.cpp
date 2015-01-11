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
    vector<int> findSubstring(string S, vector<string> &L) {
        unordered_map<string,int> ms;
        vector<int> ans;
        int n = S.size();
        int m = L.size();
        int k = L[0].size();
        for(int i=0;i<m;++i){
            ++ms[L[i]];
        }
        int endi = n-m*k+1;
        string now;
        for(int i=0,j;i<endi;++i){
            unordered_map<string,int> nows;
            for(j=i;j<i+m*k;j+=k)
            {
                now = S.substr(j,k);
                if(ms[now] && ms[now] > nows[now]){
                    ++nows[now];
                }else{
                    break;
                }
            }
            if(j == i+m*k) ans.push_back(i);
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    string S("barfoothefoobarman");
    vector<string> L({"foo","bar"});
    vector<int > ans = sol.findSubstring(S,L);
    for(int i=0;i<ans.size();++i){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}


