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
    int addDigits_old(int num) {
        while(num>9){
            int n = num;
            num = 0;
            while(n){
                num += n%10;
                n/=10;
            }
        }
        return num;
    }

    /*
     * (a_n * 10^n  + a_n-1 * 10^(n-1) + ... a0 * 1) MOD 9 == (a_n + a_n-1 + ... a0) MOD 9
     * Thus num % 9 == ans % 9 == ans ( if ans == 0 ans = 9)
     */
    int addDigits(int num) {
        return (num-1)%9 + 1;
    }
};
int main()
{
    Solution sol;
    for(int i=0;i<100;++i)
    cout<< sol.addDigits(i)<<" ";
    cout<<endl;
    return 0;
}


