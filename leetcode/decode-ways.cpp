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
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0') return 0;
       int a=1,b=1,c=1;
        for(size_t i=1;i<s.size();++i){
            if(s[i] == '0')
            {
                if(s[i-1]=='1' || s[i-1] == '2')
                    c = a;
                else return 0;
            }
            else if( (s[i-1] == '2' && s[i] <='6') || (s[i-1] == '1'))c =b + a;
            else c = b;
            a = b;
            b = c;
        }
        return c;
    }
};
int main()
{
    Solution sol;
    cout<<sol.numDecodings("17")<<endl;
    return 0;
}


