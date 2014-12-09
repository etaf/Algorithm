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
    int maxSubArray(int A[], int n) {
        if(n<1)return 0;
        int ans = A[0],sum = A[0];
        for(int i=1;i<n;++i){
            if(sum < 0) sum = A[i];
            else sum += A[i];
            ans = max(sum,ans);
        }
        return ans;
    }
};
int main()
{
	return 0;
}


