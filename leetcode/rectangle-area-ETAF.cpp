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

typedef long long llong;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long overlap =max(0LL,min(C_,G_)-max(A_,E_)) * max(0LL,min(D_,H_) - max(F_,B_));
        return (D_-B_)*(C_-A_) + (H_-F_)*(G_-E_) - overlap;
    }
};
class Solution_old {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long A_ = A, B_ = B, C_ = C, D_ = D, E_ = E, F_ = F, G_ = G, H_ = H;
        long long overlap =max(0LL,min(C_,G_)-max(A_,E_)) * max(0LL,min(D_,H_) - max(F_,B_));
        return (D_-B_)*(C_-A_) + (H_-F_)*(G_-E_) - overlap;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    cout<<sol.computeArea(-3,0, 3,4, 0,-1, 9, 2)<<endl;
    cout<<sol.computeArea(0,0, 4,4, 1,1, 2, 2)<<endl;
    cout<<sol.computeArea(0,0, 1,1, 1,0, 2, 1)<<endl;
    cout<<sol.computeArea(0,0, 1,1, 0,1, 1, 2)<<endl;
    cout<<sol.computeArea( 0,1, 1, 2, 0,0, 1,1)<<endl;
    cout<<sol.computeArea(0,0, 1,1, 10,0, 11, 1)<<endl;
    cout<<sol.computeArea(-2,-2, 2,2, -2,-4, 2, -2)<<endl;
    cout<<sol.computeArea(-2,-2, 2,2, -3,-3, 3, -1)<<endl;
    cout<<sol.computeArea(-1500000001,0,-1500000000,1,1500000000,0,1500000001,1)<<endl;
    return 0;
}


