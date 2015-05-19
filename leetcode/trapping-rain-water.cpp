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
class Solution_stack {
public:
    int trap(vector<int>& height) { //  monotone decreasing stack
        int n = height.size();
        int st[n];
        int sum[n+1];

        sum[0]=0;
        for(int i=1;i<=n;++i)
            sum[i]=sum[i-1] + height[i-1];
        int cnt = 0;
        int ans = 0;
        int l,r;
        for(int i=0;i<n;++i){
            if(cnt>0 && height[st[cnt-1]]<height[i]){
                r = i;
                while(cnt && height[st[cnt-1]]<height[i])
                {
                    --cnt;
                }
                if(cnt == 0){
                    l = st[0];
                    ans += (r-l)*height[l] -(sum[r]-sum[l]);
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
                ans += (r-l)*height[r] - (sum[r+1]-sum[l+1]);
            --cnt;
        }
        return ans;

    }
};
class Solution_WA { // it's wrong that find two peak, the case {5,2,1,2,1,5} can prove it.
public:
    int trap(vector<int>& height) {
        int p = 0, q = 0, n = height.size();
        while(p+1<n && height[p+1]>=height[p]) ++p;
        q = p+1;
        int ans = 0;
        while(q<n){
            while(q+1<n && height[q+1]<=height[q]) ++q;
            while(q+1<n && height[q+1]>=height[q]) ++q;
            int h = min(height[p],height[q]);
            cout<<p<<"-"<<q<<endl;
            for(int i=p+1;i<q;++i){
                ans += max(0,h-height[i]);
            }
            p = q;
            ++q;
        }
        return ans;
    }
};
class Solution_two_boarder {
public:
    int trap(vector<int>& height) {
        int ans = 0, n = height.size();
        if(n == 0) return 0;
        int l[n],r[n];
        l[0] = height[0];
        r[n-1] = height[n-1];
        for(int i=1; i<n; ++i) l[i] = max(l[i-1], height[i]);
        for(int i=n-2; i>=0; --i) r[i] = max(r[i+1], height[i]);
        for(int i=0; i<n; ++i){
            ans += min(l[i],r[i]) - height[i];
        }
        return ans;
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, n = height.size();
        int st[n], top=0;
        int sum[n+1];
        sum[0]=0;
        for(int i=1;i<=n;++i)
            sum[i]=sum[i-1] + height[i-1];

        for(int i=0; i<n; ++i){
            if(!top) st[top++] = i;
            else{
                while(top && height[st[top-1]] < height[i]) --top;
                if(!top){
                    ans += (i - st[0] - 1) * height[st[0]] - sum[i] + sum[st[0]+1];
                }
                st[top++] = i;
            }
        }
        int l,r;
        while(top>1){
            r = st[top-1];
            l = st[top-2];
            ans += (r-l-1)* height[r] - sum[r] + sum[l+1];
            --top;
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    //int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    //vector<int> a =  {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> a =  {5,2,1,2,1,5};
    cout<<sol.trap(a)<<endl;
    return 0;
}


