#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int a[128];
    for(int i=0;i<n;++i)
        scanf("%d",a+i);
    sort(a,a+n);
    printf("%d\n",a[n-k]);
    return 0;
}
