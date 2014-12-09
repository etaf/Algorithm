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
using namespace std;

class Solution {
public:
    int maxProduct(int A[], int n) {
        if(n==0)return 0;
        int dp[100010][2];
        dp[0][0] = dp[0][1] = A[0];
        int ans  = A[0];
        for(int i=1;i<n;++i){
            dp[i][0] = max(A[i],max(dp[i-1][0]*A[i],dp[i-1][1]*A[i]));
            dp[i][1] = min(A[i],min(dp[i-1][0]*A[i],dp[i-1][1]*A[i]));
            ans = max(ans,dp[i][0]);
        }
        return ans;
    }
};
void test(){
    int a[] = {2,3,-2,-4};
    Solution sol;
    cout<<sol.maxProduct(a,4)<<endl;

}
int main()
{
    test();
	return 0;
}


