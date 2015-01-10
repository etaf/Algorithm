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
    bool fx[10][10],fy[10][10],ft[3][3][10];
    vector<pair<int,int> > ps;
    void solveSudoku(vector<vector<char> > &board) {
        memset(fx,0,sizeof(fx));
        memset(fy,0,sizeof(fy));
        memset(ft,0,sizeof(ft));
        int x;
        for(size_t i =0;i<board.size();++i){
            for(size_t j=0;j<board[i].size();++j){
                if(board[i][j] == '.'){
                    ps.push_back(pair<int,int>(i,j));
                    continue;
                }
                x = board[i][j]-'0';
                fx[i][x] = 1;
                fy[j][x] = 1;
                ft[i/3][j/3][x] = 1;
            }
        }
        dfs(0,board);
    }
    bool dfs(int u,vector<vector<char> > &board){
        if(u==ps.size()){
            return true;
        }
        int x = ps[u].first, y = ps[u].second;
        for(int i=1;i<10;++i){
            if(!fx[x][i] && !fy[y][i] && !ft[x/3][y/3][i]){
                fx[x][i] = 1;
                fy[y][i] = 1;
                ft[x/3][y/3][i] = 1;
                board[x][y] = '0' + i;
                if(dfs(u+1,board) ) return true;
                fx[x][i] = 0;
                fy[y][i] = 0;
                ft[x/3][y/3][i] = 0;
            }
        }
        return false;
    }
};
int main()
{
    vector<vector<char> > g({
                            { '.' , '.' , '9' , '7' , '4' , '8' , '.' , '.' , '.' },
                            { '7' , '.' , '.' , '.' , '.' , '.' , '.' , '.' , '.' },
                            { '.' , '2' , '.' , '1' , '.' , '9' , '.' , '.' , '.' },
                            { '.' , '.' , '7' , '.' , '.' , '.' , '2' , '4' , '.' },
                            { '.' , '6' , '4' , '.' , '1' , '.' , '5' , '9' , '.' },
                            { '.' , '9' , '8' , '.' , '.' , '.' , '3' , '.' , '.' },
                            { '.' , '.' , '.' , '8' , '.' , '3' , '.' , '2' , '.' },
                            { '.' , '.' , '.' , '.' , '.' , '.' , '.' , '.' , '6' },
                            { '.' , '.' , '.' , '2' , '7' , '5' , '9' , '.' , '.' }});
    Solution sol;
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j)cout<<g[i][j];
        cout<<endl;
    }
    sol.solveSudoku(g);
    cout<<endl<<endl;
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j)cout<<g[i][j];
        cout<<endl;
    }

    return 0;
}


