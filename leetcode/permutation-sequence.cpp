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
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        if(k == 0) return "";
        string ans;
        int f[10];
        f[1] = 1;
        for(int i=2;i<n;++i)
            f[i] = f[i-1]*i;
        int s[10];
        for(int i=1;i<=n;++i)s[i] = i;
        int p = 1;
        while(n>1){
            p = 1;
            while(k-f[n-1]>0){
                k-= f[n-1];
                ++p;
            }
            ans.push_back(s[p]+'0');
            for(int i=1,j=1;i<=n;++i){
                if(i == p)continue;
                s[j++] = s[i];
            }
            --n;
        }
        ans.push_back(s[1]+'0');
        return ans;
    }


};

class Solution_recursive {

public:

    int f[10];

    string getPermutation(int n, int k) {
        if(k == 0) return "";
        string ans;
        f[1] = 1;
        for(int i=2;i<n;++i)
            f[i] = f[i-1]*i;
        int s[10];
        for(int i=1;i<=n;++i)s[i] = i;
        return dfs(n,k,s);
    }
    string dfs(int n,int k,int* s){
        string ans;
        if(n == 1){ ans.push_back(s[1]+'0'); return ans;
        }
        int i = 1;
        while(k-f[n-1]>0){
            k-=f[n-1];
            ++i;
        }
        char c = s[i] + '0';
        for(int j=1,p=1;j<=n;++j)
        {
            if(j==i){continue;}
            s[p++] = s[j];
        }
        ans.push_back(c);
        return ans + dfs(n-1,k,s);
    }


};

void test(){

    int n = 2,k=1;
    Solution sol;
    cout<<sol.getPermutation(n,k);
}
int main()
{
    test();
	return 0;
}


