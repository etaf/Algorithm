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
    std::ios::sync_with_stdio(false);
    Solution sol;
    vector<int> A = {1,1};
    vector<int> B = {1,2};
    cout<<sol.findMedianSortedArrays(A,B)<<endl;

    return 0;
}


