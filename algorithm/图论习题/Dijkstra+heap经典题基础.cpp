/*
复杂度：nlog(n)
*/
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<functional>
using namespace std;
const int N=1001;
const int INIF=0x3fffffff;
int dist[N];
bool used[N];
int n,m;
struct node
{
    int v,len;
};
struct pnode
{
    int dist,id;
    pnode(){}
    pnode(const int &id,const int &dist):dist(dist),id(id){}
};
struct cmp
{
    bool operator()(pnode x,pnode y)
    {return x.dist>y.dist;}
};

vector<struct node> g[N];
int Dijkstra(int s,int t)
{
    int i,j,u,v;
    priority_queue<pnode,vector<pnode>,cmp > Q;
    for(i=0;i<n;++i)
    {dist[i]=INIF;used[i]=0;}
    dist[s]=0;
    Q.push(pnode(s,dist[s]));
    while(!Q.empty())
    {
        u=Q.top().id;
        Q.pop();
        if(u==t)return dist[t];
        used[u]=1;
        for(i=0;i<g[u].size();++i)
        {
            v=g[u][i].v;
            if(!used[v] && dist[v]>dist[u]+g[u][i].len)
            {
                dist[v]=dist[u]+g[u][i].len;
                Q.push(pnode(v,dist[v]));
            }
        }
    }
    return dist[t];
}

int main()
{
    int i,j,u,v,len;
    struct node tmp;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        for(i=0;i<n;++i)
            g[i].clear();
        for(i=0;i<m;++i)
        {
            scanf("%d%d%d",&u,&v,&len);
            --u;--v;
            tmp.v=v;tmp.len=len;
            g[u].push_back(tmp);
            tmp.v=u;
            g[v].push_back(tmp);
        }
        printf("%d\n",Dijkstra(0,n-1));

    }
    return 0;
}
