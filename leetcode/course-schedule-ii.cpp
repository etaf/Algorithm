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
    bool visited[2048];
    bool checked[2048];
    bool nst[2048];
    vector<int> path;
    unordered_set<int> S[2048];
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(!canFinish(numCourses, prerequisites)) return  path;
        memset(checked,0,sizeof(checked));
        for(int i = 0; i < numCourses; ++i){
            if(!nst[i]){
                find_path(i);
                path.emplace_back(i);
            }
        }
        return path;

    }
    void find_path(int u){
        for(auto it = S[u].begin(); it!=S[u].end(); ++it){
            if(!checked[*it]){
                checked[*it] = true;
                find_path(*it);
                path.emplace_back(*it);
            }
        }
    }
    bool canFinish(int numCourses, vector<pair<int,int> >& prerequisites) {
        memset(visited,0,sizeof(visited));
        memset(checked, 0, sizeof(checked));
        memset(nst,0,sizeof(nst));
        for(unsigned int i=0;i<prerequisites.size();++i){
            S[prerequisites[i].first].insert(prerequisites[i].second);
            nst[prerequisites[i].second] = true;
        }
        for(int i=0; i<numCourses; ++i){
            if(!checked[i]){
                visited[i] = true;
                checked[i] = true;
                if(dfs(i)) return false;
                visited[i] = false;
            }
        }
        return true;
    }
    bool dfs(int u){
        for(auto it = S[u].begin(); it != S[u].end(); ++it){
            if(visited[*it] ) return true;
            if(!checked[*it]){
                checked[*it] = true;
                visited[*it] = true;
                if(dfs(*it)) return true;
                visited[*it] = false;
            }
        }
        return false;
    }

};
int main()
{
    Solution sol;
    vector<pair<int,int > > ps = {{0,1},{0,2},{1,3},{2,3}};
    vector<int> ans = sol.findOrder(6,ps);
    for(int i=0; i < ans.size(); ++i){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
        return 0;
}


