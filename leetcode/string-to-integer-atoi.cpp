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
using namespace std;

class Solution {

public:

    int atoi(const char *str) {
        if(!str) return 0;
        int sig = 1;
        int i = 0;
        int n = strlen(str);
        while(str[i] && str[i]==' ')++i;
        while(n-1 > 0 && str[n-1] == ' ') --n;
        if(i>=n) return 0;

        if(str[i] == '-'){
            sig = -1;
            ++i;
        }else if(str[i] == '+')
        {
            ++i;
        }

        for(int k=i;k<n;++k)
        {
            if(str[k]>'9' || str[k] < '0'){
                n = k;
                break;
            }
        }
        if(i>=n)return 0;
        long long ans = 0;
        int max_ans = (1<<31) - 1;
        for(;i<n;++i){
            ans = ans*10 + str[i] - '0';
            if(ans > max_ans){
               if(sig < 0)return sig*max_ans - 1; 
               else return max_ans;
            }
        }
        return sig*ans;
    }

};
void test(){
    //char *str = " 1-1010 ";
    //char *str = "+-2";
    char *str = "  2147483648 ";
    Solution sol;
    cout<<sol.atoi(str)<<endl;
}
int main()
{
    test();
	return 0;
}


