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
    int maxProfit(vector<int> &prices) {
        if(prices.empty())return 0;
        int ans = 0;
        for(int i = 0;i<prices.size()-1;++i){
            if(prices[i]<prices[i+1]) ans += prices[i+1]-prices[i];
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


