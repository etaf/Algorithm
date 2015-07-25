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
const int N = 100001;
int dp[N][3];
int th[N][2];

void solve(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        scanf("%d %d", &th[i][0], &th[i][1]);
    }
    if(n<3){
        printf("%d\n", n);
        return;
    }

    dp[0][0] = 0;
    dp[0][1] = 1;
    dp[0][2] = th[0][0] + th[0][1] < th[1][0];

    for(int i=1; i<n-1; ++i){
        dp[i][0] = std::max(dp[i-1][0], std::max(dp[i-1][1], dp[i-1][2]));
        if(th[i][0]-th[i][1] > th[i-1][0]){
            dp[i][1] = max(dp[i-1][0], dp[i-1][1]) + 1;
            if(th[i][0]-th[i][1] > th[i-1][0] + th[i-1][1])
                dp[i][1] = max(dp[i][1],dp[i-1][2] + 1);
        }else{
            dp[1][1] = 0;
        }
        if(th[i][0] + th[i][1] < th[i+1][0])
        {
            dp[i][2] = dp[i][0] + 1;
        }
        else{
            dp[i][2] = 0;
        }
    }
/*    for(int i=0;i<n-1;++i){*/
        //cout<<dp[i][0] << " "<<dp[i][1] <<" " << dp[i][2]<<endl;
    /*}*/
    printf("%d\n", max(dp[n-2][0],max(dp[n-2][1], dp[n-2][2])) + 1);
}
int main()
{
    solve();
    return 0;
}


