
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
        int l = 0,mid;
        while(l+1<r){
            mid = (r+l)>>1;
            if(citations[citations.size() - mid] < mid){
                r = mid;
            }else l = mid;
        }
        return l;
    }
};


class Solution_old {
public:
    int hIndex(vector<int>& citations) {
        int r = citations.size()+1;
        int l = 0,mid,cnt;
        int ll,rr,mmid;
        while(l+1<r){
            mid = (r+l)>>1;
            //cnt = citations.size() - (std::lower_bound(citations.begin(),citations.end(),mid)-citations.begin());
            ll = -1;
            rr = citations.size();
            while(ll+1<rr){
                mmid = (ll+rr)>>1;
                if(citations[mmid] < mid) ll= mmid; 
                else rr = mmid;
            }
            cnt = citations.size() - rr;
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
    //vector<int> nums1({3,0,6,1,5});
    vector<int> nums1({0,1,3,5,6});
    vector<int> nums2({1});
    vector<int> nums3({0});
    cout<<sol.hIndex(nums1)<<endl;
    cout<<sol.hIndex(nums2)<<endl;
    cout<<sol.hIndex(nums3)<<endl;
    return 0;
}


