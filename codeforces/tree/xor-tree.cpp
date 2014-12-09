#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N = 100001;
int f[N],d[N];
vector<int> g[N];
int ans[N],acnt;
void dfs(int u,int fa,int ffa)
{
    f[u] ^= d[ffa];
    d[u] = d[ffa] ^ f[u];
    if(f[u])ans[acnt++] = u+1;

    for(int i=0;i<g[u].size();++i){
        if(g[u][i]!=fa)
            dfs(g[u][i],u,fa);
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    int n;
    scanf("%d",&n);
    int u,v;
    for(int i=0;i<n-1;++i)
    {
        scanf("%d%d",&u,&v);
        --u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=0;i<n;++i)
    {
        scanf("%d",&f[i]);
    }
    int x;
    for(int i=0;i<n;++i)
    {
        scanf("%d",&x);
        f[i] ^= x;
    }
    dfs(0,-1,-1);
    printf("%d\n",acnt);
    for(int i=0;i<acnt;++i)printf("%d\n",ans[i]);
    return 0;
}
