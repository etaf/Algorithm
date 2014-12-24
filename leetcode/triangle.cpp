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
    int minimumTotal(vector<vector<int> > &triangle) {
        int m = triangle.size();
        for(int i=1;i<m;++i){
            triangle[i][0] += triangle[i-1][0];
            triangle[i][triangle[i].size()-1] += triangle[i-1][triangle[i-1].size()-1];
            for(int j=1;j<triangle[i].size()-1;++j){
                triangle[i][j] += min(triangle[i-1][j],triangle[i-1][j-1]);
            }
        }

        int ans = INT_MAX;
        for(int j=0;j<triangle[m-1].size();++j) ans = min(ans,triangle[m-1][j]);
        return ans;
    }

};
int main()
{
    Solution sol;
    vector<vector<int> > triangle({{2},{3,4},{6,5,7},{4,1,8,3}});
    cout<<sol.minimumTotal(triangle)<<endl;
	return 0;
}


