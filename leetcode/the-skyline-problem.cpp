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
    vector<pair<int, int> > getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int> > ans;
        int n = buildings.size();

        if(n == 0) return ans;
        vector<pair<int,int> > lines;
        int nn = n<<1;
        lines.reserve(nn);
        for(int i=0; i<n; ++i)
        {
            lines.emplace_back(pair<int,int>(buildings[i][0],buildings[i][2]));
            lines.emplace_back(pair<int,int>(buildings[i][1],buildings[i][2]));
        }
        sort(lines.begin(),lines.end());
        stack<pair<int,int> > S;
        for(int i=0;i<nn; ++i){
            if(S.empty())
            {
                S.push(lines[i]);
            }
        }
    }
};
int main()
{
    return 0;
}


