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
        vector<int> ans( (1<<n) );
        ans[0] = 0;
        int pre_size = 1;
        for(int nn = 0; nn<n; ++nn){
            for(int i=pre_size-1, j = pre_size; i>=0; --i, ++j){
                ans[j] = (1<<nn) + ans[i];
            }
            pre_size = pre_size << 1;
        }
        return ans;
    }
};
class Solution_recursive {
public:
    vector<int> grayCode(int n) {
        if(n == 0){
            return {0};
        }
        vector<int> ans = grayCode(n-1);
        int len = ans.size();
        ans.resize( len<<1 );
        for(int i=len-1,j=len; i>=0; --i, ++j){
            ans[j] = ans[i] + (1<<(n-1));
        }
        return ans;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);

    Solution_recursive sol;
    vector<int> ans = sol.grayCode(3);
    for(int i=0;i<ans.size();++i)cout<<ans[i]<<" ";
    cout<<endl;

    return 0;
}


