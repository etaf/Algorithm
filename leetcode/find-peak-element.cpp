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
using namespace std;
class Solution {

    public:

    int findPeakElement(const vector<int> &num) {
        int n = num.size();
        if(n==0)return 0;
        if(num[0]>num[1])return 0;
        if(num[n-1]>num[n-2])return n-1;
        int l=1,r=n-1,mid;
        while(l<r)
        {
           mid = (l+r)>>1;
           if(num[mid]>num[mid-1] && num[mid]>num[mid+1])return mid;
           if(num[mid]>num[mid-1])
               l = mid+1;
           else
               r = mid;
        }
        return l;

    }

};

class Solution_O_n {

    public:

    int findPeakElement(const vector<int> &num) {
        int n = num.size();
        if(num[0]>num[1])return 0;
        if(num[n-1]>num[n-2])return n-1;
        for(int i=1;i<n-1;++i){
            if(num[i]>num[i-1] && num[i]>num[i+1])return i;
        }
    }

};
void test(){
        vector<int> num({1,2,3,1});
    Solution sol;
    cout<<sol.findPeakElement(num)<<endl;
}
int main()
{
    test();
	return 0;
}


