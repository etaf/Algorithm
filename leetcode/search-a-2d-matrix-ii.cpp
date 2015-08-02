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

class Solution{
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if(matrix.empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int x=0, y= n-1;
        while(x<m && y>=0){
            //cout<<matrix[x][y]<<endl;
            if(matrix[x][y] == target) return true;
            if(matrix[x][y] < target) ++x;
            else --y;
        }
        return false;
    }
};
class Solution_1d_bsearch_TLE {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto row : matrix){
            auto it = lower_bound(row.begin(), row.end(), target);
            if(it != row.end() && *it == target) return true;
        }
        return false;
    }
};
class Solution_2d_bsearch {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        return bsearch(matrix,0,0, matrix.size(), matrix[0].size(), target);
    }
    bool bsearch(vector<vector<int> >& matrix, int x1, int y1, int x2, int y2, int target){
        if(x2-x1<2 && y2-y1<2){
            //cout<<x1<<"-"<<y1<<endl;
            return matrix[x1][y1] == target;
        }
        int mx = (x1+x2) >> 1;
        int my = (y1+y2) >> 1;
        //cout<<"mid:" <<matrix[mx][my]<<" "<<"<"<<x1<<","<<y1<<">"<<" <"<<x2<<","<<y2<<">"<<endl;
        //if(matrix[mx][my] == target) return true;
        if(matrix[mx][my] > target){
            if(bsearch(matrix, x1, y1, mx, my, target)) return true;
            if(target >= matrix[mx][y1] && bsearch(matrix, mx,y1, x2, my, target)) return true;
            if(target >= matrix[x1][my] && bsearch(matrix, x1, my, mx, y2, target)) return true;
        }
        else{
            //cout<<"!!!"<<matrix[mx][my]<<endl;
            if(bsearch(matrix,  mx, my, x2, y2, target)) return true;
            if( (my-1>=0 && target<= matrix[x2-1][my-1]) && (mx+1<x2&& bsearch(matrix, mx+1,y1, x2, my, target))) return true;
            if( ( mx-1>=0 && target<=matrix[mx-1][y2-1]) && (my+1<y2 && bsearch(matrix, x1, my+1, mx, y2, target))) return true;

        }
        return false;
    }
};
int main()
{
    Solution sol;
    vector<vector<int> > matrix;
    matrix.push_back({1,4,7,11,15});
    matrix.push_back({2,   5,  8, 12, 19});
    matrix.push_back({3,   6,  9, 16, 22});
    matrix.push_back({10, 13, 14, 17, 24});
    matrix.push_back({18, 21, 23, 26, 30});
    cout<<sol.searchMatrix(matrix, 3)<<endl;
    cout<<sol.searchMatrix(matrix, 5)<<endl;
    cout<<sol.searchMatrix(matrix, 20)<<endl;
    cout<<sol.searchMatrix(matrix, 50)<<endl;
    return 0;
}


