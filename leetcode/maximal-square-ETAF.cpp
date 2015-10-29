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

typedef long long llong;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        int dp[n+1][m+1];
        int tmp,maxn = 0;
        memset(dp,0,sizeof(dp));

        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(matrix[i-1][j-1] == '0') continue;
                tmp = min(dp[i-1][j],dp[i][j-1]);
                dp[i][j] = tmp;
                if(i-tmp>=1 && j-tmp>=1 && matrix[i-tmp-1][j-tmp-1]!='0'){ dp[i][j] += 1; }
                maxn = max(maxn, dp[i][j]);
            }
        }
/*        for(int i=0;i<=n; ++i){*/
            //for(int j=0;j<=m;++j){
                //cout<<dp[i][j]<<" ";
            //}
            //cout<<endl;
        /*}*/
        return maxn*maxn;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    vector<vector<char> > matrix = {{'1','0','1','0','0',},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    vector<vector<char> > matrix1 = {{'1','0','1','0'},{'1','0','1','1'},{'1','0','1','1'},{'1','1','1','1'}};
    vector<vector<char> > matrix2 = {{'0','0','0','1'},{'1','1','0','1'},{'1','1','1','1'},{'0','1','1','1'},{'0','1','1','1'}};
    vector<vector<char> > matrix3 = {{'0','1','1','0','1'},{'1','1','0','1','0'},{'0','1','1','1','0'},{'1','1','1','1','0'},{'1','1','1','1','1'},{'0','0','0','0','0'}};
    cout<<sol.maximalSquare(matrix)<<endl;
    cout<<sol.maximalSquare(matrix1)<<endl;
    cout<<sol.maximalSquare(matrix2)<<endl;
    cout<<sol.maximalSquare(matrix3)<<endl;

    return 0;
}


