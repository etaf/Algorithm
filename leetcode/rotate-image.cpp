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
    void rotate(vector<vector<int>>& matrix) { //inplace 
       int n = matrix.size();
       int mid = n>>1;
       int ii,jj,ni,nj;
       for(int i=0; i<mid; ++i){
           for(int j=0; j<mid +(n&1); ++j){
               ii = i;
               jj = j;
               for(int k=0; k<3; ++k){
                   ni = jj;
                   nj = n-1-ii;
                   std::swap(matrix[i][j], matrix[ni][nj]);
                   ii = ni;
                   jj = nj;
               }
           }
       }

    }
};
int main()
{
    std::ios::sync_with_stdio(false);

    //vector<vector<int> > M({{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}});
    //vector<vector<int> > M({{1,2,3},{4,5,6},{7,8,9}});
    Solution sol;
    for(int i=0; i<M.size(); ++i){
        for(int j=0; j<M[0].size(); ++j){
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<" =============="<<endl;
    sol.rotate(M);
    for(int i=0; i<M.size(); ++i){
        for(int j=0; j<M[0].size(); ++j){
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


