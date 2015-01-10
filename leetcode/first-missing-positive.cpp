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
    int firstMissingPositive(int A[], int n) {
        for(int i=0,t;i<n;++i){
            t = i;
            while(A[t]>0 && A[t] != t+1 && A[t]<=n && A[A[t]-1]!=A[t]){
                swap(A[t],A[A[t]-1]);
            }
        }
/*        for(int i=0;i<n;++i)cout<<A[i]<<" ";*/
        /*cout<<endl;*/
        for(int i=0;i<n;++i){
            if(A[i] != i+1)return i+1;
        }
        return n+1;
    }
};
int main()
{
    Solution sol;
    int A[] = {1,1};
    cout<<sol.firstMissingPositive(A,2)<<endl;
    return 0;
}


