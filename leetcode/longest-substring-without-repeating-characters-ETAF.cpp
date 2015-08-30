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
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        bool f[256];
        memset(f,0,sizeof(f));
        int l=0,r=0;
        for(; r<s.size(); ++r){
            if(f[s[r]]){
                ans = max(ans, r-l);
                while(s[l] != s[r]){
                    f[s[l]] = 0;
                    ++l;
                }
                ++l;
            }
            else{
                f[s[r]] = 1;
            }
        }
        return max(ans, r-l);
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    cout<<sol.lengthOfLongestSubstring("abcabcbb")<<endl;;
    cout<<sol.lengthOfLongestSubstring("aa")<<endl;;
    return 0;
}


