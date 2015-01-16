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

int d[2][4] = {{0,1,0,-1},{1,0,-1,0}};
class Solution {
public:
    bool vis[128][128];
    int n,m;
    bool exist(vector<vector<char> > &board, string word) {
        n = board.size();
        m = board[0].size();
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(board[i][j] == word[0]){
                    memset(vis,0,sizeof(vis));
                    if(dfs(i,j,board,word,0))return true;
                }
            }
        }
        return false;
    }
    bool dfs(int x,int y,vector<vector<char> > &board, string& word,int step){
        if(step == word.size()-1) return board[x][y] == word[step];
        if(board[x][y] != word[step]) return false;
        vis[x][y] = true;
        for(int i=0;i<4;++i){
            if(0<= x+d[0][i] && x+d[0][i] <n && 0<= y+d[1][i] && y+d[1][i]<m && !vis[x+d[0][i]][y+d[1][i]])
                if(dfs(x+d[0][i],y+d[1][i],board,word,step+1))return true;
        }
        vis[x][y] = false;
        return false;
    }
};
int main()
{
    Solution sol;
    string word = "aaa";
    vector<vector<char> > board({{'a','a'}});
    cout<<sol.exist(board,word)<<endl;
    return 0;
}


