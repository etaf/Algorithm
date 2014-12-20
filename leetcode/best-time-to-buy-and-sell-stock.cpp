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
class Solution_old {//O(n)space
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty())return 0;
        vector<int> mins(prices.size(),INT_MAX);
        mins[0] = prices[0];
        for(size_t i=1;i<prices.size();++i){
            mins[i] = min(mins[i-1],prices[i]);
        }
        int ans = 0,max_now = prices.back();
        for(int i=prices.size()-1;i>=0;--i){
            max_now = max(max_now,prices[i]);
            ans = max(ans,max_now-mins[i]);
        }
        return ans;
    }
};
class Solution {
public:
    int maxProfit(vector<int> &prices) { // O(n) time and O(1) space
        if(prices.empty())return 0;
        int ans = 0,minn = INT_MAX;
        for(size_t i=0;i<prices.size();++i){
            if(prices[i]>minn) ans = max(ans,prices[i]-minn);
            else minn = prices[i];
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> prices({3,1,5,9,2,5,1,0});
    //vector<int> prices({3,4});
    cout<<sol.maxProfit(prices)<<endl;
	return 0;
}


