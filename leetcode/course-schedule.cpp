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
    bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
        int colors[numCourses];
        unordered_set<int> S[numCourses];
        memset(colors,-1,sizeof(colors));
        for(unsigned int i=0;i<prerequisites.size();++i){
            S[prerequisites[i][0]].insert(prerequisites[i][1]);
        }
        for(int i=0;i<numCourses;++i){
            if(colors[i] == -1){
                colors[i] = i;
                if(dfs(i,i,S,colors)){
                    return false;
                }
            }
        }
        return true;
    }
    bool dfs(int u, int color, unordered_set<int>* S, int* colors){
        for(auto it = S[u].begin(); it != S[u].end(); ++it){
            if(colors[*it] == color) return true;
            if(colors[*it] == -1){
                colors[*it] = color;
                if(dfs(*it, color,S,colors)) return true;
            }
        }
        return false;
    }

};
int main()
{
    Solution sol;
    //vector<vector<int> > ps({{5,8},{3,5},{1,9},{4,5},{0,2},{1,9},{7,8},{4,9}});
    vector<vector<int> > ps;
    cout<<sol.canFinish(1,ps)<<endl;
    return 0;
}


