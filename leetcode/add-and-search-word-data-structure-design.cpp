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
    virtual bool search(string key) {
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
//private:
    TrieNode* root;
};
class WordDictionary : public Trie  {
public:
    // Adds a word into the data structure.
    void addWord(string word) {
        insert(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string key) {
        return dfs_search(0, root, key);
    }

    bool dfs_search(int start_index, TrieNode* now, const string& key){
    for(unsigned int i = start_index; i < key.size(); ++i){
            if(key[i] != '.'){
                if(now->nexts[key[i]-'a'] == NULL) return false;
                now = now->nexts[key[i]-'a'];
            }
            else{
                for(int j=0; j<26; ++j){
                    if(now->nexts[j] == NULL) continue;
                    if(dfs_search(i+1,now->nexts[j],key)) return true;
                }
                return false;
            }
        }
        return now->is_end;

    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
int main()
{
 WordDictionary wordDictionary;
 wordDictionary.addWord("word");
 cout<<wordDictionary.search(".o.")<<endl;

    return 0;
}


