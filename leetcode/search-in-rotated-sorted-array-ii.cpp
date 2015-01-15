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
class Solution { //bsearch
public:
    bool search(int A[], int n, int target) {
        return bs(A,0,n,target);
    }
    bool bs(int*A,int l ,int r, int target)
    {
        if(l+1>=r){
            return A[l] == target;
        }
        int mid = (l+r)>>1;
        if(A[mid] == target) return true;
        if(A[mid]>target){
            if(A[mid] > A[0]){
                if(target >= A[0]) return bs(A,l,mid,target);
                else return bs(A,mid,r,target);
            }else if(A[mid]<A[0]){
                return bs(A,l,mid,target);
            }
            else{
                return bs(A,l,mid,target) || bs(A,mid,r,target);
            }
        }else{
            if(A[mid]>A[0]){
                return bs(A,mid,r,target);
            }else if(A[mid] < A[0]){
                if(target >= A[0])
                    return bs(A,l,mid,target);
                else return bs(A,mid,r,target);
            }else{
                return bs(A,l,mid,target) ||  bs(A,mid,r,target);
            }
        }
    }

};
int main()
{
    Solution sol;
    int A[] = {1,1,3};
    cout<<sol.search(A,3,3)<<endl;
    return 0;
}


