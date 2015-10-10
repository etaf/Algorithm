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
typedef long long llong;
using namespace std;
class Solution_bsearch {//binary serarch answer
public:
    int findDuplicate(vector<int>& nums) {
        int mid, l=0, r=nums.size()-1,cnt;
        while(l+1<r){
            mid = (l+r) >> 1;
            cnt = 0;
            for(int i=0; i<nums.size(); ++i)
            {
                if(nums[i]<=mid)++cnt;
            }
            if(cnt>mid) r = mid;
            else l = mid;
        }
        return r;
    }
};
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast=0,slow=0;
        while(true){
            fast = nums[fast];
            fast = nums[fast];
            slow = nums[slow];
            if(fast == slow){
                fast = 0;
                while(fast!=slow){
                    fast = nums[fast];
                    slow = nums[slow];
                }
                return slow;
            }
        }
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    vector<int> nums1({1,2,3,4,5,3});
    vector<int> nums2({1,1});
    cout<<sol.findDuplicate(nums1)<<endl;
    cout<<sol.findDuplicate(nums2)<<endl;
    return 0;
}


