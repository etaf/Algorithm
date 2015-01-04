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
    vector<int> grayCode(int n) {
        vector<int> ans({0});
        int tmp_size;
        for(int i=0;i<n;++i){
            tmp_size = ans.size();
            for(int j=ans.size()-1;j>=0;--j){
                ans.push_back(ans[j] + (1<<i));
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> ans = sol.grayCode(3);
    for(int i=0;i<ans.size();++i)cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}


