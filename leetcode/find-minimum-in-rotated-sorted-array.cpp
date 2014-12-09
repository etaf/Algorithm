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

class Solution{
    public:
        int findMin(vector<int> &num) {
            int l=0,r = num.size();
            int mid;
            while(r-l>0){
                mid = (l+r) >> 1;
                if(mid>0 && num[mid]<num[mid-1])return num[mid];
                if(num[mid] > num[0])
                {
                    l = mid + 1;
                }
                else
                    r = mid;
            }
            return num[0];
        }
};
void test(){
    //vector<int> num({4,5,6,7,-1,1,2});
    vector<int> num({7,1,2,3,4});
    Solution sol;
    cout<<sol.findMin(num)<<endl;

}
int main()
{
    test();
	return 0;
}


