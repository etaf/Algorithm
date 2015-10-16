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
typedef long long llong;
using namespace std;
class Solution {
public:
    string numberToWords(int num) {
        string ws[] = {"Zero", "One","Two","Three","Four", "Five", "Six", "Seven", "Eight", "Nine"};
        string wws[] = {"","","Twenty","Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty","Ninety"};
        string wwws[] = {"Ten","Eleven", "Twelve", "Thirteen", "Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        string bs[] = {"","Thousand","Million","Billion"};
        int ns[16];
        int cnt=0;
        if(!num) return "Zero";
        while(num){
            ns[cnt++] = num%1000;
            num/=1000;
        }

        string ans = "";
        string tmp;
        for(int i=cnt-1; i>=0; --i){
            tmp = get_3num(ns[i],ws,wws,wwws);
            if(tmp.size()>0){
                if(ans.size()>0){
                    ans += " ";
                }
                ans += tmp;
                if(bs[i].size()>0)
                    ans += " "+ bs[i];
            }
        }
        return ans;
    }
    string get_3num(int x,string* ws, string* wws, string* wwws){
        string res = "";
        if(x>99){
            res = ws[x/100] + " Hundred";
            x%=100;
        }
        if(x>9 && x<20){
            if(res.size()>0) res+=" ";
            res+= wwws[x-10];
            return res;
        }
        if(x>19){
            if(res.size()>0) res+=" ";
            res += wws[x/10];
            x%=10;
        }
        if(x>0){
            if(res.size()>0) res+=" ";
            res += ws[x];
        }
        return res;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    cout<<sol.numberToWords(0)<<endl;
    cout<<sol.numberToWords(10)<<endl;
    cout<<sol.numberToWords(100)<<endl;
    cout<<sol.numberToWords(1000)<<endl;
    cout<<sol.numberToWords(10000)<<endl;
    cout<<sol.numberToWords(123)<<endl;
    cout<<sol.numberToWords(12345)<<endl;
    cout<<sol.numberToWords(1234567)<<endl;
    cout<<sol.numberToWords(1123456789)<<endl;
    cout<<sol.numberToWords(1000000000)<<endl;
    return 0;
}


