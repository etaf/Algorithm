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
    string longestCommonPrefix(vector<string> &strs) {
        size_t maxlen = 0;
        for(int i=strs.size()-1;i>=0;--i)
            maxlen = max(strs[i].size(),maxlen);
        string prefix;
        for(int j=0,i;j<maxlen;++j){
            for(i=strs.size()-1;i>0 && strs[i][j] == strs[i-1][j];--i);
            if(i)return prefix;
            prefix.push_back(strs[0][j]);
        }
        return prefix;
    }
};
int main()
{
    Solution sol;
    vector<string> strs({"a'","aba","ab","aac","abaacc","aac","abb","aaca","abaaccd"});
    //vector<string> strs({"a","a","b"});
    cout<<sol.longestCommonPrefix(strs)<<endl;
    return 0;
}


