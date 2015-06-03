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
    int maximalSquare(vector<vector<char> >& matrix) {
        int n=matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        int dp[n][m];
        int ans = 0;
        memset(dp,0,sizeof(dp));
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(i == 0 || j==0) dp[i][j] = matrix[i][j] - '0';
                else{
                    if(matrix[i][j] == '0') continue;
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1]);
                    dp[i][j] = dp[i][j] + matrix[i-dp[i][j]][j-dp[i][j]] - '0';
                }
                ans = max(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }
};
class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        int n=matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        int dp[m];
        int ans = 0;
        memset(dp,0,sizeof(dp));
        int l;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(i == 0 || j==0) dp[j] = matrix[i][j] - '0';
                else{
                    if(matrix[i][j] == '0'){
                        dp[j] = 0;
                        continue;
                    }
                    l = min(dp[j],dp[j-1]);
                    dp[j] = l +  matrix[i-l][j-l] - '0';
                }
                ans = max(ans,dp[j]);
            }
        }
        return ans*ans;
    }
};
int main()
{
    Solution sol;
    vector<vector<char> > matrix = {{'1','0','1','0','0',},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout<<sol.maximalSquare(matrix)<<endl;
    return 0;
}


