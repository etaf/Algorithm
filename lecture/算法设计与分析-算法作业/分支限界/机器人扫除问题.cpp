 
             
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int MAX=106;
const int inf=0xffff;

int Move[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

struct Node
{
    int x,y,step;
};

struct Dirty
{
    int x,y;
}Num[13];

int n,m,Min,k,Flag[13][13];
char Map[MAX][MAX];
bool flag,Used[13];
bool Visted[MAX][MAX];

queue<Node> Q;


int BFS( int x, int y, int x2, int y2 )
{
    while( !Q.empty() )
     Q.pop();
    memset(Visted,0,sizeof(Visted));
    Visted[x][y]=1;
    Node p1;
    p1.x=x;
    p1.y=y;
    p1.step=0;
    Q.push(p1);
    while( !Q.empty() )
    {
        Node Now=Q.front();
        Q.pop();
        for( int i=0; i<4; ++i )
        {
            Node Next;
            Next.x=Now.x+Move[i][0];
            Next.y=Now.y+Move[i][1];
            Next.step=Now.step+1;
            if( Next.x<0 || Next.y<0 || Next.x>=n || Next.y>=m
               || Map[Next.x][Next.y]=='x' )
                continue;
             if( !Visted[Next.x][Next.y] )
             {
                 Visted[Next.x][Next.y]=1;
                 if( Next.x==x2 && Next.y==y2 )
                 {

                     return Next.step;
                 }
                 Q.push(Next);
             }
        }
    }
    return inf;
}

void DFS( int x, int sum, int len )
{
    if( len>Min )
      return;
    if( sum>=k )
    {
        Min=Min<len?Min:len;
        return;
    }
    for( int i=0; i<=k; ++i )
    {
        if( Flag[x][i]!=inf && !Used[i] )
        {
            Used[i]=1;
            DFS(i,sum+1,len+Flag[x][i]);
            Used[i]=0;
        }
    }
}
int main()
{
  
   int i,j;
    while( scanf("%d%d",&n,&m)!=EOF )
    {
        if( !n && !m )
         break;
        k=0;
        getchar();
        for( i=0; i<n; ++i )
        {
          for(  j=0; j<m; ++j )
          {
             scanf("%c",&Map[i][j]);
             if( Map[i][j]=='o' )
             {
                Num[0].x=i;
                Num[0].y=j;
                Map[i][j]='.';
             }
             else if( Map[i][j]=='*' )
             {
                 Num[++k].x=i;
                 Num[k].y=j;
             }
          }
          getchar();
        }
        Min=0;
        flag=1;
        //cout<<k<<endl<<endl;
        if( k==0 )
        {
            printf("0\n");
            continue;
        }
        for(i=0; i<=k && flag; ++i )
          for(  j=i+1; j<=k; ++j )
          {
            int temp=BFS(Num[i].x,Num[i].y,Num[j].x,Num[j].y);
            Flag[i][j]=Flag[j][i]=temp;
            if( temp==inf )
            {
                flag=0;
                break;
            }
          }
        if( !flag )
        {
          printf("-1\n");
          continue;
        }
        memset(Used,0,sizeof(Used));
        Min=inf;
        Used[0]=1;
        DFS(0,0,0);
        printf("%d\n",Min);
    }
    return 0;
}

        
        