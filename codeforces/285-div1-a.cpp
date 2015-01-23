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

void solve(){
    int n,d,x;
    cin>>n;
    pair<int,int> ps[n];
    unsigned int vs[n];
    unsigned int next[n];
    vector<pair<int,int> > edges;
    edges.reserve(1<<16);
    int cnt = 0;
    for(int i=0;i<n;++i){
        cin>>ps[i].first>>ps[i].second;
        if(ps[i].first==1){
            vs[cnt++] = i;
        }
    }
    int v;
    int len = cnt;
    while(len){
        cnt = 0;
        int cntt = 0;
        for(int i=0;i<len;++i){
            if(ps[vs[i]].first != 1)continue;
            v = ps[vs[i]].second;
            ps[v].second^=vs[i];
            --ps[v].first;
            if(ps[v].first == 1)next[cntt++] = v;
            edges.push_back({vs[i],v});
        }
        for(int i=0;i<cntt;++i){
            if(ps[next[i]].first == 1)
                vs[cnt++] = next[i];
        }
       len = cnt;
    }
    cout<<edges.size()<<endl;
    for(auto e : edges){
        cout<<e.first<<" "<<e.second<<endl;
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}


