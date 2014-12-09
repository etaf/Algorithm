#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int n,m,maxn,minn;
    int a[128];
    scanf("%d%d%d%d",&n,&m,&minn,&maxn);
    int need = 2;
    bool ans = true;
    for(int i=0;i<m;++i)
    {
        scanf("%d",a+i);
        if(a[i] > maxn || a[i] < minn )
            ans = false;
        if(a[i] == maxn)
            --need;
        if(a[i] == minn)
            --need;
    }

    if(!ans || need > n-m)
    {
        puts("Incorrect");
    }else
        puts("Correct");
    return 0;
}
