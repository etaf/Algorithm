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
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> M;
        int nw = words.size();
        int wl = words[0].size();
        int nwl = nw * wl;
        for(int i=0; i<nw; ++i){
            ++M[words[i]];
        }
        vector<int> ans;
        int cnt;
        for(int i=0; i<s.size()+1-nwl; ++i){
            unordered_map<string, int> tM(M);
            cnt = 0;
            for(int j = i; cnt< nw; ++cnt, j+=wl){
                auto it = tM.find(s.substr(j,wl));
                if(it == tM.end() || it->second == 0)
                    break;
                --it->second;
            }
            if(cnt == nw) ans.push_back(i);
        }
        return ans;

    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    string s("barfoothefoobarman");
    vector<string> words({"foo", "bar"});
    vector<int> ans = sol.findSubstring(s,words);
    for(auto& x : ans) cout<<x<<" ";
    cout<<endl;
    return 0;
}


