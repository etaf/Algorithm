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
    int rob(vector<int>& num){
        if(num.empty()) return 0;
        int n = num.size();
        if(n<2) return num[0];
        return max(rob_single(num,1,n),rob_single(num,0,n-1));
    }
    int rob_single(const vector<int> &num,int start,int end) {
        unsigned int  a = 0, b =num[start];
        for(int i=start+1;i<end; ++i){
            a = max(b,a+num[i]);
            a^=b;
            b^=a;
            a^=b;
        }
        return max(a,b);
    }
};
int main()
{

    return 0;
}


