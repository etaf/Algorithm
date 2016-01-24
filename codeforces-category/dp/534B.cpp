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

int dp[101][1101];
void solve(){
    int v1, v2, n, d;
    const int maxv = 1101;
    scanf("%d %d %d %d", &v1, &v2, &n, &d);
    memset(dp,-1,sizeof(dp));
    dp[0][v1] = v1;
    int tmp;
    for(int i=1; i<n; ++i){
        for(int v = 0; v<maxv; ++v )
        {
            tmp = -1;
            for(int detv = 0; detv <= d; ++detv){
                tmp =  max(tmp, max(v+detv<maxv ? dp[i-1][v+detv] : -1, v-detv>=0 ? dp[i-1][v-detv] : -1));
            }
            if(tmp>0){
                dp[i][v] = tmp + v;
            }
        }
    }
    printf("%d\n", dp[n-1][v2]);
}
void solve_greedy(){
    int v1, v2, n, d, v;
    scanf("%d %d %d %d", &v1, &v2, &n, &d);
    int ans = v1 + v2;
    v = v1;
    for(int i=1; i<n-1; ++i){
        v =min(v+d, v2 + d*(n-1-i));
        ans += v;
    }
    printf("%d\n",ans);
}
int main()
{
    solve_greedy();
    return 0;
}


