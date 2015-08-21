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
        bool isUgly(int num) {
            if(n<=0) return false;
            while(num%2){
                num/=2;
            }
            while(num%3){
                num/=3;
            }
            while(num%5){
                num/=5;
            }
            return num == 1;
        }
};
int main()
{

    return 0;
}


