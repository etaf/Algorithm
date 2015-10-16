
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
typedef long long llong;
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int r = citations.size()+1;
        int l = 0,mid,cnt;
        while(l+1<r){
            mid = (r+l)>>1;
            cnt = 0;
            for(int i=0; i<citations.size(); ++i){
                cnt+= (citations[i]>=mid);
            }
            if(cnt < mid){
                r = mid;
            }else l = mid;
        }
        return l;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    Solution sol;
    vector<int> nums1({3,0,6,1,5});
    vector<int> nums2({1});
    cout<<sol.hIndex(nums1)<<endl;
    cout<<sol.hIndex(nums2)<<endl;
    return 0;
}


