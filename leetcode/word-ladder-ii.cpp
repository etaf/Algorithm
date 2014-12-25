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

class Solution {//accepted ,used  1s
    public:
        unordered_map<string,vector<string> > path;
        vector<vector<string> > ans;
        vector<string> nv;
        unsigned int len;
        vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
            queue<string > Q;
            unordered_map<string,unsigned int> dist;
            Q.push(start);
            dist[start] = 1;
            string now,next;
            len = 0;
            while(!Q.empty())
            {
                now = Q.front();
                Q.pop();
                if(len && dist[now] >= len)continue;
                next = now;
                char c;
                for(int i=now.size()-1;i>=0;--i){
                    c = now[i];
                    for(int j=0;j<26;++j){
                        next[i] = 'a'+j;
                        if(next[i] == c)continue;
                        if(next == end){
                            if( 0 == len){
                                len = dist[now]+1;
                                path[next].push_back(now);
                            }
                            else if(dist[now] + 1 == len){
                                path[next].push_back(now);
                            }
                            break;
                        }
                        if( dict.find(next)!= dict.end()){
                            unordered_map<string,unsigned int>::iterator it = dist.find(next);
                            if(it == dist.end())
                            {
                                dist[next] = dist[now]+1;
                                Q.push(next);
                                path[next].push_back(now);
                            }else if( it->second == dist[now]+1 )
                            {
                                path[next].push_back(now);
                            }
                        }
                    }
                    next[i]=c;
                }
            }
            if(len == 0)return ans;
            nv.resize(len);
            nv[len-1] = end;
            dfs(end,1);
            return ans;
        }
        void dfs(string now,unsigned int step){
            if(step == len){
                ans.push_back(nv);
            }
            vector<string>nexts = path[now];
            for(int i=nexts.size()-1;i>=0;--i){
                nv[len-step-1] = nexts[i];
                dfs(nexts[i],step+1);
            }
        }
};


int main()
{
    Solution sol;
    unordered_set<string> dict,dict2;
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("log");
    dict.insert("lot");
    dict2.insert("a");
    dict2.insert("b");
    dict2.insert("c");
    //vector<vector<string> > ans = sol.findLadders("hit","cog",dict);
    vector<vector<string> > ans = sol.findLadders("hot","cog",dict);
    //vector<vector<string> > ans = sol.findLadders("a","c",dict2);
    for(int i=0;i<ans.size();++i){
        for(int j=0;j<ans[i].size();++j){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


