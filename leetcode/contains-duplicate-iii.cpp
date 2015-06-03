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
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        if(n < 2) return false;
        if(t<0) return false;
        long long minn, maxn ;
        minn = maxn = nums[0];
        for(int i=1; i<n; ++i){
            minn = (minn < nums[i] ? minn : nums[i]);
            maxn =(maxn > nums[i] ? maxn : nums[i]);
        }
        long long  remapn, bucketn, tt = (long long)t+1;
        maxn -= minn;
        unordered_map<long long,long long> buckets;
        unordered_map<long long,long long>::iterator preb,nextb,currb;
        for(int i=0; i<n; ++i){
            remapn = nums[i] - minn;
            bucketn = remapn / tt;
            preb = buckets.find(bucketn-1);
            nextb = buckets.find(bucketn+1);
            currb = buckets.find(bucketn);
            if( (currb!=buckets.end()) || (preb!=buckets.end() && remapn - preb->second <=t)  ||( nextb != buckets.end() && buckets[bucketn+1] - remapn <=t))
                return true;
            if(currb == buckets.end()){
                buckets.insert(pair<int,int>(bucketn,remapn));
            }
            if(i-k>=0){
                currb = buckets.find((nums[i-k]-minn)/tt);
                if(currb != buckets.end())
                    buckets.erase(currb);
            }
        }
        return false;
    }
};
int main()
{
    Solution sol;
    //vector<int> nums = {-100,5,1000,15,100,22};
    vector<int> nums = {-1,2147483647};
    cout<<sol.containsNearbyAlmostDuplicate(nums,1,2147483647)<<endl;
    return 0;
}


