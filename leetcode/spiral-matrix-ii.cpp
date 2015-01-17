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
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n,vector<int>(n));
        if(n == 0) return matrix;
        int now = 0;
        for(int k=0;k<n/2;++k){
            //start from (k,k)
            int len = n-1-k-k;
            for(int j=k;j<k+len;++j){
                matrix[k][j] = ++now;
            }
            for(int i=k;i<k+len;++i){
                matrix[i][k+len] = ++now;
            }
            for(int j=k+len;j>k;--j){
                matrix[k+len][j] = ++now;
            }
            for(int i=k+len;i>k;--i){
                matrix[i][k] = ++now;
            }
        }
        if(n&1)matrix[n/2][n/2] = ++now;
        return matrix;
    }
};

void test(){
    Solution sol;
    vector<vector<int> > ans = sol.generateMatrix(0);
    for(int i=0;i<ans.size();++i){
        for(int j= 0;j<ans[0].size();++j){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    test();

	return 0;
}


