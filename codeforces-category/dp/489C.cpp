#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<limits.h>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<cstdlib>
using namespace std;
void solve(){ //greedy
    int m,s;
    cin>>m>>s;
    if(s == 0 && m > 1){
        printf("-1 -1\n");
        return;
    }
    char smin [128], smax[128];
    smin[m] = 0;
    smax[m] = 0;
    int st = s,t;
    for(int i=m-1;i>=0;--i){
        t =  min(9, st - (i>0));
        st -= t;
        smin[i] = '0' + t;
    }
    if(st != 0 )
    {
        printf("-1 -1\n");
        return ;
    }
    st = s;
    for(int i=0;i<m; ++i){
        t = min( 9, st);
        smax[i] = '0' + t;
        st -= t;
    }
    printf("%s %s\n",smin,smax);
}


int main()
{
ios::sync_with_stdio(false);
    solve();
    return 0;
}


