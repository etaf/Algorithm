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
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size() - k;
        std::nth_element(nums.begin(), nums.begin() + n, nums.end());
        return nums[n];
    }
};
int main()
{
    vector<int> nums = {1,3,9,2,10,8,4,6,7,5};
    Solution sol;
    for(unsigned int i=0; i<nums.size(); ++i){
        cout<<sol.findKthLargest(nums,i+1)<<endl;
    }
    return 0;
}


