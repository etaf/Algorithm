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
class Solution { // use 1d space
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> dp(n,0);
        dp[0] = 1;
        for(int i=0;i<m;++i)for(int j=0;j<n;++j){
            if(obstacleGrid[i][j]) dp[j] = 0;
            else if(j>0) dp[j] += dp[j-1];
        }
        return dp[n-1];
    }
};

class Solution_2dspace { // use 2d space
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[2][101];
        int c = 0;
        for(int i=0;i<m;++i,c^=1)
            for(int j=0;j<n;++j){
                if(!i && !j){dp[i][j] = 1-obstacleGrid[0][0];continue;}
                if(obstacleGrid[i][j] == 1) dp[c][j] = 0;
                else  dp[c][j] = (i ? dp[1-c][j] : 0) + (j ? dp[c][j-1]: 0);
            }
        return dp[1-c][n-1];
    }
};
void test(){
    vector<vector<int> > g({{0,0,0},{0,1,0},{0,0,0}});
    //vector<vector<int> > g({{0}});
    Solution sol;
    cout<<sol.uniquePathsWithObstacles(g);
}
int main()
{
    test();
	return 0;
}


