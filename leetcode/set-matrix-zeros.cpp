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
class Solution { //inplace
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int col0 = 1;
        for(int i=0;i<n;++i){
            if(matrix[i][0] == 0) col0 = 0;
            for(int j=1;j<m;++j){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=n-1;i>=0;--i){
            for(int j=m-1;j>0;--j){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
            if(col0 ==0){
                matrix[i][0] = 0;
            }
        }
    }
};
class Solution_old { //inplace
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool r=false,c=false;
        for(int i=0;i<n;++i){
            if(matrix[i][0] == 0) {c = true ; break;}
        }
        for(int j=0;j<m;++j){
            if(matrix[0][j] == 0) {r = true; break;}
        }
        for(int i=1;i<n;++i){
            for(int j=1;j<m;++j){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=1;i<n;++i){
            if(matrix[i][0] == 0)
                for(int j=1;j<m;++j){
                    matrix[i][j] = 0;
                }
        }
        for(int j=1;j<m;++j){
            if(matrix[0][j]==0){
                for(int i=1;i<n;++i){
                    matrix[i][j] = 0;
                }
            }
        }
        if(c == true){
            for(int i=0;i<n;++i)matrix[i][0] = 0;
        }
        if(r) for(int j=0;j<m;++j)matrix[0][j] = 0;
    }
};
int main()
{
    return 0;
}


