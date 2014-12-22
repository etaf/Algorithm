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
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        int ans = 0;
        queue<pair<string,int> > Q;
        unordered_set<string> vis;
        Q.push(pair<string,int>(start,1));
        vis.insert(start);
        pair<string,int> now;
        string next;
        while(!Q.empty()){
            now = Q.front();
            Q.pop();
            next = now.first;
            char c;
            for(size_t i=0;i<now.first.size();++i){
                c = now.first[i];
                for(int j=0;j<26;++j){
                    next[i] = 'a'+j;
                    if(next == end) return now.second+1;
                    if(dict.find(next) != dict.end() && vis.find(next) == vis.end()){
                        vis.insert(next);
                        Q.push(pair<string,int>(next,now.second+1));
                    }
                }
                next[i] = c;
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    unordered_set<string> dict;
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("log");
    dict.insert("lot");
    cout<<sol.ladderLength("hit","cog",dict)<<endl;
	return 0;
}


