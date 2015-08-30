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
    int search(vector<int>& nums, int target) {
        int l =0, r=nums.size(), mid;
        while(l+1<r){
            mid = (l+r)>>1;
            if(target < nums[mid]){
                if(nums[mid] < nums[0]) r = mid;
                else{
                    if( target < nums[0]) l = mid+1;
                    else r = mid;
                }
            }else{
                if(nums[mid] < nums[0] && target >= nums[0])
                    r = mid;
                else l = mid;
            }
        }
        return nums[l] == target ? l : -1;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    vector<int> nums = {4,5,6,7,0,1,2};
    cout<<sol.search(nums,0)<<endl;

    return 0;
}


