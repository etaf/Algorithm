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
class Solution { //stack
public:
    int m,n;
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty())return 0;
        m = matrix.size();
        n = matrix[0].size();
        int p[1010];
        memset(p,0,sizeof(p));
        int ans = 0;
        for(int i=m-1;i>=0;--i){
            for(int j=0;j<n;++j){
                if(matrix[i][j] == '0')p[j] = 0;
                else p[j]+=1;
            }
            ans = max(ans,monotonic_stack(p));
        }
        return ans;
    }
private:
    int monotonic_stack (int *p){
        /*cout<<"======="<<endl;*/
        //for(int i=0;i<n;++i)
            //cout<<p[i]<<" ";
        /*cout<<endl;*/
        int st[1010];
        int cnt = 0;
        st[cnt++] = 0;
        int ans = 0;
        for(int i=1;i<n;++i){
            if(p[i] >= p[st[cnt-1]]) st[cnt++] = i;
            else{
                int r = st[cnt-1];
                while(cnt && p[i]<=p[st[cnt-1]]){
                    --cnt;
                    ans = max(ans,p[st[cnt]] * (r- ( cnt ? st[cnt-1] : -1)));
                }
                st[cnt++]=i;
            }

        }

        if(cnt>0){
            int r= st[cnt-1];
            while(cnt){
                --cnt;
                ans = max(ans,p[st[cnt]] * (r-(cnt? st[cnt-1]:-1)));
            }
        }
        return ans;
    }
};

class Solution_dp { //dp
public:
    int m,n;
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty())return 0;
        m = matrix.size();
        n = matrix[0].size();
        int p[1010];
        memset(p,0,sizeof(p));
        int ans = 0;
        for(int i=m-1;i>=0;--i){
            for(int j=0;j<n;++j){
                if(matrix[i][j] == '0')p[j] = 0;
                else p[j]+=1;
            }
            ans = max(ans,oned(p));
        }
        return ans;
    }
private:
    int oned(int *p){
        int maxn;
        int l[1010],r[1010];
        for(int i=0;i<n;++i){
            l[i] = i;
            while( l[i] > 0 && p[l[i]-1] >= p[i] ) l[i] = l[l[i]-1];
        }
        for(int i=n-1;i>=0;--i){
            r[i] = i;
            while(r[i]<n-1 && p[r[i]+1] >= p[i]) r[i] = r[r[i]+1];
        }
        maxn = 0;
        for(int i=0;i<n;++i){
            maxn = max(maxn,p[i]*(r[i]-l[i]+1));
        }
        return maxn;
    }
};
int main()
{
    Solution sol;
    vector<vector<char> > M({{'0','1','1'},{'1','1','0'},{'1','1','1'}});
    //vector<vector<char> > M({{'1','1','1'}});
    cout<<sol.maximalRectangle(M)<<endl;
    return 0;
}


