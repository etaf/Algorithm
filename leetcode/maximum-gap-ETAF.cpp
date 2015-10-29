
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
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2)return 0;
        int maxn = INT_MIN, minn = INT_MAX;
        for(int i=0; i<nums.size(); ++i){
            maxn = max(maxn, nums[i]);
            minn = min(minn, nums[i]);
        }
        int n = nums.size();
        int d = (maxn - minn)/(n-1);
        if(d == 0) return maxn - minn;
        int ns = (maxn-minn) / d + 1;
        vector<pair<int,int> >ps(ns);
        for(int i=0; i<ns; ++i) ps[i].first = INT_MAX, ps[i].second = INT_MIN;
        int id;
        for(int i=0; i<n; ++i){
            id= (nums[i]-minn)/d;
            ps[id].first = min(ps[id].first, nums[i]);
            ps[id].second = max(ps[id].second, nums[i]);
        }
        int ans = d;
        int l = 0 , r;
        while(l<=n && ps[l].second == INT_MIN) ++l;

        for(r=l+1; r<ns; ++r){
            while(r<ns && ps[r].first== INT_MAX) ++r;
            if(r == ns)break;
            ans = max(ans, ps[r].first-ps[l].second);
            l = r;
        }
        return ans;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    vector<int> nums1({6,9,9});
    vector<int> nums2({1,9});
    vector<int> nums3({1,1,1,1,1,5,5,5,5,5});
    cout<<sol.maximumGap(nums3)<<endl;
    cout<<sol.maximumGap(nums2)<<endl;
    cout<<sol.maximumGap(nums1)<<endl;
    return 0;
}


