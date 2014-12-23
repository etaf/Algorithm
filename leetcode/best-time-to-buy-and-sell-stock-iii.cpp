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
    int maxProfit(vector<int> &prices) { //O(n)time O(n)space
        if(prices.empty())return 0;
        int ans = 0,minn = INT_MAX,maxn = prices.back();
        vector<int> d(prices.size(),0);
        for(int i=prices.size()-2;i>0;--i){
            d[i] = max(d[i+1],maxn-prices[i]);
            maxn = max(maxn,prices[i]);
        }
        for(size_t i=0;i<prices.size();++i){
            if(prices[i]>=minn) ans = max(ans,prices[i]-minn+d[i]);
            else minn = prices[i];
        }

        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> prices({1,2,1,1});
    cout<< sol.maxProfit(prices) << endl;
	return 0;
}


