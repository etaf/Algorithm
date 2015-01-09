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
    string minWindow(string S, string T) {
        int f[256];
        int e[256];
        memset(e,0,sizeof(e));
        memset(f,0,sizeof(f));
        int m = S.size();
        int nt = T.size();
        for(size_t i=0;i<T.size();++i){
            ++f[T[i]];
        }
        int l=0,r;
        while(l<m && !f[S[l]])++l;
        if(l==m)return "";
        int c;
        for(r=l;r<m;++r){
            c = S[r];
            if(f[c]){
                if(e[c] < f[c])
                    --nt;
                ++e[c];
                if(nt==0)break;
            }
        }
        if(r==m)return "";
        while(!f[S[l]] || e[S[l]]>f[S[l]]){
            --e[S[l]];
            ++l;
        }

        int ans = r-l+1;
        int ans_l = l;
        while(++r<m){
            ++e[S[r]];
            if(S[r] == S[l]){
                --e[S[l]];
                ++l;
                while(!f[S[l]] || e[S[l]]>f[S[l]]){
                    --e[S[l]];
                    ++l;
                }
                if(ans > r-l+1){
                    ans = r-l+1;
                    ans_l = l;
                }
            }
        }
        return S.substr(ans_l,ans);
    }
};
int main()
{
    string s("bba");
    string t("ab");

    /*string s("ADOBECODEBANC");*/
    /*string t("COE");*/
    Solution sol;
    cout<<sol.minWindow(s,t)<<endl;

    return 0;
}


