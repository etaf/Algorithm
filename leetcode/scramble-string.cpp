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
    int n,m;
    int dp[48][48][48];
    const char* _s1,*_s2;
    bool isScramble(string s1, string s2) {
        _s1 = s1.c_str();
        _s2 = s2.c_str();
        if(s1.size() != s2.size()) return false;
        memset(dp,-1,sizeof(dp));
        dfs(0,0,s2.size());
        return dp[0][0][s2.size()];
    }
    void dfs(int l1,int l2,int len){
        //if(_s1.substr(l1,len) == _s2.substr(l2,len))
        if(!memcmp(_s1+l1,_s2+l2,len))
        {
            dp[l1][l2][len] = 1;
            return;
        }
        //cout<<_s1.substr(l1,len)<<"-"<<_s2.substr(l2,len)<<endl;
        for(int i=1;i<len;++i){
            if(dp[l1][l2][i] == -1) dfs(l1,l2,i);
            if(dp[l1+i][l2+i][len-i] == -1) dfs(l1+i,l2+i,len-i);
            if(dp[l1+len-i][l2][i] == -1) dfs(l1+len-i,l2,i);
            if(dp[l1][l2+i][len-i] == -1) dfs(l1,l2+i,len-i);

            if((dp[l1+i][l2+i][len-i]==1 && dp[l1][l2][i] == 1) || (dp[l1+len-i][l2][i] == 1 && dp[l1][l2+i][len-i]) == 1 )
            {
                dp[l1][l2][len] = 1;
                return;
            }
        }
        dp[l1][l2][len] = 0;
    }

};
class Solution_TLE {
public:
    bool isScramble(string s1, string s2) {
        //cout<<s1<<"-"<<s2<<endl;
        if(s1.size()!=s2.size()) return false;
        if(s1 == s2) return true;
        if(s1.size() == 1 ) return s1[0] == s2[0];
        for(size_t i=1;i<s2.size();++i){
            if( (
                    isScramble(s1.substr(0,i),s2.substr(0,i)) &&
                    isScramble(s1.substr(i,s2.size()-i),s2.substr(i,s2.size()-i))
                ) || (
                    isScramble(s1.substr(0,i),s2.substr(s2.size()-i,i)) &&
                    isScramble(s1.substr(i,s2.size()-i),s2.substr(0,s2.size()-i))
                    )
              )
                return true;
        }
        return false;
    }
};
int main()
{
    Solution sol;
    cout<<sol.isScramble("great","rgtae")<<endl;
    cout<<sol.isScramble("abcdefghijklmnopq","efghijklmnopqcadb")<<endl;
    return 0;
}


