#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<unordered_map>
using namespace std;
class Solution{
    public:
        string fractionToDecimal(int numerator, int denominator) {
            if(numerator == 0) return "0";
            string ans = "";
            int sig = 1;
            long long nu = numerator,de = denominator;
            if(nu<0)sig*=-1, nu  = -nu;
            if(de<0)sig*=-1, de = -de;
            if(sig == -1) ans.push_back('-');
            long long d = nu/ de;
            long long rest = nu % de;
            unordered_map<long long,int> rests;
            rests[rest] = 0;
            long long  now = rest;
            int cnt = 1;
            ans.append(to_string(d));
            if(rest == 0)return ans;
            ans.push_back('.');
            while(rest)
            {
                now*=10;
                d = now / de;
                rest = now % de;
                ans.push_back(d+'0');
                if(rests.find(rest)!=rests.end())
                {
                    int l = cnt -  rests[rest];
                    int start = ans.size()-l;
                    string tmp = ans.substr(start,l);
                    ans.push_back(')');
                    ans.push_back(')');
                    ans[start] = '(';
                    for(int i=0;i<l;++i)ans[start+1+i] = tmp[i];
                    break;
                }
                else {
                    rests[rest] = cnt++;
                }
                now = rest;
            }
            return ans;
        }
};
int main(){
    Solution sol;
    cout<<sol.fractionToDecimal(-1,-2147483648)<<endl;
    return 0;
}
