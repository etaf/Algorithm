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
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode* nexts[26];
    bool is_end;
    TrieNode() {
            memset(nexts,0,sizeof(nexts));
            is_end = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode* now = root;
        for(unsigned int i=0; i<s.size(); ++i){
            if(now->nexts[s[i]-'a'] == NULL ){
                now->nexts[s[i]-'a'] = new TrieNode();
            }
            now = now->nexts[s[i]-'a'];
        }
        now->is_end = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode* now = root;
        for(unsigned int i = 0; i < key.size(); ++i){
            if(now->nexts[key[i]-'a'] == NULL) return false;
            now = now->nexts[key[i]-'a'];
        }
        return now->is_end;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* now = root;
        for(unsigned int i = 0; i < prefix.size(); ++i){
            if(now->nexts[prefix[i]-'a'] == NULL ) return false;
            now = now->nexts[prefix[i]-'a'];

        }
        return true;
    }

    TrieNode* root;
};

int d[2][4] = {{0,1,0,-1},{1,0,-1,0}};
class Solution {
public:
    bool vis[128][128];
    int n,m;
    vector<string> ans;
    unordered_set<string> S;
    Trie trie;
    string path;
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        for(unsigned long i=0; i<words.size(); ++i) trie.insert(words[i]);
        n = board.size();
        m = board[0].size();
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                memset(vis,0,sizeof(vis));
                path="";
                dfs(i,j,trie.root,board);
            }
        }
        return ans;
    }
    void dfs(int x, int y, TrieNode* now, const vector<vector<char> >& board){
        TrieNode* next = now->nexts[board[x][y]-'a'];
        if(next)
        {
            path.push_back(board[x][y]);
            if(next->is_end && S.find(path) == S.end()){
                ans.push_back(path);
                S.insert(path);
            }
            vis[x][y] = true;
            for(int i=0;i<4;++i){
                if(0 <= x+d[0][i] && x+d[0][i] <n && 0<= y+d[1][i] && y+d[1][i]<m && !vis[x+d[0][i]][y+d[1][i]])
                {
                    dfs(x+d[0][i], y+d[1][i], next, board);
                }
            }
            vis[x][y] = false;
            path.pop_back();
        }
    }
};
int main()
{
    Solution sol;
    vector<string> word = {"aba","baa","bab","aaab","aaa","aaaa","aaba"};
    vector<vector<char> > board({{'a','b'},{'a','a'}});

    vector<string> ans = sol.findWords(board,word);
    for(int i=0; i<ans.size(); ++i){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}


