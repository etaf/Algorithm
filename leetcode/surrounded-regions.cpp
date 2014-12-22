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

class Solution { // bfs or dfs from border where the board[i] == 'o'
public:
    void solve(vector<vector<char> > &board) {
        int m = board.size();
        if(m == 0)return;
        int n = board[0].size();
        vector<vector<bool> > f;
        for(int i=0;i<m;++i){
            f.push_back(vector<bool>(n,0));
        }
        queue<pair<int,int> > Q;
        for(int i=0;i<m;++i){
            if(board[i][0] == 'O'){
                Q.push(pair<int,int>(i,0));
                f[i][0] = true;
            }
            if(board[i][n-1] == 'O'){
                Q.push(pair<int,int>(i,n-1));
                f[i][n-1] = true;
            }
        }
        for(int j=1;j<n-1;++j){
            if(board[0][j] == 'O'){
                Q.push(pair<int,int>(0,j));
                f[0][j] = true;
            }
            if(board[m-1][j] == 'O'){
                Q.push(pair<int,int>(m-1,j));
                f[m-1][j] = true;
            }
        }
        pair<int,int> now,next;
        int d[2][4] = {{0,1,0,-1},{1,0,-1,0}};
        while(!Q.empty()){
           now = Q.front();
           Q.pop();
           for(int i=0;i<4;++i){
                next.first = now.first + d[0][i];
                next.second = now.second + d[1][i];
                if( next.first >=0 && next.first <m && next.second>=0 && next.second < n && board[next.first][next.second] == 'O' && !f[next.first][next.second]){
                    f[next.first][next.second] = 1;
                    Q.push(pair<int,int>(next));
                }
           }
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<n; ++j){
                if(board[i][j] == 'O' && !f[i][j])board[i][j] = 'X';
            }
        }
    }
};
int main()
{
    Solution sol;
    vector<vector<char> > vs({{'X','O','X'},{'O','X','O'},{'X','O','X'}});
    //vector<vector<char> > vs({{'O'}});
    sol.solve(vs);
    for(int i=0;i<vs.size();++i){
        for(int j=0;j<vs[0].size();++j)cout<<vs[i][j];
        cout<<endl;
    }
	return 0;
}


