#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/*
 * [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 */
class Solution { //treat it as a sorted list not a matrix
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = n*m, mid;
        while(l+1<r){
            mid = (l+r) >> 1;
            if(matrix[mid/m][mid%m]>target) r=mid;
            else l = mid;
        }
        return (matrix[l/m][l%m] == target);
    }
};
class Solution_old {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        unsigned int i;
        for(i=0;i<matrix.size();++i){
            if(target<=matrix[i].back())
                break;
        }
        if(i==matrix.size()) return false;
        vector<int>::iterator it = lower_bound(matrix[i].begin(),matrix[i].end(),target);
        return (*it == target);
    }
};
int main(){
    Solution sol;
    vector<vector<int> > matrix({{1,3,5,7},{10,11,16,20},{23,30,34,50}});
    cout<<sol.searchMatrix(matrix,16)<<endl;
    return 0;
}
