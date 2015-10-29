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
    bool canFinish(int numCourses, vector<pair<int,int> >& prerequisites) {
        bool visited[numCourses];
        bool checked[numCourses];
        unordered_set<int> S[numCourses];
        memset(visited,0,sizeof(visited));
        memset(checked, 0, sizeof(checked));
        for(unsigned int i=0;i<prerequisites.size();++i){
            S[prerequisites[i].second].insert(prerequisites[i].first);
        }

        for(int i=0; i<numCourses; ++i){
            if(!checked[i]){
                visited[i] = true;
                checked[i] = true;
                if(dfs(i,S,checked, visited)) return false;
                visited[i] = false;
            }
        }
        return true;
    }
    bool dfs(int u, unordered_set<int>* S,bool* checked, bool* visited){
        for(auto it = S[u].begin(); it != S[u].end(); ++it){
            if(visited[*it] ) return true;
            if(!checked[*it]){
                checked[*it] = true;
                visited[*it] = true;
                if(dfs(*it,S,checked, visited)) return true;
                visited[*it] = false;
            }
        }
        return false;
    }

};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    vector<pair<int,int> > ps = {{5,8},{3,5},{1,9},{4,5},{0,2},{1,9},{7,8},{4,9}};
    vector<pair<int,int > > ps2 = {{0,1},{3,1},{1,3},{3,2}};
    cout<<sol.canFinish(10,ps)<<endl;
    cout<<sol.canFinish(4,ps2)<<endl;
    return 0;
}


