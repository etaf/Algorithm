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
    int maxArea(vector<int>& height) {
        int l=0, r = height.size()-1;
        int ans = 0;
        while(l<r){
            if(height[l]>height[r]){
                ans = max(ans, (r-l)*height[r]);
                while(r-1>l && height[r-1] <= height[r]) --r;
                --r;
            }
            else{
                ans = max(ans, (r-l)*height[l]);
                while(l+1<r && height[l+1] <= height[l]) ++l;
                ++l;
            }
        }
        return ans;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    vector<int> h({1,2,0,3,4});
    cout<<sol.maxArea(h)<<endl;

    return 0;
}


