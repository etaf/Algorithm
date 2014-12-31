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

class Solution { // O(n)
public:
    bool isMatch(const char *s, const char *p) {
        int l,r,sr;
        int n = strlen(p);
        int m = strlen(s);
        int i,j;
        if(m == 0){
            for(i=0;i<n;++i)
                if(p[i]!='*')return false;
            return true;
        }
        for( i=0;i<n && i<m && p[i]!='*';++i){
            if(p[i] != '?' && p[i] != s[i])
                return false;
        }
        l = i;
        if(i == n)return i==m;
        if(i == m){
            while(i<n){
                if(p[i]!='*')return false;
                ++i;
            }
            return true;
        }
        for(i=n-1,j=m-1; p[i]!='*' && j>=l;--i,--j){
            if(p[i]!='?' && p[i] != s[j]) return false;
        }
        r = i;
        //cout<<l<<"-"<<j<<endl;
        if(l>j){
            for(;i>l;--i)if(p[i]!='*')return false;
        }
        const char* psl = s+l;
        const char* psr = s+j+1;

        char *pp = new char[n];
        int cntp = 0;
        if(l==r)return true;
        for(i=l+1;i<r;++i){
            cntp=0;
            for(;i<r && p[i]!='*';++i){
                pp[cntp++] = p[i];
            }
            pp[cntp] = 0;
            psl = strStr(psl,psr,pp);
            if(psl == NULL)return false;
            //psl += 1;
        }
        return true;
    }
private:
    const char* strStr(const char *sl,const char* sr,const  char *needle) { //KMP
        /*for(const char* t = sl;t!=sr;++t)cout<<*t;*/
        //cout<<endl;
        /*printf("%s\n----------------\n",needle);*/
        int m = strlen(needle);
        int *next = new int[m];
        get_next(needle,next,m);
        int i=0,j=0;
        const char* si = sl;
        while(si != sr && j<m){
            if(j==-1 || *si == needle[j] || needle[j] == '?') ++si, ++j;
            else j = next[j];
            //cout<<j<<endl;
        }
        /*while(i<n && j<m)*/
        //{
            //if( j == -1 || haystack[i] == needle[j] || needle[j] == '?')++i,++j;
            //else j = next[j];
        /*}*/
        delete next;
        if( j == m) return si;
        else return NULL;
    }
    void get_next(const char* pattern, int* next, int m){
        int i=0,j=-1;
        if(pattern[0] == '?') next[0] = 0;
        else next[0] = -1;

        while(i<m-1){
            if(j == -1 || pattern[i] == pattern[j] || pattern[j] == '?' || pattern[i] == '?') {
                ++j,++i;
                if(pattern[i] != pattern[j] && pattern[i]!='?' && pattern[j]!='?') next[i] = j;
                else next[i] = next[j];
            }
            else j = next[j];
        }

    }
};
class Solution_dp { /// O(m*n) TLE
public:
    bool isMatch(const char *s, const char *p) {
       int n = strlen(p);
       int m = strlen(s);
       bool dp[2][100100];
       memset(dp,0,sizeof(dp));
       dp[0][0]= 1;
       int first_true[2];
       first_true[0] = 0;
       int c = 1;

  /*      for(int j=0;j<=m;++j)cout<<dp[0][j]<<" ";*/
           /*cout<<endl;*/

       for(int i=1;i<=n;++i,c^=1){
           first_true[c] = INT_MAX;
           if(p[i-1] == '*'){
               dp[c][0]  = dp[c^1][0];
               first_true[c] = 0;
           }
           else dp[c][0] = 0;
           for(int j=1;j<=m;++j){
               if(p[i-1] == s[j-1] || p[i-1] == '?'){
                   dp[c][j] = dp[c^1][j-1];
               }else if(p[i-1] == '*' && first_true[c^1] <= j){
                   dp[c][j] = 1;
               }else dp[c][j] = 0;
               if(dp[c][j] && first_true[c] == INT_MAX) first_true[c] = j;
           }
/*           for(int j=0;j<=m;++j)cout<<dp[c][j]<<" ";*/
           /*cout<<endl;*/
       }
       return dp[c^1][m];
    }
};
int main()
{
    Solution sol;
    //cout<<sol.isMatch("a*cbcdesaf","a*b*cde*f")<<endl;
    //cout<<sol.isMatch("a","*?*")<<endl;
    //cout<<sol.isMatch("","*")<<endl;
    //cout<<sol.isMatch("b","*?*?")<<endl;
    //cout<<sol.isMatch("abce","abc*??")<<endl;
    //cout<<sol.isMatch("ab","**ab")<<endl;
    cout<<sol.isMatch("bbabab","**?a*")<<endl;
    return 0;
}


