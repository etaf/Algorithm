#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N = 30001;
const int M = 100001;
vector<int> g[N];
int ans[N];
int ans_cnt;
bool vis[N];
void dfs(int u)
{
    vis[u] = 1;
    for(int i=0;i<g[u].size();++i)
    {
        if(!vis[g[u][i]])
        {
            vis[g[u][i]] = 1;
            dfs(g[u][i]);
        }
    }
    ans[ans_cnt++] = u;
}
int main()
{
    int n,m,u,v;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)
    {
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
    }
    for(int i=1;i<=n;++i)
    {
        if(!vis[i])
            dfs(i);
    }
    printf("%d",ans[0]);
    for(int i=1;i<n;++i)
        printf(" %d",ans[i]);
    printf("\n");
    return 0;
}
