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
    vector<int> majorityElement(vector<int>& nums) {
        int cnt[3];
        int x[3];
        vector<int> ans;
        int n = nums.size();
        memset(cnt,0,sizeof(cnt));
        for(int i=0; i<n; ++i){
            for(int j=0; j<3; ++j){
                if(cnt[j] == 0){
                    cnt[j] = 1;
                    x[j] = nums[i];
                    if(cnt[0]>0 && cnt[1]>0 && cnt[2]>0) {
                        --cnt[0];
                        --cnt[1];
                        --cnt[2];
                    }
                    break;
                }
                if(x[j] == nums[i]){
                    ++cnt[j];
                    break;
                }
            }
        }

        int th = n%3 ? 0 : 1;
        for(int i=0; i<3; ++i){
            if(cnt[i]>th) ans.push_back(x[i]);
        }
        vector<int> ans2;
        for(int i=ans.size()-1; i>=0; --i){
            int cnt = 0;
            for(int j=0; j<n; ++j){
                if(ans[i] == nums[j]) ++cnt;
            }
            if(cnt > n/3) ans2.push_back(ans[i]);
        }
        return ans2;
    }
};
int main()
{
    Solution sol;
    vector<int> nums({1,2,1,2,2,1});
    //vector<int> nums({1,2,3,4});
    vector<int> ans = sol.majorityElement(nums);
    for(int i=0; i<ans.size(); ++i){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}


