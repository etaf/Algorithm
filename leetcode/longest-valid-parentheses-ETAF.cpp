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
        stack<int> st;
        int ans = 0, invalid_p = -1 ;
        for(int i=0; i<s.size(); ++i){
            if(s[i] == '('){
                st.push(i);
            }else{
                if(!st.empty())
                {
                   st.pop();
                   ans = max(ans, st.empty() ? i - invalid_p : i-st.top());
                }else{
                    invalid_p = i;
                }
            }
        }
        return ans;

    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    //string s = "()())()";
    string s = ")()()((";

    Solution sol;
    cout<<sol.longestValidParentheses(")()()((")<<endl;
    cout<<sol.longestValidParentheses("(()")<<endl;
    cout<<sol.longestValidParentheses("(")<<endl;
    cout<<sol.longestValidParentheses("())")<<endl;
    cout<<sol.longestValidParentheses("()(")<<endl;
    cout<<sol.longestValidParentheses(")(((((()())()()))()(()))(")<<endl;
    cout<<sol.longestValidParentheses(")(()(")<<endl;
    cout<<sol.longestValidParentheses("(()))(()(")<<endl;

    return 0;
}


