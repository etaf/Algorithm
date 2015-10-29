
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
bool mycmp(string x, string y){
    return x+y > y+x;

}
class Solution {
    public:

        string largestNumber(vector<int>& nums) {
            vector<string> ns(nums.size());
            for(int i=0; i<ns.size(); ++i){
                ns[i] = std::to_string(nums[i]);
            }
            sort(ns.begin(),ns.end(),mycmp);
            string ans = "";
            int i=0;
            while(i<ns.size()&& ns[i] == "0"){
                ++i;
            }
            for(; i<ns.size(); ++i){
                ans += ns[i];
            }
            if(ans.size()==0) ans = "0";
            return ans;
        }
};
int main()
{
    std::ios::sync_with_stdio(false);
    return 0;
}


