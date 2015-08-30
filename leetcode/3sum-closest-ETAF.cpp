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
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int l , r, d = 0x3fffffff, t, tmp, ans = 0;
        for(int i=0; i<nums.size(); ++i)
        {
            t = target - nums[i];
            l = i+1;
            r = nums.size()-1;
            while(l<r){
                tmp = nums[l] + nums[r];
                if(tmp == t){
                    return target;
                }
                else if(tmp > t){
                    if(d > tmp-t){
                        ans = tmp+nums[i];
                        d = tmp-t;
                    }
                    --r;
                }
                else{
                    if(d> t-tmp){
                        d = t-tmp;
                        ans = tmp+nums[i];
                    }
                    ++l;
                }
            }
            while(i+1 < nums.size() && nums[i] == nums[i+1]) ++i;
        }
        return ans;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    vector<int> num({-1, 2, 1, -4});
    int ans = sol.threeSumClosest(num,1);
    cout<<ans<<endl;

    return 0;
}


