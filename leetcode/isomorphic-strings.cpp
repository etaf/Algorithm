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
    bool isIsomorphic(string s, string t) {
        char m[256];
        bool md[256];
        memset(m,0,sizeof(m));
        memset(md,0,sizeof(md));
        int len = s.size();
        for(int i=0;i<len;++i){
            if(m[s[i]]){
                if( m[s[i]] != t[i]){
                    return false;
                }
            }
            else{
                if(md[t[i]])
                    return false;
                m[s[i]] = t[i];
                md[t[i]] = true;
            }
        }
        return true;
    }
};
int main()
{
    Solution sol;
    cout<<sol.isIsomorphic("abc", "eeg")<<endl;
    return 0;
}


