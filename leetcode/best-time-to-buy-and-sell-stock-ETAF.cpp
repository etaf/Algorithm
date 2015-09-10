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
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int minn = prices[0];
        int ans = 0;
        for(int i=1; i<prices.size(); ++i){
            if(minn > prices[i]) minn = prices[i];
            else ans = max(ans, prices[i] - minn);
        }
        return ans;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    vector<int> prices({3,1,5,9,2,5,1,0});

    cout<<sol.maxProfit(prices)<<endl;
    return 0;
}


