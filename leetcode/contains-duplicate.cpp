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
class Solution_old {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> S;
        for(auto x : nums){
            if(S.find(x) != S.end())
            {
                return true;
            }
            S.insert(x);
        }
        return false;
    }
};
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        const int M = 1000007;
        int hash_table[M];
        int n = nums.size();
        int pos;
        memset(hash_table,0,sizeof(hash_table));
        for(int i=0; i<n; ++i){
            pos = nums[i]%M;
            if(hash_table[pos] == 1)
                return true;
            hash_table[pos] = 1;
        }
        return false;
    }
};
int main()
{
    return 0;
}


