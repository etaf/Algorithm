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
        double findMedianSortedArrays(int A[], int m, int B[], int n) {
            if(m>n)return findMedianSortedArrays(B,n,A,m);
            int l =0,r = min(n,m), midA,midB;
            int k = (n+m-1)/2;
            if(m == 0 ) return (n&1 ? B[k]: (B[k] + B[k+1])*0.5);
            while(l+1<r){
                midA = (l+r)>>1;
                midB = k-midA;
                //if(A[midA] == B[midB]) return (double) A[midA];
                if(A[midA] > B[midB])
                {
                    r = midA;
                }else{
                    l = midA;
                }
            }
            //cout<<k<<"-"<<l<<endl;
            if((n+m)&1){
                if(A[l] > B[k-l] ) return B[k];
                if(k-l>0 ){
                    if( A[l]<B[k-l-1])return B[k-l-1];
                    return  A[l];
                }
                return 0;
            }else{
                if(l+1<m && A[l+1]<B[k-l]) return (max(k-l-1>=0?B[k-l-1]:0,A[l])+A[l+1])*0.5;
                if(k-l>0 && A[l]<B[k-l-1]) return (B[k-l-1]+B[k-l])*0.5;
                if(k-l+1<n && A[l]>B[k-l+1]) return (B[k-l] + B[k-l+1]) * 0.5;
                return (A[l]+B[k-l])*0.5;
            }
        }
};
int main()
{
    Solution sol;
    int A[] = {1,3};
    int B[] = {2,4};
    cout<<sol.findMedianSortedArrays(A,2,B,2)<<endl;
    return 0;
}


