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
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[2][101];
        int c = 0;
        for(int i=0;i<m;++i,c^=1)
            for(int j=0;j<n;++j)
                if(i==0 || j==0)dp[c][j] = 1;
                else dp[c][j] = dp[1-c][j]+dp[c][j-1];
        return dp[1-c][n-1];
    }
};
void test(){
    Solution sol;
    cout<<sol.uniquePaths(10,1);
}
int main()
{
    test();
	return 0;
}


