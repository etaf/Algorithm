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
class Solution_old { //find the min num which seperate two sorted array, then find int the two array
public:
    int search(int A[], int n, int target) {
        int u = findMin(A,n);
        int p = lower_bound(A+u,A+n,target)-A;
        if(p!= n && A[p]==target) return p;
        int q = lower_bound(A,A+u,target)-A;
        if(q!=n && A[q] == target) return q;
        return -1;
    }
    int findMin(int num[],int n) {
        int l=0,r = n;
        int mid;
        while(r-l>0){
            mid = (l+r) >> 1;
            if(mid>0 && num[mid]<num[mid-1])return mid;
            if(num[mid] > num[0])
            {
                l = mid + 1;
            }
            else
                r = mid;
        }
        return 0;
    }

};
class Solution { //bsearch
public:
    int search(int A[], int n, int target) {
        int l =0, r = n, mid;
        while(l+1<r){
            mid = (l+r)>>1;
            if(A[mid] > target){
                if(A[mid]<A[0]) r = mid;
                else{
                    if(A[0]>target) l=mid;
                    else r = mid;
                }
            }else {
                if(A[mid] >= A[0])l=mid;
                else{
                    if(A[0]>target){
                        l = mid;
                    }else{
                        r = mid;
                    }
                }
            }
        }
        return A[l] == target ? l : -1;
    }

};
int main()
{
    Solution sol;
    int A[] = {4,5,6,7,0,1,2};
    cout<<sol.search(A,7,3)<<endl;
    return 0;
}


