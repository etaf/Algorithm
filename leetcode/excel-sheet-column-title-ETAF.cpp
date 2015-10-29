
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

typedef long long llong;
class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n){
            if(n%26==0){
                res.push_back('Z');
                n/=26;
                --n;
            }else{
                res.push_back('A' + n%26 - 1);
                n/=26;
            }
        }
        std::reverse(res.begin(),res.end());
        return res;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    cout<<sol.convertToTitle(78)<<endl;
    return 0;
}


