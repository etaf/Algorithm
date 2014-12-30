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
    int trap(int A[], int n) { //  monotone decreasing stack
        int *st = new int[n];
        int *sum = new int[n+1];

        sum[0]=0;
        for(int i=1;i<=n;++i)
            sum[i]=sum[i-1] + A[i-1];
        int cnt = 0;
        int ans = 0;
        int l,r;
        for(int i=0;i<n;++i){
            if(cnt>0 && A[st[cnt-1]]<A[i]){
                r = i;
                while(cnt && A[st[cnt-1]]<A[i])
                {
                    --cnt;
                }
                if(cnt == 0){
                    l = st[0];
                    ans += (r-l)*A[l] -(sum[r]-sum[l]);
                }
            }
            st[cnt++] = i;
            /*for(int i=0;i<cnt;++i)cout<<A[st[i]]<<" ";*/
            /*cout<<endl;*/
        }
        while(cnt>1){
            r = st[cnt-1];
            l = st[cnt-2];
            if(r-l>1)
                ans += (r-l)*A[r] - (sum[r+1]-sum[l+1]);
            --cnt;
        }
        return ans;

    }
};
int main()
{
    Solution sol;
    //int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int a[] = {5,8,1};
    cout<<sol.trap(a,3)<<endl;
    return 0;
}


