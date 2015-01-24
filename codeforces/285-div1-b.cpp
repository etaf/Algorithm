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

class Solution_TLE{
    public:
    int sums[64];
    vector<int> get_perm(int n,int order){
       
        vector<int> ans(n);
        int f[n];
        for(int i=0;i<n;++i)f[i] = i;
        int flen = n;
        int cnt = 0;
        int k;
        for(int i=n-1;i>=0;--i){
            k = order/sums[i];
            order%=sums[i];
            ans[cnt++] = f[k];
            for(int j=k;j<flen-1;++j){
                f[j] = f[j+1];
            }
            --flen;
        }
        return ans;
    }
    int get_order(int n,int A[])
    {
        int order = 0;
        int k=0;
        int f[n];
        for(int i=0;i<n;++i)f[i] = i;
        int flen = n;

        for(int i=0;i<n;++i){
            k=0;
            for(int j=0;j<flen && f[j]<A[i];++j,++k);
            order += k*sums[n-i-1];
            for(int j=k;j<flen-1;++j){
                f[j] = f[j+1];
            }
            --flen;
        }
        return order;
    }
    void solve(){
        int n;
        cin>>n;

        sums[0] = 1;
        for(int i=1;i<=n;++i){
            sums[i] = sums[i-1]*i;
        }

        int p[n],q[n];
        for(int i=0;i<n;++i)cin>>p[i];
        for(int j=0;j<n;++j)cin>>q[j];
        int op = get_order(n,p);
        int oq = get_order(n,q);
        vector<int> ans = get_perm(n,(op+oq)%sums[n]);
        cout<<ans[0];
        for(int i=1;i<ans.size();++i)
            cout<<" "<<ans[i];
        cout<<endl;
    }
};
int main()
{

    ios::sync_with_stdio(false);
    Solution sol;
    sol.solve();
    return 0;
}
