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
    bool isAnagram(string s, string t) {
        if(t.size()!=s.size()) return false;
        int ks[26];
        memset(ks, 0, sizeof(ks));
        for(int i=0; i<s.size(); ++i){
            ++ks[s[i]-'a'];
            --ks[t[i]-'a'];
        }
        for(int i=0; i<26; ++i){
            if(ks[i] != 0 ) return false;
        }
        return true;
    }
};
int main()
{
    return 0;
}


