#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<limits.h>
#include<functional>
using namespace std;

class Solution {//BFS , can also be solved by dp
public:
    vector<vector<int> > vs;
    int minCut(string s) { 
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
        vector<int> dist(n+1,INT_MAX);
        dist[0] = 0;
        queue<int> Q;
        Q.push(0);
        int u,v;
        while(!Q.empty()){
            u = Q.front();
            Q.pop();
            if(u==n)break;
            for(size_t i=0;i<vs[u].size();++i){
                v = vs[u][i]+1;
                if(dist[v] > dist[u]+1)
                {
                    dist[v] = dist[u]+1;
                    Q.push(v);
                }
            }
        }
        return dist[n]-1;
    }
};
int main(){
    Solution sol;
    cout<<sol.minCut("aalalalalalalalalalaaalala")<<endl;
    //cout<<sol.minCut("abababa")<<endl;
    return 0;
}
