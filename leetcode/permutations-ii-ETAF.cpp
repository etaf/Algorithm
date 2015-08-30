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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        ans.push_back(nums);
        while (next_permutation(nums.begin(), nums.end()))
        {
            ans.push_back(nums);
        }
        return ans;

    }
};
void test(){
    vector<int> num({1,1,3});
    Solution sol;
    vector< vector<int> > ans = sol.permuteUnique(num);
    for(int i=0;i<ans.size();++i){
        for(int j=0;j<ans[i].size();++j){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    test();
    return 0;
}


