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
    vector<int> plusOne(vector<int> &digits) {
        vector<int> ans=digits;
        if(digits.empty())return ans;
        int c = (digits.back()+1)/10;
        ans[ans.size()-1] = (digits.back()+ 1)%10;
        for(int i=ans.size()-2;c && i>=0;--i){
            ans[i] = (ans[i] + c)%10;
            c = (digits[i] + c)/10;
        }
        if(c){
            ans.push_back(0);
            for(int i=ans.size()-1;i>0;--i) ans[i]=ans[i-1];
            ans[0]=1;
        }
        return ans;
    }

};
int main()
{
    Solution sol;
    vector<int> vs({1,9,9});
    vector<int> ans  = sol.plusOne(vs);
    for(size_t i=0;i<ans.size();++i)cout<<ans[i];
    cout<<endl;
    return 0;
}


