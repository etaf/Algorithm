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
class Solution_old {
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
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m>n)return findMedianSortedArrays(nums2,nums1);
        int l =0,r = min(n,m), midA,midB;
        int k = (n+m-1)/2;
        if(m == 0 ) return (n&1 ? nums2[k]: (nums2[k] + nums2[k+1])*0.5);
        while(l+1<r){
            midA = (l+r)>>1;
            midB = k-midA;
            if(nums1[midA] > nums2[midB])
            {
                r = midA;
            }else{
                l = midA;
            }
        }
        if((n+m)&1){
            if(nums1[l] > nums2[k-l] ) return nums2[k]; //nums1[0] > nums2[k]]
            else{
                if( nums1[l]<nums2[k-l-1])return nums2[k-l-1]; // nums1[l] <= nums2[k-l]  && nums1[l+1] < nums2[k-l]
                return  nums1[l]; //nums1[l] <= nums2[k-1] && nums[l] > nums2[k-l-1]
            }
        }else{

            if(nums1[l] > nums2[k-l]) return 0.5*(nums2[k]+ ( k+1 < n ? min(nums1[0],nums2[k+1]) : nums1[0]));
            else{
                if(k-l>0){
                    if(nums1[l] < nums2[k-l-1]){
                        return 0.5*(nums2[k-l-1] +( l+1<m ? min(nums1[l+1],nums2[k-l]) : nums2[k-l]));
                    }
                    else{
                        return 0.5*(nums1[l] + ( l+1<m ? min(nums1[l+1],nums2[k-l]) : nums2[k-l]));
                    }
                }
                else{//k==l && nums1[l] < nums2[k-l]
                    return 0.5*(nums2[k-l] + nums1[l]);
                }
            }
        }
    }
};
int main()
{
    double x = (100001+100000)*0.5;
    cout<<x<<endl;
    Solution sol;
    vector<int> A = {2,3};
    vector<int> B = {1,4};
    cout<<sol.findMedianSortedArrays(A,B)<<endl;
    return 0;
}


