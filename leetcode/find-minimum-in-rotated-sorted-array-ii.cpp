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

            int ans = dfs(0,num.size(),num);
            if(ans == -1)
                return num[0];
            else return num[ans];
        }
        int dfs(int l,int r,vector<int> & num)
        {
            if(r-l<=0)return -1;
            int mid = (l+r)>>1;
            if(mid > 0 && num[mid] < num[mid-1])return mid;
            if(num[mid]>num[0]) return dfs( mid+1,r,num);
            else if(num[mid] < num[0]) return dfs(l,mid, num);
            else{
                if(num[num.size()-1]<num[0]) return dfs(mid+1,r,num);
                else return max(dfs(l,mid,num),dfs(mid+1,r,num));
            }
        }

};
void test(){
    //vector<int> num({2,1});
    //vector<int> num({4,5,6,7,-1,1,2});
    //vector<int> num({3,3,1});
    //vector<int> num({3,3,3,3,3,1,3});
    //vector<int> num({3,1,3,3});
    //vector<int> num({3,1,3,3,3,3,3,3,3});
    Solution sol;
    cout<<sol.findMin(num)<<endl;

}
int main()
{
    test();
	return 0;
}


