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
    string getPermutation(int n, int k) {
        int pers[10];
        pers[0] = 1;
        string s;
        for(int i=1;i<=n;++i){
            pers[i] = pers[i-1] * i;
            s+=i+'0';
        }
        --k;
        k%=pers[n];
        int p;
        for(int i=0; i<n; ++i){
           p =k/pers[n-i-1];
           k%=pers[n-1-i];
           swap(s[i+p],s[i]);
           sort(s.begin() + i+1, s.end());
        }
        return s;
    }
};
void test(){

    int n = 5;
    Solution sol;
    for(int k=1;k<10;++k)
        cout<<sol.getPermutation(n,k)<<endl;

}
void test1(){
    int n = 2;
    Solution sol;
    cout<<sol.getPermutation(n,100)<<endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    test();
    test1();
    return 0;
}


