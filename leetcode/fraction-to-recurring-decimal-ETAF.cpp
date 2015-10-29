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
    string fractionToDecimal(int numerator, int denominator) {
        string ans;
        long long nn = numerator, dd = denominator;
        if(nn*dd < 0){
            ans.push_back('-');
        }
        nn = nn > 0 ? nn : -nn;
        dd = dd > 0 ? dd : -dd;

        ans+=to_string(nn/dd);
        if(nn%dd){
            ans.push_back('.');
        }
        nn %= dd;
        unordered_set<long long> S;
        long long nn_bk = nn, rec=-1;
        string ans_bk = ans;
        while(nn){
            if(S.find(nn) != S.end()){
                //get len
                rec = nn;
                break;
            }
            else{
                S.insert(nn);
            }
            nn*=10;
  /*          while(nn < dd){*/
                //nn*=10;
                //ans.push_back('0');
            /*}*/


            ans += to_string(nn/dd);
            nn %= dd;
        }
        if(rec!=-1){
            ans = ans_bk;
            nn = nn_bk;
            bool start_f = false;
            while(nn){
                if(nn == rec){
                    if(start_f == false){
                        start_f = true;
                        ans.push_back('(');
                    }else{
                        ans.push_back(')');
                        break;
                    }
                }
                nn*=10;
/*                while(nn<dd){*/
                    //nn*=10;
                    //ans.push_back('0');
                /*}*/

                ans += to_string(nn/dd);
                nn %= dd;
            }
        }
        return ans;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;

    cout<<sol.fractionToDecimal(-1,2)<<endl;
    cout<<sol.fractionToDecimal(1,5)<<endl;
    cout<<sol.fractionToDecimal(-2,3)<<endl;
    cout<<sol.fractionToDecimal(1,3)<<endl;
    cout<<sol.fractionToDecimal(10,3)<<endl;
    cout<<sol.fractionToDecimal(1,90)<<endl;
    cout<<sol.fractionToDecimal(1,99)<<endl;
    cout<<sol.fractionToDecimal(-1,-2147483648)<<endl;
    return 0;
}


