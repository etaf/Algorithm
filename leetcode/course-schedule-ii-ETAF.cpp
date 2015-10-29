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

typedef long long llong;


class Solution {
public:
    typedef struct Edge{
        int u,v,next;
    }Edge;
    int ecnt;
    Edge es[10240];
    int head[10240];
    bool vis[10240];
    bool checked[10240];
    bool f[10240];
    vector<int> ans;
    void addEdge(int u,int v){
        es[ecnt].u = u;
        es[ecnt].v = v;
        es[ecnt].next = head[u];
        head[u] = ecnt++;
    }

    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        memset(head,-1,sizeof(head));
        memset(vis,0,sizeof(vis));
        memset(checked, 0, sizeof(checked));
        memset(f,0,sizeof(f));
        for(uint32_t i=0; i<prerequisites.size(); ++i){
            addEdge(prerequisites[i].first, prerequisites[i].second);
            f[prerequisites[i].second] = true;
        }
        ans.clear();
        for(int i=0; i<numCourses; ++i){
            if(f[i]) continue;
            if(dfs(i)) return {};
        }
        for(int i=0; i<numCourses; ++i) {
            if(!checked[i]) return {};
        }
        //cout<<"can finish"<<endl;
        //std::reverse(ans.begin(),ans.end());
        return ans;
    }
    bool dfs(int u){
        if(vis[u]) return true;
        vis[u] = true;
        for(int p=head[u]; p!=-1; p=es[p].next){
            if(dfs(es[p].v)) return true;
        }
        vis[u] = false;
        if(!checked[u])
        {
            ans.push_back(u);
            checked[u] = true;
        }
        return false;
    }

};
int main()
{
    std::ios::sync_with_stdio(false);
    std::ios::sync_with_stdio(false);
    Solution sol;
    vector<pair<int,int> > ps({{5,8},{3,5},{1,9},{4,5},{0,2},{1,9},{7,8},{4,9}});
    vector<pair<int,int > > ps2 = {{0,1},{3,1},{1,3},{3,2}};
    vector<pair<int,int > > ps3 = {{0,1},{1,0}};
    vector<pair<int,int > > ps4 = {{1,0},{2,6},{1,7},{5,1},{6,4},{7,0},{0,5},{5,1},{6,4}};

    vector<int> ans;
    ans = sol.findOrder(10,ps);
    for(auto x : ans) cout<<x<<" ";
    cout<<endl;
    ans = sol.findOrder(4,ps2);
    for(auto x : ans) cout<<x<<" ";
    cout<<endl;
    ans = sol.findOrder(2,ps3);
    for(auto x : ans) cout<<x<<" ";
    cout<<endl;

    ans = sol.findOrder(8,ps4);
    for(auto x : ans) cout<<x<<" ";
    cout<<endl;



    return 0;
}


