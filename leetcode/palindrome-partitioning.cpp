#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
class Solution {
public:
    vector<vector<string> > ans;
    string ss;
    vector<vector<int> > vs;
    int n;
    vector<vector<string> > partition(string s) {
        int n = s.size();
        ss = s;
        vs.resize(n);
        int p,q;
        for(int i=0;i<n;++i){
            p=i-1;q=i+1;
            vs[i].push_back(i);
            while(p>=0 && q<n && s[p]==s[q]){
               vs[p].push_back(q);
               --p;++q;
            }
        }
        for(int i=0;i<n-1;++i){
            p=i;q=i+1;
            while(p>=0 && q<n && s[p] == s[q]){
                vs[p].push_back(q);
                --p;++q;
            }
        }
        vector<string> res;
        dfs(0,res);
        return ans;
    }
    void dfs(int u,vector<string> & res){
        if(u == ss.size()){
            ans.push_back(res);
            return;
        }
        for(size_t i=0;i<vs[u].size();++i)
        {
            res.push_back(ss.substr(u,vs[u][i]+1-u));
            dfs(vs[u][i]+1,res);
            res.pop_back();
        }
    }
};

class Solution_BFS{
    public:
    vector<vector<string> > partition(string s) {
        int n = s.size();
        vector<vector<int> > vs(n);
        int p,q;
        for(int i=0;i<n;++i){
            p=i-1;q=i+1;
            vs[i].push_back(i);
            while(p>=0 && q<n && s[p]==s[q]){
               vs[p].push_back(q);
               --p;++q;
            }
        }
        for(int i=0;i<n-1;++i){
            p=i;q=i+1;
            while(p>=0 && q<n && s[p] == s[q]){
                vs[p].push_back(q);
                --p;++q;
            }
        }
        queue<vector<int> > Q;
        Q.push(vector<int>({0}));
        vector<int> now;
        vector<vector<string> > ans;
        int u;
        while(!Q.empty()){
            now = Q.front();
            Q.pop();
            u = now[now.size()-1];
            if(u == s.size()){
                vector<string> tmp_ans;
                for(int i=0;i<now.size()-1;++i){ 
                    tmp_ans.push_back(s.substr(now[i],now[i+1]-now[i]));
                }
                ans.push_back(tmp_ans);
                continue;
            }
            for(int i=0;i<vs[u].size();++i){
                vector<int> next = now;
                next.push_back(vs[u][i]+1);
                Q.push(next);
            }
        }
        return ans;
    }
};
class Solution_recursive {
public:
    vector<vector<string> > partition(string s) {
        int n = s.size();
        vector<vector<int> > vs(n);
        int p,q;
        for(int i=0;i<n;++i){
            p=i-1;q=i+1;
            vs[i].push_back(i);
            while(p>=0 && q<n && s[p]==s[q]){
               vs[p].push_back(q);
               --p;++q;
            }
        }
        for(int i=0;i<n-1;++i){
            p=i;q=i+1;
            while(p>=0 && q<n && s[p] == s[q]){
                vs[p].push_back(q);
                --p;++q;
            }
        }
        return recursive(vs,s,0);
    }
    vector<vector<string> > recursive(const vector<vector<int> > &vs,const string &s,int now){
        vector<vector<string> > ans;
        for(size_t i=0;i<vs[now].size();++i){
            string now_s = s.substr(now,vs[now][i]-now+1);
            if(vs[now][i] + 1 == s.size()) {
                vector<string> tmp;
                tmp.push_back(now_s);
                ans.push_back(tmp);
                continue;
            }
            vector<vector<string> > tmp_ans = recursive(vs,s,vs[now][i]+1);
            for(size_t j=0;j<tmp_ans.size();++j){
                vector<string> tmp;
                tmp.push_back(now_s);
                for(size_t k=0;k<tmp_ans[j].size();++k){
                   tmp.push_back(tmp_ans[j][k]);
                }
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};
int main(){
    Solution sol;
    vector<vector<string> > ans = sol.partition("aba");
    cout<<"======="<<endl;
    for(int i = 0;i<ans.size();++i)
    {
        for(int j=0;j<ans[i].size();++j) cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
