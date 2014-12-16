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
    int singleNumber(int A[], int n) { // 00 -> 10 -> 01 -> 00 
       int ones = 0,twos = 0 ;
       for(int i=0;i<n;++i){
        ones = ones ^ A[i] & ~twos;
        twos = twos ^ A[i] & ~ones;
       }
       return ones;
    }
};

class Solution_ugly {
public:
    int singleNumber(int A[], int n) {
        int a[32];
        memset(a,0,sizeof(a));
        long long x;
        int cnt = 0;
        for(int i=0;i<n;++i){
           x = A[i];
           if(x<0){
               ++a[31];
               x=-x;
           }
           cnt = 0;
          while(x){
              a[cnt++]+=(x&1);
              x>>=1;
          }
        }
        for(int i=0;i<32;++i){
            a[i]%=3;
        }
        int ans = 0;
        for(int i=30;i>=0;--i)
        {
            ans = (ans<<1)+a[i];
        }
        if(ans == 0 && a[31]){
            return -2147483648; //1000.....0
        }
        if(a[31])ans*=-1;
        return ans;
    }
};
int main()
{
    Solution sol;
    int A[] = {-1,-2147483648,-2147483648,-2147483648,-1,-1,0,0,0,-2147483648};
    cout<<sol.singleNumber(A,10)<<endl;
	return 0;
}


