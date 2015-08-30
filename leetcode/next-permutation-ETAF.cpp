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
    void nextPermutation(vector<int>& nums) {
        int p = nums.size()-1;
        while(p-1>=0 && nums[p-1]>= nums[p] ) --p;
        //sort(nums.begin() + p, nums.end());
        std::reverse(nums.begin() + p, nums.end());
        if(p==0) return;
        auto it = upper_bound(nums.begin()+p, nums.end(), nums[p-1]);
        swap(*it, nums[p-1]);
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    vector<int> num({2,3,6,4,4,1});
    Solution sol;
    sol.nextPermutation(num);
    for(int i=0;i<num.size();++i)
        cout<<num[i]<<" ";
    cout<<endl;

    return 0;
}


