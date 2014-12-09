/*
 * File:   main.cpp
 * Author: etaf
 *
 * Created on 2011年8月11日, 下午8:49
 * 4538748	2011-09-04 00:22:45	Accepted	4004	296MS	320K	1173 B	C++	kite
 */
#include<cstdio>
#include <cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
using namespace std;
const int N=500010;
int l,n,m,a[N];
bool judge(int x)
{
    int pos=0,id;
    for(int i=0;i<m;++i)
    {
        pos+=x;
        id=upper_bound(a,a+n,pos)-a-1;
        pos=a[id];
        if(pos==l)
            return 1;
    }
    return 0;

}
int main()
{
  //  freopen("in","r",stdin);
    int i,left,right,mid,ans;
    while(scanf("%d%d%d",&l,&n,&m)!=EOF)
    {
        for(i=1;i<=n;++i)
        {
            scanf("%d",a+i);
        }
        sort(a+1,a+1+n);
        a[++n]=l;
        ++n;
        left=0;right=l;
        while(left<=right)
        {
            mid=(left+right)>>1;
            if(judge(mid))
            {
                right=mid-1;
                ans=mid;
            }
            else
                left=mid+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
