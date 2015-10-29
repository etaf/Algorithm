
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
    void addEdge(int u,int v){
        es[ecnt].u = u;
        es[ecnt].v = v;
        es[ecnt].next = head[u];
        head[u] = ecnt++;
    }
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        memset(head,-1,sizeof(head));
        memset(vis,0,sizeof(vis));
        memset(checked, 0, sizeof(checked));
        for(uint32_t i=0; i<prerequisites.size(); ++i){
            addEdge(prerequisites[i].first, prerequisites[i].second);
        }
        for(int i=0; i<numCourses; ++i){
            if(checked[i])continue;
            if(dfs(i)) return false;
        }
        return true;
    }
    bool dfs(int u){
        //cout<<u<<" "<<vis[u]<<endl;
        if(vis[u]) return true;
        vis[u] = true;
        for(int p=head[u]; p!=-1; p=es[p].next){
            if(!checked[es[p].v] && dfs(es[p].v))return true;
        }
        vis[u] = false;
        checked[u] = true;
        return false;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    vector<pair<int,int> > ps({{5,8},{3,5},{1,9},{4,5},{0,2},{1,9},{7,8},{4,9}});
    vector<pair<int,int > > ps2 = {{0,1},{3,1},{1,3},{3,2}};
    vector<pair<int,int > > ps3 = {{0,1},{1,0}};
    vector<pair<int,int > > ps4 = {{1,0},{2,6},{1,7},{5,1},{6,4},{7,0},{0,5},{5,1},{6,4}};

    cout<<sol.canFinish(10,ps)<<endl;
    cout<<sol.canFinish(4,ps2)<<endl;
    cout<<sol.canFinish(2,ps3)<<endl;
    cout<<sol.canFinish(8,ps4)<<endl;

    return 0;
}


