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
#include<unordered_set>
#include<unordered_map>
#include<limits.h>
using namespace std;
class Solution { //bfs
public:

    int n;
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> ans;
        vector<vector<int> > fs(s.size());
        vector<int>  ps;
        n = s.size();
        string tmp;
        ps.push_back(n);
        for(int i=n-1;i>=0;--i){
            tmp = "";
            int k = i;
            bool flag = false;
            for(int j=ps.size()-1;j>=0;--j)
            {
                for(;k<ps[j];++k){
                    tmp.push_back(s[k]);
                }
                if(dict.find(tmp)!=dict.end())
                {
                    if(!flag){
                        ps.push_back(i);
                        flag = true;
                    }
                    fs[i].push_back(k);
                }
            }
        }
/*        for(int i=0;i<n;++i){*/
            //if(!fs[i].empty()){
                //for(int j=0;j<fs[i].size();++j)
                    //cout<<fs[i][j]<<" ";
                //cout<<endl;
            //}
        /*}*/
        queue<pair<int,string> > Q;
        Q.push(pair<int,string>(0,""));
        pair<int,string> now;
        while(!Q.empty())
        {
           now = Q.front();
           Q.pop();
           int k = now.first;
           /*if(k == n)*/
           //{
               //ans.push_back(now.second);
               //continue;
           /*}*/

           for(int i= fs[k].size()-1;i>=0;--i){
               if(fs[k][i] == n)
                    ans.push_back(now.second + s.substr(k,n-k));
               else Q.push(pair<int,string>(fs[k][i], now.second + s.substr(k,fs[k][i]-k) + " " ) ) ;
           }
        }
        return ans;
    }
};

class Solution_DFS { //dfs
public:

    int n;
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> ans;
        vector<vector<int> > fs(s.size());
        vector<int>  ps;
        n = s.size();
        string tmp;
        ps.push_back(n);
        for(int i=n-1;i>=0;--i){
            tmp = "";
            int k = i;
            bool flag = false;
            for(int j=ps.size()-1;j>=0;--j)
            {
                for(;k<ps[j];++k){
                    tmp.push_back(s[k]);
                }
                if(dict.find(tmp)!=dict.end())
                {
                    if(!flag){
                        ps.push_back(i);
                        flag = true;
                    }
                    fs[i].push_back(k);
                }
            }
        }
        return dfs(0,s,fs);
    }
    vector<string> dfs(int k,const string& s,const vector<vector<int> > & fs){
        vector<string> ans;
        if(k == n)
        {
            return ans;
        }
        int e;
       for(int i=0;i<fs[k].size();++i)
       {
           e = fs[k][i];
           string tmp = s.substr(k,e-k);
          if(e == n)
              ans.push_back(tmp);
          else{
            vector<string> tmp_ans = dfs(e,s,fs);
            for(int j=0;j<tmp_ans.size();++j)
            {
                ans.push_back(tmp + " " + tmp_ans[j]);
            }
          }
       }
       return ans;
    }
};
void test()
{
    unordered_set<string> dict;
    dict.insert(string("cat"));
    dict.insert(string("cats"));
    dict.insert(string("and"));
    dict.insert(string("dog"));
    dict.insert(string("sand"));
    //dict.insert(string("catsand"));
    string s = "catsanddog";
    Solution sol;
    vector<string> ans = sol.wordBreak(s,dict);
    for(int i=0;i<ans.size();++i) cout<<ans[i]<<endl;
}
int main()
{
    test();
	return 0;
}


