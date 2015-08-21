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
    int nthUglyNumber(int n) {
        int  ps[] = {0,0,0};
        int primes[] = {2,3,5};
        int nums[n];
        int cntn = 0;
        nums[cntn++] = 1;
        int minp;
        int minn;
        while(cntn < n){
            minn = 0x7fffffff;
            for(int i=0; i<3; ++i){
                while(nums[ps[i]] * primes[i] <= nums[cntn-1]){++ps[i];}
                if(minn > nums[ps[i]] * primes[i])
                {
                    minp = i;
                    minn = nums[ps[i]] * primes[i];
                }
            }
            nums[cntn++] = minn;
            ++ps[minp];
        }
/*        for(int i=0;i<cntn;++i)cout<<nums[i]<<" ";*/
        /*cout<<endl;*/
        return nums[cntn-1];
    }
};
int main()
{
    Solution sol;
    cout<<sol.nthUglyNumber(10)<<endl;
    cout<<sol.nthUglyNumber(1)<<endl;
    cout<<sol.nthUglyNumber(4)<<endl;
    cout<<sol.nthUglyNumber(1600)<<endl;
    return 0;
}


