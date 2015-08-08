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
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int x1 = max(A,E), y1 = max(B, F),x2 = min(C, G), y2 = min(D, H);
        if(x1 > x2 || y1 > y2) return (C-A)*(D-B)+(G-E)*(H-F);
        return (C-A)*(D-B)+(G-E)*(H-F)-(x2-x1)*(y2-y1);
    }
};
class Solution_verse {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if(A > E){
            swap(A, E);
            swap(B, F);
            swap(C, G);
            swap(D, H);
        }
        // contain
/*        if(B<=F && C>=G && D >=H){*/
            //return (C-A)*(D-B);
        //}
        //if(E>=C || F >=D || H<=B){
            //return (C-A)*(D-B)+(G-E)*(H-F);
        /*}*/
        int x1 = E, y1 = max(B, F);
        int x2 = min(C, G), y2 = min(D, H);
        if(x1 > x2 || y1 > y2) return (C-A)*(D-B)+(G-E)*(H-F);
        //cout<<"<"<<x1<<","<<y1<<"> "<<"<"<<x2<<","<<y2<<">"<<endl;
        return (C-A)*(D-B)+(G-E)*(H-F)-(x2-x1)*(y2-y1);
    }
};
int main()
{
    Solution sol;
    cout<<sol.computeArea(-3,0, 3,4, 0,-1, 9, 2)<<endl;
    cout<<sol.computeArea(0,0, 4,4, 1,1, 2, 2)<<endl;
    cout<<sol.computeArea(0,0, 1,1, 1,0, 2, 1)<<endl;
    cout<<sol.computeArea(0,0, 1,1, 0,1, 1, 2)<<endl;
    cout<<sol.computeArea( 0,1, 1, 2, 0,0, 1,1)<<endl;
    cout<<sol.computeArea(0,0, 1,1, 10,0, 11, 1)<<endl;
    cout<<sol.computeArea(-2,-2, 2,2, -2,-4, 2, -2)<<endl;
    cout<<sol.computeArea(-2,-2, 2,2, -3,-3, 3, -1)<<endl;

    return 0;
}


