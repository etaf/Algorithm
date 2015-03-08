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
    void rotate(int nums[], int n, int k) {
        k%=n;
        this->reverse(nums,0,n-k);
        this->reverse(nums,n-k,n);
        this->reverse(nums,0,n);
    }
private:
    void reverse(int* nums,int begin,int end){
        --end;
        while(begin < end){
            swap(nums[begin],nums[end]);
            ++begin;
            --end;
        }
    }
};
int main()
{
    Solution sol;
    int nums[] = {1,2};
    sol.rotate(nums,2,0);
    for(int i=0;i<2;++i)cout<<nums[i]<<" ";
    cout<<endl;
    return 0;
}


