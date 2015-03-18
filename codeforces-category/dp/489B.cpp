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

void solve(){
    long n,m;
    cin>>n;
    long ns[n+1];
    for(long i=1;i<=n;++i){
        cin>>ns[i];
    }
    cin>>m;
    long ms[m+1];
    for(long i=1;i<=m;++i){
        cin>>ms[i];
    }
    sort(ns+1,ns+n+1);
    sort(ms+1,ms+m+1);
    //dp[i][j] = max(dp[i-1][j-1]+(abs(ns[i]-ns[j]) < 2) , dp[i-1][j] , dp[i][j-1]);
    long dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(long i=1;i<=n;++i){
        for(long j=1;j<=m;++j){
            dp[i][j] = max(dp[i-1][j-1] +( abs(ns[i]-ms[j])<2 ), max(dp[i-1][j],dp[i][j-1]));
        }
    }
    cout<<dp[n][m]<<endl;
}
int main()
{
ios::sync_with_stdio(false);
    solve();
    return 0;
}


