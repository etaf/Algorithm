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
    int calculate(string s) {
        const char* ss = s.c_str();
        int len = s.size();
        int st[len];
        int cnt = 0;
        for(int i=0; i<len; ++i){
            while(s[i] == ' ') ++i;
            if(i==len)break;
            if(s[i] >= '0' && s[i] <= '9'){
                int x = s[i]-'0';
                while(i+1<len && s[i+1]>='0' && s[i+1]<='9'){
                    ++i;
                    x = x*10 + s[i] - '0';
                }
                if(cnt>1 && (st[cnt-1] < -2))
                {
                    st[cnt-2] = st[cnt-1] == -3 ? st[cnt-2] * x : st[cnt-2]/x;
                    --cnt;
                }
                else
                {
                    st[cnt++] = x;
                }
            }else{
                if(s[i] == '+') st[cnt++] = -1;
                else if(s[i] == '-') st[cnt++] = -2;
                else if(s[i] == '*') st[cnt++] = -3;
                else st[cnt++] = -4;
            }
        }
        for(int i=1; i<cnt; i+=2){
            st[i+1] = st[i] == -1 ? st[i-1] + st[i+1] : st[i-1] - st[i+1];
        }
        return st[cnt-1];
    }
};
int main()
{
    Solution sol;
    cout<< sol.calculate(" 3 + 5 / 2 ")<<endl;
    return 0;
}


