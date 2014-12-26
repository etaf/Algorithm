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
    int longestValidParentheses(string s) {
        int ans = 0;
        if(s.empty())return 0;
        stack<int> st;
        vector<int> dp(s.size());
        if(s[0] == '(')st.push(0);
        for(size_t i=1;i<s.size();++i){
            if(s[i] == '('){
                dp[i] = 0;
                st.push(i);
            }else{
                if(st.empty()){
                    dp[i] = 0;
                }else{
                    dp[i] = i-st.top() + 1 + (st.top() == 0 ? 0 : dp[st.top()-1]);
                    st.pop();
                }
            }
            ans = max(dp[i],ans);
        }
        return ans;
    }
};
int main()
{
    //string s = ")()())()()(";
    //string s = "())()";
    string s = "()())()";
    Solution sol;
    cout<<sol.longestValidParentheses(s)<<endl;
    return 0;
}


