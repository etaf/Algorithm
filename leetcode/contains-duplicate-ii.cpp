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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        const int M = 1000007;
        int hash_table[M];
        int n = nums.size();
        int pos;
        memset(hash_table,0,sizeof(hash_table));
        for(int i=0; i<n; ++i){
            pos = (nums[i]+M)%M;
            if(hash_table[pos] && i+1 - hash_table[pos] <= k)
                return true;
            hash_table[pos] = i+1;
        }
        return false;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {-1,-1};
    cout<<sol.containsNearbyDuplicate(nums,1)<<endl;
    return 0;
}


