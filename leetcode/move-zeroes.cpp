
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
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        for(int i=0;i<nums.size(); ++i){
            if(nums[i]) nums[cnt++] = nums[i];
        }
        while(cnt<nums.size()){
            nums[cnt++] = 0;
        }
    }
};

class Solution_old {
public:
    void moveZeroes(vector<int>& nums) {
        for(int p0=0,p1=0; p0<nums.size() ; ++p0 ){
            while(p0<nums.size() && nums[p0]) ++p0;
            p1 = max(p1,p0)+1;
            while(p1<nums.size() && !nums[p1]) ++p1;
            if(p0==nums.size() || p1 == nums.size()) return;
            swap(nums[p0],nums[p1]);
        }
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    vector<int> nums({4,2,4,0,0,3,0,5,1,0});
    sol.moveZeroes(nums);
    for(int i=0; i<nums.size(); ++i)cout<<nums[i]<<" ";
    cout<<endl;
    return 0;
}


