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
    string multiply(string num1, string num2) {
        int res[num1.size() + num2.size()+1];
        memset(res,0,sizeof(res));
        int c,tmp,k;
        for(int i=num1.size()-1;i>=0;--i){
            c = 0;
            k = num1.size()-1-i;
            for(int j=num2.size()-1;j>=0;--j,++k){
                tmp =  (num1[i]-'0') * (num2[j]-'0') + c + res[k];
                res[k] = tmp%10;
                c = tmp/10;
            }
            while(c){
                tmp = res[k] + c;
                res[k] = tmp%10;
                c = tmp/10;
                ++k;
            }
        }
        string ans(k,'0');
        int i;
        for(i=k-1;i>=0 && res[i] ==0;--i);
        if(i<0)return "0";
        for(;i>=0;--i){
            ans[k-i-1] = res[i]  + '0';
        }
        return ans;

    }
};
int main()
{
    Solution sol;
    cout<<sol.multiply("22","5")<<endl;
    return 0;
}


