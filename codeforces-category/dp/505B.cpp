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

typedef struct Edge{
    int v,c,next;
    int vs[128];
}Edge;

Edge edges[256];
int head[128];
int ecnt;

void addEdge(int u,int v, int c){
    edges[ecnt].v = v; edges[ecnt].c = c; edges[ecnt].next = head[u]; head[u] = ecnt;
    ++ecnt;
    edges[ecnt].v = u; edges[ecnt].c = c; edges[ecnt].next = head[v]; head[v] = ecnt;
    ++ecnt;
}

int n,m;

void solve(){
    memset(head,-1,sizeof(head));
    ecnt=0;
    cin>>n>>m;
    int u,v,c;
    for(int i=0;i<m;++i){
        cin>>u>>v>>c;
        addEdge(u,v,c);
    }
    int q;
    cin>> q;
    while(q--){
        cin>>u>>v;

    }

}
int main()
{
ios::sync_with_stdio(false);
    solve();
    return 0;
}


