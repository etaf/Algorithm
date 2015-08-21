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


