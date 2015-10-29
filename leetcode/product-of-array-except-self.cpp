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
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        vector<int> nums_bk = nums;
        //int tmp;
        for(int i=0; i<nums.size(); ++i){
            //tmp = nums[i];
            nums[i] = product;
            product *= nums_bk[i];
        }
        product = 1;
        for(int i=nums.size()-1; i>=0; --i){
            nums[i] *= product;
            product *= nums_bk[i];
        }
        return nums;
    }
};
int main()
{
    Solution sol;
    vector<int> nums({1,2,3,4});
    vector<int> ans = sol.productExceptSelf(nums);
    for(int i=0; i<ans.size(); ++i){
        cout<<ans[i]<<endl;
    }
    return 0;
}


