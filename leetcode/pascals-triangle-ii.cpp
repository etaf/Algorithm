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
    vector<int> getRow(int rowIndex) { // O(n)space O(n*n)time
        vector<int> ans(rowIndex+1);
        ans[0] = 1;
        if(rowIndex == 0)return ans;
        for(int i=1;i<=rowIndex;++i){
            for(int j=i;j>=0;--j)
            {
                if(j-1>=0 && j<i)
                    ans[j] += ans[j-1];
                else
                    ans[j] = 1;
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> ans = sol.getRow(0);
    for(int i=0;i<ans.size();++i)cout<<ans[i]<<" ";
    cout<<endl;
	return 0;
}


