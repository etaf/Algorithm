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
    private:
        int convert(int n){
            int res = 0;
            int x;
            while(n){
                x = n%10;
                n/=10;
                res += x*x;
            }
            return res;
        }
    public:
    bool isHappy(int n) {
        //unordered_set<int> S;
        //S.insert(n);
        bool hash_table[654]; //(2,299,999,999)
        memset(hash_table,0,sizeof(hash_table));
        while(n!=1){
            n = convert(n);
            //if(S.find(n) != S.end())return false;
            //S.insert(n);
            if(hash_table[n]) return false;
            hash_table[n] = true;
        }
        return true;
    }
};
int main()
{
    Solution sol;
    cout<<sol.isHappy(20)<<endl;
    return 0;
}


