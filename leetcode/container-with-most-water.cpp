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
class Solution_old {
public:
    int maxArea(vector<int> &height) {//optimized but use more time
        int l = 0, r = height.size()-1;
        int maxhl=0, maxhr=0;
        int ans=0;
        while(l<r){
            if(height[l]>=height[r]){
                ans = max( (r-l)*height[r],ans);
                --r;
                while(l<r-1 && height[r] < maxhr)--r;
                maxhr = max(maxhr, height[r]);
            }else{
                ans = max( (r-l)*height[l],ans);
                ++l;
                while(l+1<r && height[l]< maxhl) ++l;
                maxhl = max(maxhl, height[l]);
            }
        }
        return ans;
    }
};
class Solution_1 { // not optimized but use less time
public:
    int maxArea(vector<int> &height) {
        int l = 0, r = height.size()-1;
        int ans=0;
        while(l<r){
            if(height[l]>=height[r]){
                ans = max( (r-l)*height[r],ans);
                --r;
            }else{
                ans = max( (r-l)*height[l],ans);
                ++l;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> h({1,2,0,3,4});
    cout<<sol.maxArea(h)<<endl;

    return 0;
}


