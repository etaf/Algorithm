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
using namespace std;

class Solution {

public:

    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ans;
        int m = matrix.size();
        if(m<1)return ans;
        int n = matrix[0].size();
        int** g = new int*[m];
        for(int i=0;i<m;++i)
            g[i] = new int[n];
        for(int i=0;i<m;++i)for(int j=0;j<n;++j)g[i][j] = 0;

        int ds[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int d = 0;
        int x = 0, y = 0;
        int nx,ny;
        while(1){
            if(x<0 || x>=m || y<0 || y>=n || g[x][y]) break;
            ans.push_back(matrix[x][y]);
            g[x][y] = 1;
            nx = ds[d][0] + x;
            ny = ds[d][1] + y;
            if( nx<0 || nx>=m || ny<0 || ny>=n || g[nx][ny]) d = (d+1)%4;
            x +=  ds[d][0];
            y += ds[d][1];
        }
        return ans;

    }

};
void test(){
    Solution sol;
    vector<vector<int> > m({{1}});
    //vector<vector<int> > m({{1,2,3},{4,5,6},{7,8,9}});
    //vector<vector<int> > m({{1,2,3,4},{5,6,7,8},{9,10,11,12}});
    //vector<vector<int> > m({{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}});
    vector<int>ans = sol.spiralOrder(m);
    for(int i=0;i<ans.size();++i)cout<<ans[i]<<" ";
    cout<<endl;
}
int main()
{
    test();

	return 0;
}


