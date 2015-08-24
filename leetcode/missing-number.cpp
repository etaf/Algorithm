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
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        for(auto i=0; i<nums.size(); ++i){
            ans ^= i;
            ans ^=nums[i];
        }
        return ans ^ nums.size();
    }

    int missingNumber_old_1(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<=nums.size(); ++i){
            ans ^= i;
        }
        for(auto x:nums){
            ans ^=x;
        }
        return ans;
    }
    int missingNumber_old(vector<int>& nums) {
        long sum = (nums.size()+1)*(nums.size())/2;
        for(auto x : nums){
            sum -= x;
        }
        return (int)sum;
    }

};
int main()
{
    Solution sol;
    vector<int> nums({0,1,3,4,5});
    //vector<int> nums({});
    cout<<sol.missingNumber(nums)<<endl;
    return 0;
}


