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
    int numIslands(vector<vector<char> > &grid) {
        int m = grid.size();
        if(m==0)return 0;
        int n = grid[0].size();
        int ans = 0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j] == '1'){
                    bfs(grid, i, j,m,n);
                    ++ans;
                }
            }
        }
        return ans;
    }
    void bfs(vector<vector<char> > &grid, int x, int y,int m,int n){
        int d[2][4] = {{-1,0,1,0},{0,1,0,-1}};
        queue<pair<int,int> > q;
        grid[x][y] += 1;
        q.push(pair<int,int>(x,y));
        while(!q.empty()){
            auto now = q.front();
            q.pop();
            auto next = now;
            for(int i=0;i<4;++i){
                next.first = now.first + d[0][i];
                next.second = now.second + d[1][i];
                if(next.first >=0 && next.first < m && next.second >= 0 && next.second < n  && grid[next.first][next.second] == '1')
                {
                    grid[next.first][next.second] += 1;
                    q.push(next);
                }
            }
        }
    }
};
int main()
{
    Solution sol;
    vector<vector<char> > grid({{'1','1','0','0','0'},{'1','1','0','0','0'}, {'0','0','1','0','0'},{'0','0','0','1','1'}});
    //vector<vector<char> > grid({{'1','1'}});
    cout<<sol.numIslands(grid)<<endl;
    return 0;
}


