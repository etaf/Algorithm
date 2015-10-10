
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
typedef long long llong;
using namespace std;
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        if(n==0)return;
        int m= board[0].size();
        int dir[8][2] = {{1,0},{1,-1},{1,1},{0,1},{0,-1},{-1,0},{-1,1},{-1,-1}};
        int nx,ny;
        for(int i=0; i<n; ++i){
            for(int j=0;j<m; ++j){
                if(board[i][j] >0 ){
                    for(int k=0;k<8;++k){
                        nx = i+dir[k][0];
                        ny = j+dir[k][1];
                        if(nx>=0 && nx < n && ny>=0 && ny<m){
                            board[nx][ny] += (board[nx][ny]>0 ? 1 : -1);
                        }
                    }
                }
            }
        }
        for(int i=0;i<n; ++i){
            for(int j=0; j<m; ++j){
                if(board[i][j] == 3 || board[i][j] == 4 || board[i][j] == -3) board[i][j] = 1;
                else board[i][j] = 0;
            }
        }
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    vector<vector<int> > board({{0,1,0,1},{1,0,1,0},{1,1,1,0},{0,0,1,0}});
    sol.gameOfLife(board);
    for(int i=0; i<board.size(); ++i){
        for(int j=0;j<board[0].size(); ++j)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}


