#include<iostream>
#include<limits.h>
#include<queue>
#include<cstring>
using namespace std;
class Solution_TLE {
public:
    int jump(int A[], int n) {
        int *dp = new int[n];
        for(int i=0;i<n;++i)dp[i] = INT_MAX;
        dp[0] = 0;
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<=i+A[i] && j<n;++j)
                dp[j] = min(dp[i]+1,dp[j]);
        }
        return dp[n-1];
    }
};

class Solution_48ms {
public:
    int jump(int A[], int n) {
        int *dp = new int[n];
        memset(dp,-1,sizeof(int)*n);
        dp[0] = 0;
        for(int i=0;i<n-1;++i){
            if(A[i]+i >= n-1)
                return dp[i]+1;
            for(int j=min(A[i]+i,n-1);j>=1+i && j<n;--j){
                if(dp[j]!=-1)break;
                dp[j] = dp[i]+1;
            }
        }
        return dp[n-1];
    }
};
class Solution { // optimized  O(n) time O(1) space
public:
    int jump(int A[], int n) {
        int maxn = A[0],ans = 0,nextn = 0;
        int i = 0;
        while(i<n-1){
            ++ans;
            if(maxn >=n-1)return ans;
            for(int j=i;j<=maxn;++j){
                nextn = max(nextn,A[j]+j);
           }
            i = maxn;
            maxn = nextn;
        }
        return ans;
    }
};
int main(){
    int a[] = {1,1,1};
    Solution sol;
    cout<<sol.jump(a,3)<<endl;
    return 0;
}
