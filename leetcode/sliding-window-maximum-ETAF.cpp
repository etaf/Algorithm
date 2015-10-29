
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

typedef long long llong;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int> > mq;
        for(int i=0; i<k && i<nums.size(); ++i){
            mq.push(pair<int,int>(nums[i],i));
        }
        vector<int> ans;
        if(mq.size()>0) ans.push_back(mq.top().first);
        for(int i=k; i< nums.size(); ++i){
            mq.push(pair<int,int>(nums[i],i));
            while(mq.top().second <= i-k) mq.pop();
            ans.push_back(mq.top().first);
        }
        return ans;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    vector<int> nums({1,3,-1,-3,5,3,6,7});
    Solution sol;
    vector<int> ans = sol.maxSlidingWindow(nums, 3);
    for(int i=0; i<ans.size(); ++i){
        cout<<ans[i]<<endl;
    }
    cout<<endl;

    return 0;
}


