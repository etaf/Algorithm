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
    vector<int> searchRange(int A[], int n, int target) {
        int l = 0,r=n,mid;
        while(l+1<r){
            mid = (l+r)>>1;
            if(target < A[mid])r=mid;
            else l = mid;
        }
        if(A[l] != target) return {-1,-1};
        int res_r = l;
        r = l,l = -1;
        while(l+1<r){
            mid = (l+r)>>1;
            if(target > A[mid]) l = mid;
            else r = mid;
        }
        return {r,res_r};
    }
};
class Solution_stl {
public:
    vector<int> searchrange(int a[], int n, int target) {
        int l = lower_bound(a,a+n,target) - a;
        if(a[l] != target)return {-1,-1};
        int r = upper_bound(a,a+n,target) - a;
        return vector<int>({l,r-1});
    }
};
int main()
{
    Solution sol;
    int A[] = {5, 7, 7, 8, 8, 10};
    vector<int> ans = sol.searchRange(A,6,7);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}


