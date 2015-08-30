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
using namespace std;

class Solution {

public:

    vector<vector<int> > fourSum(vector<int> &num, int target) { // O(n^3)
        sort(num.begin(),num.end());
        vector< vector<int> > ans;
        vector< vector<int> > tmp;
        int n = num.size();
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
               tmp = twoSum(j+1,n,num,target-num[i]-num[j]);
               for(int k=0;k<tmp.size();++k)
               {
                   ans.push_back(vector<int>({num[i],num[j],tmp[k][0],tmp[k][1]}));
               }
               while(j+1<n && num[j] == num[j+1])++j;
            }
            while(i+1<n && num[i] == num[i+1]) ++i;
        }
        return ans;
    }
    vector<vector<int> > twoSum(int l,int r,const vector<int> &num,int target){
        int p = l,q=r-1;
        vector<vector<int> > ans;

        while(p<q){
            if(num[p] + num[q] == target){
                ans.push_back(vector<int>({num[p],num[q]}));
                while(++p<r && num[p] == num[p-1]);
            }
            else if(num[p]+num[q]>target) --q;
            else ++p;
        }
        return ans;
    }

};
void test(){

    vector<int> num({1,0,-1,0,-2,2});int t = 0;
    //vector<int> num({1,1,1,1,1,1,1,1});int t =4;
    Solution sol;
    vector< vector<int> > ans =  sol.fourSum(num,t);
    for(int i=0;i<ans.size();++i){
        for(int j=0;j<ans[i].size();++j)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    test();
	return 0;
}


