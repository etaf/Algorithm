Source Code
Problem: 3013		User: 030902414
Memory: 3324K		Time: 610MS
Language: G++		Result: Accepted

    Source Code

    #include<iostream>
    #include<cstdio>
    #include<cstring>
    #include<algorithm>
    #include<queue>
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
    bool in_queue[N];
    void spfa(int s)
    {
        int i,u,p;
        queue<int> Q;
        for(i=1;i<=n;++i)
        {
            dist[i]=inf;
            in_queue[i]=0;
            //Count[i]=0;
        }
        dist[s]=0;
        Q.push(s);
        while(!Q.empty())
        {
            u=Q.front();
            Q.pop();
          //  ++Count[u];
            //if(Count[u]>=n)return false;
            in_queue[u]=false;
            p=head[u];
            while(p!=-1)
            {
                if(dist[E[p].v]>dist[u]+E[p].len)
                {
                    dist[E[p].v]=dist[u]+E[p].len;
                    if(!in_queue[E[p].v])
                    {
                        Q.push(E[p].v);
                        in_queue[E[p].v]=true;
                    }
                }
                p=next[p];
            }

        }
        //return true;
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
           // Dijkstra(1);
            spfa(1);
            ans=0;
            bool flag=1;
            for(i=1;i<=n;++i)
            {
              //  printf("dist[%d]=%d\n",i,dist[i]);
                if(ll(dist[i])>=inf){flag=0;break;}
                ans+=(ll)dist[i]*cost[i];
            }
            if(flag)
                printf("%lld\n",ans);
            else
                printf("No Answer\n");
        }
        return 0;
    }


