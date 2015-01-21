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
    int searchInsert(int A[], int n, int target) {
        int l = 0,r = n,mid;
        while(l+1<r){
            mid = (l+r)>>1;
            if(A[mid] > target) r = mid;
            else l = mid;
        }
        if(A[l] == target) return l;
        if(A[l] < target) return l+1;
        return 0;
    }
};
int main()
{

    return 0;
}


