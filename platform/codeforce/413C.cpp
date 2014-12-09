#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long llong;


int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a[128],b[128];
    llong sum = 0;
    for(int i=1;i<=n;++i)
    {
        scanf("%d",a+i);
        sum+=a[i];
    }
    if(!m)
    {
        cout<<sum<<endl;
        return 0;
    }
    int x;
    for(int i=0;i<m;++i)
    {
        scanf("%d",&x);
        b[i] = a[x];
        sum-=a[x];
    }
    sort(b,b+m);
    for(int i=m-1;i>=0;--i)
    {
        sum+= sum>b[i]?sum:b[i];
    }
    cout<<sum<<endl;
    return 0;
}
