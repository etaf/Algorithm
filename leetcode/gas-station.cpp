#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) { // max subarray sum
        int n = gas.size();
        if(n==0)return -1;
        int now = 0;
        int p = 0;
        for(int i=0;i<n;++i){
           if(now <0 )
           {
               now = 0;
               p = i;
           }
           now += gas[i] - cost[i];
        }
        if(now < 0)return -1;
        now = gas[p]-cost[p];
        if(now < 0)return -1;
        for(int i = (p+1)%n; i!=p;i=(i+1)%n){
            now += gas[i]-cost[i];
            if(now < 0) return -1;
        }
        return p;
    }
};
void test(){
    Solution sol;
    vector<int> gas({4});
    vector<int> cost({5});
    cout<<sol.canCompleteCircuit(gas,cost )<<endl;
}
int main(){
    test();
    return 0;
}
