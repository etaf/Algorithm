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
    int jump(vector<int>& nums) {
        int rst = nums[0], nrst;
        int i=0,ans=0;
        int n = nums.size()-1;
        while(i<n){
            ++ans;
            nrst = rst;
            //if(rst >= nums.size() - 1) return ans;
            for(int j=i; j <= rst; ++j){
                nrst = nrst < j + nums[j] ? j + nums[j] : nrst;//max(nrst, j + nums[j]);
            }
            i = rst;
            rst = nrst;
        }
        return ans;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    vector<int> a({3,2,1});
    Solution sol;
    cout<<sol.jump(a)<<endl;

    return 0;
}


