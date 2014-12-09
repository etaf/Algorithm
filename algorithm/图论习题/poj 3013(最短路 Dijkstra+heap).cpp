Source Code
Problem: 3013		User: 030902414
Memory: 3364K		Time: 797MS
Language: G++		Result: Accepted

    Source Code

    #include<iostream>
    #include<cstdio>
    #include<cstring>
    #include<algorithm>
    using namespace std;
    typedef long long ll;
    const int N=50010;
    const ll inf=10000000000000000LL;
    typedef struct edge
    {
        int u,v,len;
        edge(){}
        edge(int u1,int v1,int len1):u(u1),v(v1),len(len1){}
    }edge;
    edge E[N+N];
    int head[N+N],next[N+N];
    inline void addedge(int i,int u,int v,int len)
    {
        E[i]=edge(u,v,len);
        next[i]=head[u];
        head[u]=i;
    }

    int n,m;
    int cost[N];
    bool vis[N];
    ll dist[N];
    typedef struct heap_node
    {
        int v;
        ll dist;
        heap_node(){}
        heap_node(int v1,ll dist1):v(v1),dist(dist1){}
        bool operator<(const heap_node& z)const
        {return dist<z.dist;}
    }heap_node;
    heap_node C[N];
    void Dijkstra(int s)
    {
        int i,u,top=0,p;
        for(i=1;i<=n;++i)
        {
            dist[i]=inf;
            vis[i]=0;
        }
        dist[s]=0;
        C[top++]=heap_node(1,0);
        while(top>0)
        {
            pop_heap(C,C+top);
            --top;
            u=C[top].v;
            vis[u]=1;
            p=head[u];
            while(p!=-1)
            {
                if(dist[E[p].v]>dist[u]+E[p].len)
                {
                    dist[E[p].v]=dist[u]+E[p].len;
                    C[top++]=heap_node(E[p].v,dist[E[p].len]);
                    push_heap(C,C+top);
                }
                p=next[p];
            }
        }
    }
    int main()
    {
        int T,i,j,u,v,len;
       
        ll ans;
        scanf("%d",&T);
        while(T--)
        {

            scanf("%d%d",&n,&m);
            for(i=1;i<=n;++i)
                scanf("%d",cost+i);
            memset(head,-1,sizeof(head));
            for(i=0;i<m;++i)
            {
                scanf("%d%d%d",&u,&v,&len);
                addedge(i,u,v,len);
                addedge(i+m,v,u,len);
            }
            Dijkstra(1);
            ans=0;
            bool flag=1;
            for(i=1;i<=n;++i)
            {
              //  printf("dist[%d]=%d\n",i,dist[i]);
                if(dist[i]>=inf){flag=0;break;}
                ans+=dist[i]*cost[i];
            }
            if(flag)
                printf("%lld\n",ans);
            else
                printf("No Answer\n");
        }
        return 0;
    }


