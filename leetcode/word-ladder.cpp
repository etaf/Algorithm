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
class Solution { //astar
public:
    int hf(const string& s1,const string &s2){
        int res = 0;
        for(size_t i=0;i<s1.size();++i)if(s1[i] == s2[i])++res;
        return res;
    }
    int ladderLength(string start, string end, unordered_set<string> &dict) { //bfs
        int ans = 0;
        priority_queue<pair<int,string> > Q;
        unordered_map<string,int> dist;
        Q.push(pair<int,string>(hf(start,end)+1,start));
        dist[start] = 1;
        string next;
        pair<int,string> now;
        while(!Q.empty()){
            now = Q.top();
            Q.pop();
            next = now.second;
            char c;
            for(size_t i=0;i<now.second.size();++i){
                c = now.second[i];
                for(int j=0;j<26;++j){
                    next[i] = 'a'+j;
                    int nn = dist[now.second];
                    if(next == end) return nn+1;
                    if(dict.find(next) != dict.end() && nn+1<dist[next]){
                        dist[next] = nn + 1;
                        Q.push(pair<int,string>(hf(next,end)+nn,next));
                    }
                }
                next[i] = c;
            }
        }
        return ans;
    }
};
class Solution_double_bfs {
public:
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
    int ladderLength(string start, string end, unordered_set<string> &dict) { //bfs
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
    priority_queue<pair<int,int> > Q;
    Q.push(pair<int,int>(1,1));
    Q.push(pair<int,int>(1,2));
    Q.push(pair<int,int>(2,2));
    while(!Q.empty()){
        cout<<Q.top().first<<" "<<Q.top().second<<endl;
        Q.pop();
    }
    Solution sol;
    unordered_set<string> dict;
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    /*dict.insert("log");*/
    /*dict.insert("lot");*/
    cout<<sol.ladderLength("hot","dog",dict)<<endl;
	return 0;
}


