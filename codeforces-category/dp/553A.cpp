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

/*
 * color[i] means the number of ball of color i.
 * dp[i] means the valid solution using the first i color.
 * dp[i+1] = dp[i] * C[color[0] + ];
 */
const int N = 1024;
const int MOD = 1000000007;
typedef long long llong;
llong C[N][N];
void get_combination(int n){
    for(int i=0; i<=n; ++i){
        C[i][0] = C[i][i] = 1;
        for(int j=1; j<i; ++j){
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
        }
    }
}
void solve(){
    int k, color, sum=0;
    scanf("%d",&k);
    get_combination(1000);
    llong ans = 1;
    while(k--){
        scanf("%d", &color);
        ans = (ans* C[sum+color-1][color-1])%MOD;
        sum+=color;
    }
    cout<<ans<<endl;
}
int main()
{
    solve();
    return 0;
}


