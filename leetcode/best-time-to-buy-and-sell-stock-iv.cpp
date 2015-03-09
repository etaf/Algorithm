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
class Solution {
    private:
        int maxProfit_unlimited(vector<int> &prices) {
            if(prices.empty())return 0;
            int ans = 0;
            for(unsigned int i = 0;i<prices.size()-1;++i){
                if(prices[i]<prices[i+1]) ans += prices[i+1]-prices[i];
            }
            return ans;
        }

    public:
        int maxProfit(int k, vector<int> &prices) {
            //dp[k][i] = max(dp[k][i-1], dp[k-1][j] + prices[i]-prices[j])
            //         = max(dp[k][i-1], price[i] + max(dp[k-1][j]-prices[j]))
            int n = prices.size();
            if(n==0)return 0;
            int dp[n];
            memset(dp,0,sizeof(dp));
            int ans = 0;
            int tmp;
            if(k>=n/2){
                return maxProfit_unlimited(prices);
            }
            bool f_inc = false;
            for(int kk=0;kk<k;++kk){
                int max_tmp = dp[0] - prices[0];
                f_inc = false;
                for(int i=1;i<n;++i){
                    tmp = dp[i];
                    dp[i] = max(dp[i-1],prices[i]+max_tmp);
                    max_tmp  = max(max_tmp,tmp-prices[i]);
                    if(ans < dp[i]){
                        ans=dp[i];
                        f_inc = true;
                    }
                }
                if(!f_inc)
                    break;
            }
            return ans;
        }
};

int main()
{
    Solution sol;
    vector<int> prices({1,5,4,9});
    cout<<sol.maxProfit(2,prices)<<endl;
    return 0;
}


