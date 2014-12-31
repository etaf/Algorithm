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
    int trailingZeroes(int n) { //找出所有的5乘子，因为有5 的乘子必有2与之对应，反之不然。 n/5 表示 1-n 里面 所有包含至少一个5因子的个数，n/5*5）表示至少包含2个5的个数。
        // 假设n = 5 * k, 那么5*（1，2，。。。k) 都小于n，都在【1-n】 区间内。
        int cnt5=0;
        for(int i=5;i<=n;i*=5){
           cnt5+= n/i;
        }
        return cnt5;
    }
};
int main()
{
    Solution sol;
    cout<<sol.trailingZeroes(30)<<endl;
    return 0;
}


