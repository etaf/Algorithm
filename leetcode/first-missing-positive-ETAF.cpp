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
    int firstMissingPositive(vector<int>& nums) {

        for(int i=0; i<nums.size(); ++i){
            while(nums[i] > 0 && nums[i]-1 != i && nums[i] -1 <nums.size()  && nums[nums[i]-1] != nums[i]){
                std::swap(nums[i], nums[nums[i]-1]);
            }
        }

        for(int i=0; i<nums.size(); ++i){
            if(nums[i] != i+1) return i+1;
        }
        return nums.size()+1;
    }
};
int main()
{
    Solution sol;
    //vector<int> A = {3,4,-1,1};
    //vector<int> A = {1,1};
    vector<int> A = {4};

    cout<<sol.firstMissingPositive(A)<<endl;

    std::ios::sync_with_stdio(false);
    return 0;
}


