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
#include<bitset>
using namespace std;
class Solution {
    private:
        int acgt2num(char c){
            switch(c){
                case 'A':
                    return 0;
                case 'C':
                    return 1;
                case 'G':
                    return 2;
                case 'T':
                    return 3;
            }
            return 0;
        }
    public:
        vector<string> findRepeatedDnaSequences(string s) {
            uint32_t n = s.size();
            vector<string> ans;
            if(n<=10)return  ans;
            uint32_t v = 0;
            for(int i=9;i>=0;--i){
                v = (v<<2)+acgt2num(s[i]);
            }
            char mv[1048576];
            memset(mv,0,sizeof(mv));
            ++mv[v];
            for(uint32_t i=10;i<n;++i){
                v >>= 2;
                v += (acgt2num(s[i]) << 18);
                ++mv[v];
                if(mv[v]==2){
                    ans.push_back(s.substr(i-9,10));
                }
            }
            return ans;
        }
};

int main()
{
    Solution sol;
    //vector<string> ans = sol.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    vector<string> ans = sol.findRepeatedDnaSequences("AAAAAAAAAAAAAAA");
    for(int i=0;i<ans.size();++i){
        cout<<ans[i]<<endl;
    }
    return 0;
}


