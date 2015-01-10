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
class Solution { // DP的思想，第i个时，前i个是正确的数字表示
public:
    bool isNumber(const char *s) {
        bool fe = false;
        bool fp = false;
        int start = 0;
        int end = strlen(s);
        for(start =0;start<end && s[start] == ' '; ++start);
        if(s[start] == '-' || s[start] == '+') ++start;
        if(start == end)return false;

        for(--end;end>=start && s[end] == ' '; --end);
        ++end;
        if(end == start)return false;
        if(start + 1 == end){
            return s[start] <= '9' && s[start]>='0';
        }
        for(int i=start;i<end;++i){
            if(s[i] <= '9' && s[i] >= '0'){
                continue;
            }
            if(s[i] == '+' || s[i] == '-'){
                if(s[i-1] != 'e')return false;
                continue;
            }
            if(s[i] == '.'){
                if(fp || fe ) return false;
                fp = true;
                continue;
            }
            if(s[i] == 'e'){
                if(fe)return false;
                fe  = true;
                if(i==start  ||(s[i-1] == '.' && i-1 == start))return false;
                continue;
            }
            return false;
        }
        if((s[end-1] <='9' && s[end-1]>='0') || (s[end-1] == '.' && end-start>1 ) )return true;
        return false;
    }
};
int main()
{
    Solution sol;
    char s[] = " . 1 ";
    //char s[] = " -1.e-1 ";
    //char s[] = " 0e ";
    cout<<sol.isNumber(s)<<endl;
    return 0;
}


