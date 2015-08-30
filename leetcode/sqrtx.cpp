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
class Solution { // newton method
    //if we need to know sqrt(C), construct a function:
    // f(x) = x^2 - C
    // make f(x) = 0, the value of x would be sqrt(C).
    // From newton method, we know x(n+1) = x(n) - f(x(n))/f'(x(n))
    // f'(x(n))  = 2*x(n);
    // x(n+1) = (x(n) + C/(x(n)) ) / 2;
    //
public:
    int mySqrt(int x) {
        double xn = 1;
        while(fabs(xn*xn-x)>=1)
        {
            xn = (xn + x/xn) / 2;
        }
        return xn;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    for(int i=1;i<10;++i){
        cout<<"sqrt("<<i<<") = "<<sol.mySqrt(i)<<endl;
    }
    return 0;
}


