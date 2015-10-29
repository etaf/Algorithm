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
    int partition(vector<int>& nums, int l, int r){
        int pivot = nums[r];
        int ll = l, rr = r-1;
        while(ll<rr){
            while(ll<r && nums[ll] >= pivot) ++ll;
            while(l<=rr && nums[rr] < pivot) --rr;
            if(ll<rr)swap(nums[ll],nums[rr]);
        }
        if(nums[ll]<=pivot){
            swap(nums[ll],nums[r]);
            return  ll;
        }else{
            return ll+1;
        }
        //return l;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size()-1, t;
        t = partition(nums,l,r);
        --k;
        while(t!=k){
            //cout<<l<<"-"<<r<<endl;
            if(t>k)r = t-1;
            else l = t+1;
            t = partition(nums,l,r);
        }
        return nums[k];
    }
};

class Solution_accpeted {
public:
    int partition2(vector<int>& nums, int l, int r){
        int pivot = nums[r];
        int i=l-1;
        for(int j=l;j<=r; ++j){
            if(nums[j] >= pivot){
                swap(nums[++i],nums[j]);
            }
        }
        return i;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size()-1, t;
        t = partition2(nums,l,r);
        --k;
        while(t!=k){
            //cout<<l<<"-"<<r<<endl;
            if(t>k)r = t-1;
            else l = t+1;
            t = partition2(nums,l,r);
        }
        return nums[k];
    }
};
class Solution_stl {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size() - k;
        std::nth_element(nums.begin(), nums.begin() + n, nums.end());
        return nums[n];
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {1,3,9,2,10,8,4,6,7,5};
    vector<int> nums2 = {2,2};
    vector<int> nums3 = {2,1};

    cout<<sol.findKthLargest(nums2,1)<<endl;
    cout<<sol.findKthLargest(nums3,1)<<endl;

    for(unsigned int i=0; i<nums.size(); ++i){
        cout<<sol.findKthLargest(nums,i+1)<<endl;
    }
    return 0;
}


