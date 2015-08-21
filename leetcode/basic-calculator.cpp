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
        int len;
        int calculate(string s) {
            int ans = 0;
            len = s.size();
            int st[len], cnt=0 ;
            for(int i=len-1; i>=0; --i){
                while(i>=0 && s[i] == ' ') --i;
                if(i < 0)break;
                if(s[i] == '+'){
                    st[cnt++] = -1;
                }else if(s[i] == '-'){
                    st[cnt++] = -2;
                }else if(s[i] == ')'){
                    st[cnt++] = -3;
                }else if(s[i] == '('){
/*                    while(st[cnt-1] != -3 && st[cnt-2] != -3){*/
                        //st[cnt-3] = st[cnt-2] == -1 ? st[cnt-1] + st[cnt-3] : st[cnt-1] - st[cnt-3];
                        //cnt -= 2;
                    //}
                    //if(st[cnt-1] == -3)--cnt;
                    /*else{st[cnt-2] = st[cnt-1]; --cnt;}*/
                    while(st[cnt-2] != -3){
                        st[cnt-3] = st[cnt-2] == -1 ? st[cnt-1] + st[cnt-3] : st[cnt-1] - st[cnt-3];
                        cnt -= 2;
                    }
                    st[cnt-2] = st[cnt-1]; --cnt;

                }else{
                    int x = s[i] - '0';
                    int p10 = 10;
                    while(i-1>=0 && s[i-1] >='0' && s[i-1] <='9')
                    {

                        x +=  (s[i-1] - '0') * p10;
                        p10 *= 10;
                        --i;
                    }
                    st[cnt++] = x;
                }
            }
            while(cnt > 2){
                st[cnt-3] = st[cnt-2] == -1 ? st[cnt-1] + st[cnt-3] : st[cnt-1] - st[cnt-3];
                cnt -= 2;
            }
/*            for(int i=0; i<cnt; ++i){*/
                //cout<<st[i]<<" ";
            //}
            /*cout<<endl;*/
            return st[0];

        }
};
int main()
{
    Solution sol;
    cout<<sol.calculate("(1 + (4+ 5+ 2) -3)+ ( 6 + 8) ")<<endl;
    cout<<sol.calculate(" 2-1 + 2 ")<<endl;
    cout<<sol.calculate("2147483647")<<endl;
    return 0;
}


