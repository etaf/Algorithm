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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int mq[nums.size()-1],top=0,tail=0;
        for(int i=0; i<k; ++i){
            while(tail>top && nums[mq[tail-1]] <= nums[i]) --tail;
            mq[tail++] = i;
        }
        if(tail>top)
            ans.push_back(nums[mq[top]]);
        for(int i=k; i<nums.size(); ++i){
            while(tail>top && nums[mq[tail-1]] <= nums[i]) --tail;
            mq[tail++] = i;
            while(tail>top && mq[top] <= i-k) ++top;
            ans.push_back(nums[mq[top]]);
        }
        return ans;
    }
};
class Solution_heap {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if(nums.empty()) return  ans;
        int n = nums.size();
        int mq[nums.size()];
        int h=0,t=0;
        for(int i=0; i<k; ++i){
            while(t>h && nums[mq[t-1]] <= nums[i])--t;
            mq[t++] = i;
        }
        ans.push_back(nums[mq[h]]);
        for(int i=k; i < n; ++i){
           while(t>h && mq[h] < i-k+1 ) ++h;
           while(t>h && nums[mq[t-1]] <=nums[i]) --t;
           mq[t++] = i;
           ans.push_back(nums[mq[h]]);
        }
        return ans;
    }
};
int main()
{
    vector<int> nums({1,3,-1,-3,5,3,6,7});
    Solution sol;
    vector<int> ans = sol.maxSlidingWindow(nums, 3);
    for(int i=0; i<ans.size(); ++i){
        cout<<ans[i]<<endl;
    }
    cout<<endl;
    return 0;
}


