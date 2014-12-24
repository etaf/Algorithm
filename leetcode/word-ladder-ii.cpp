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
class Solution { //dfs
public:
    vector<vector<string> > ans;
    int len;
    string _end;
    unordered_set<string> vis;
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        len = ladderLength(start,end,dict);
        if(len == 0)return ans;
        else{
            _end = end;
            vector<string> path(len);
            vis.insert(start);
            path[len-1] = end;
            dfs(start,dict,path,0);
            return ans;
        }
    }
    void dfs(string now,unordered_set<string> &dict, vector<string>& path,int step){
        if(step + 1 >= len)return;
        path[step] = now;
        char c;
        string next = now;
        for(int i=0;i<now.size();++i){
            c = now[i];
           for(int j=0;j<26;++j){
                next[i] = 'a'+j;
                if(next == _end){
                    ans.push_back(path);
                    return;
                }
                if(dict.find(next) != dict.end() && vis.find(next) == vis.end() )
                {
                    vis.insert(next);
                    dfs(next,dict,path,step+1);
                    vis.erase(vis.find(next));
                }
           }
           next[i] = c;
        }
    }
    int ladderLength(string start, string end, unordered_set<string> &dict) { //double bfs
        int ans = 0;
        queue<string> Q1;
        queue<string> Q2;
        unordered_map<string,int> dist1 ;
        unordered_map<string,int> dist2 ;
        Q1.push(start);
        Q2.push(end);
        dist1[start] = 1;
        dist2[end] = 0;
        string now,next;
        while(!Q1.empty() && !Q2.empty()){
            now = Q1.front();
            Q1.pop();
            next = now;
            char c;
            for(size_t i=0;i<now.size();++i){
                c = now[i];
                for(int j=0;j<26;++j){
                    next[i] = 'a'+j;
                    if(dist2.find(next)!=dist2.end()) return dist1[now]+ 1 + dist2[next];
                    if(dict.find(next) != dict.end() && dist1.find(next) == dist1.end()){
                        dist1[next] = dist1[now]+1;
                        Q1.push(next);
                    }
                }
                next[i] = c;
            }

            now = Q2.front();
            Q2.pop();
            next = now;
            for(size_t i = 0;i<now.size();++i){
                c = now[i];
                for(int j=0;j<26;++j){
                    next[i] = 'a'+j;
                    if(dist1.find(next)!=dist1.end()) return dist2[now] + 1 + dist1[next];
                    if(dict.find(next) != dict.end() && dist2.find(next) == dist2.end()){
                        dist2[next] = dist2[now]+1;
                        Q2.push(next);
                    }
                }
                next[i] = c;
            }
        }
        return ans;
    }

};

class Solution_bfs {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > ans;
        queue< vector<string> > Q;
        vector<string> nv;
        nv.push_back(start);
        unordered_map<string,int> dist;
        Q.push(nv);
        dist[start] = 0;
        string now,next;
        int step = 0;
        while(!Q.empty())
        {
            nv = Q.front();
            Q.pop();
            now = nv.back();
            if(step && nv.size()>=step)continue;
            next = now;
            char c;
            for(int i=0;i<now.size();++i){
                c = now[i];
                for(int j=0;j<26;++j){
                    next[i] = 'a'+j;
                    unordered_map<string,int>::iterator it = dist.find(next);
                    if(next == end){
                        nv.push_back(end);
                        step = nv.size();
                        ans.push_back(nv);
                        nv.pop_back();
                        continue;
                    }
                    if( dict.find(next)!= dict.end() && (it == dist.end() || it->second == dist[now]+1 ))
                    {
                        dist[next] = dist[now]+1;
                        nv.push_back(next);
                        Q.push(nv);
                        nv.pop_back();
                    }
                }
                next[i]=c;
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
    vector<vector<string> > ans = sol.findLadders("hit","cog",dict);
    for(int i=0;i<ans.size();++i){
        for(int j=0;j<ans[i].size();++j){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
	return 0;
}


