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
#include<sstream>
typedef long long llong;
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<int,string> mp;
        unordered_map<string,int> bp;
        vector<string> tokens;
        stringstream sin(str);
        string word;
        for(int i=0; i<pattern.size(); ++i){
            if(!(sin>>word)) return false;
            auto it = mp.find(pattern[i]);
            if(it == mp.end()) {
                if(bp.find(word) != bp.end()){
                    return false;
                }
                mp.insert(make_pair(pattern[i],word));
                bp.insert(make_pair(word,pattern[i]));
            }
            else{
                if(it->second != word) return false;
            }
        }
        if(sin>>word) return false;
        return true;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    cout<<sol.wordPattern("abba", "dog cat cat dog")<<endl;
    cout<<sol.wordPattern("abba", "dog cat cat fish")<<endl;
    cout<<sol.wordPattern("aaaa", "dog cat cat dog")<<endl;
    cout<<sol.wordPattern("abba", "dog dog dog dog")<<endl;

    return 0;
}


