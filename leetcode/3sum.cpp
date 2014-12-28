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
class Solution { //O(n*n without a hash map
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ans;
        sort(num.begin(),num.end());
        size_t p,q;
        for(size_t i=0;i+2<num.size();++i){ // for(int i=0;i<num.size()-2;++i) or for(unsigned int i=0;i<num.size()-2;++i), when num.size() == 0 , (i<num.size()-2) == True
            p=i+1;
            q=num.size()-1;
            while(p<q){
                if(num[p] + num[q] == 0-num[i]){
                    ans.push_back(vector<int>({num[i],num[p],num[q]}));
                    while(p+2<num.size()&& num[p]==num[p+1]) ++p;
                    ++p;
                    --q;
                }else if(num[p] + num[q] < 0-num[i]) ++p;
                else --q;
            }
            while(i+1<num.size()-2 && num[i] == num[i+1])++i;
        }

        return ans;
    }
};
class Solution_bsearch { //O(n*n*log(n) without a hash map
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ans;
        sort(num.begin(),num.end());
        vector<int>::iterator it;
        for(size_t i=0;i+2<num.size();++i){ // for(int i=0;i<num.size()-2;++i) or for(unsigned int i=0;i<num.size()-2;++i), when num.size() == 0 , (i<num.size()-2) == True
            for(size_t j=i+1;j<num.size()-1;++j){
                it = lower_bound(num.begin()+j+1,num.end(),0-num[i]-num[j]);
                if(it==num.end() || *it != 0-num[i]-num[j])continue;
                ans.push_back(vector<int>({num[i],num[j],*it}));
                while(j+1<num.size()-1 && num[j] == num[j+1])++j;
            }
            while(i+1<num.size()-2 && num[i] == num[i+1])++i;
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> num({-1,0,1,2,-1,2,-4});
    vector<vector<int> > ans = sol.threeSum(num);
    sort(num.begin(),num.end());
    for(int i=0;i<ans.size();++i){
        for(int j=0;j<ans[i].size();++j){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


