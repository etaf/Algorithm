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
    string longestPalindrome(string s) {
        int n = s.size();
        int maxlen = 1,maxl=0;
        int l,r;
        for(int i=1;i<n;++i){
            l=r=i;
            while(l-1>=0 && r+1 <n && s[l-1] == s[r+1]){
                --l;++r;
            }
            if(r-l+1>maxlen){
                maxlen = r-l+1;
                maxl = l;
            }
        }
        for(int i=0;i<n-1;++i){
            l=i,r=i+1;
            if(s[l]!=s[r]) continue;
            while(l-1>=0 && r+1<n && s[l-1] == s[r+1] ){
                --l;++r;
            }
            if(r-l+1>maxlen){
                maxlen = r-l+1;
                maxl = l;
            }
        }
        return s.substr(maxl,maxlen);
    }
};
int main()
{
    Solution sol;
    cout<<sol.longestPalindrome("abb")<<endl;
    return 0;
}


