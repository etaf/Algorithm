#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int n = 20001;
const int m = 11;
int g[n][m];
int tt[m][n];
int cnt[m];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            scanf("%d",&g[i][j]);
        }
    }

    int u,v;
    while(k--)
    {
        scanf("%d%d",&u,&v);
        --v;--u;
        cnt[v]++;
        tt[v][u]++;
    }
    for(int i=0;i<n;++i)
    {
        int ans= 0;
        for(int j=0;j<m;++j)
        {
            if(g[i][j])
            ans += cnt[j]-tt[j][i];
        }
        if(i)
            printf(" ");
        printf("%d",ans);
    }
    printf("\n");
    return 0;
}
