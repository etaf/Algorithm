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
class Solution_bsearch { //nlog(n)
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        const int INF = 0x3fffffff;
        int n = nums.size();
        int sums[n+1];
        sums[0] = 0;
        for(int i=1;i<=n;++i){
            sums[i] = nums[i-1] + sums[i-1];
        }
        int l,r,mid;
        int ans = INF;
        for(int i=0;i<n;++i){
            l = i;
            r = n;
            while(l+1<r){
                mid = (l+r) >> 1;
                if(sums[mid+1] - sums[i]<= s){
                    l = mid;
                }else{
                    r = mid;
                }
            }
            if(sums[l+1] - sums[i] >= s){
                ans = min(ans,l+1-i);
            }else if (l+1 < n && sums[l+2] - sums[i] > s){
                ans = min(ans, l+2-i);
            }
        }
        if(ans == INF) return 0;
        return ans;
    }
};
class Solution_dp_nXs_TLE { // dp[i][j] means: end at index i, not less than j,  minSubArrayLen.
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int dp[s+1];
        const int INF = 2100000000;
        dp[0] = 0;
        for(int i=1; i<=s; ++i) dp[i] = INF;
        int ans = INF;
        for(int i=0; i<n; ++i){
            for(int j=s; j>0; --j){
                dp[j] = (nums[i] >= j ? 0 : dp[j-nums[i]]) + 1;
            }
            ans = min(ans,dp[s]);
        }
        if(ans == INF) return 0;
        return ans;
    }
};
class Solution_two_pointer { //two pointer, O(n)
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int l=0,r=0;
        int sum = 0;
        while(r<n && sum < s){
            sum += nums[r++];
        }
        if(sum<s) return 0;
        int ans = r-l;
        while(r<=n){
            sum -= nums[l++];
            while(r<n && sum < s){
                sum += nums[r++];
            }
            if(sum < s) return ans;
            ans = min(ans,r-l);
        }
        return ans;
    }
};
class Solution { //two pointer, O(n)
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(),l=0,r=0,sum = 0,ans = 0x3fffffff;
        while(r<=n){
            while(r<n && sum<s) sum+=nums[r++];
            if(sum < s) break;
            ans = ans < r-l ? ans : r-l;
            sum -= nums[l++];
        }
        return ans == 0x3fffffff ? 0 : ans;
    }
};
int main()
{
    Solution sol;
    //vector<int> nums = {2,1,1,2,1,2};
    vector<int> nums = {1,2,3,4,5};
    cout<<sol.minSubArrayLen(11,nums)<<endl;
    return 0;
}


