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
    vector<int> singleNumber(vector<int>& nums) {  // 00 -> 01 -> 10 -> 11->00
        int a=0, b=0;
        for(int i=0; i<nums.size(); ++i) a^=nums[i];
        int tmp = a & -a; //get the first one start from right
        for(int i=0; i<nums.size(); ++i) if(nums[i] & tmp) b ^= nums[i];
        return {a^b,b};
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    vector<int> ans = sol.singleNumber(nums);
    cout<<ans[0]<< " " <<ans[1]<<endl;
    return 0;
}


