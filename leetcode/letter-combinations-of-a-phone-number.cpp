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

    string ss[10];
    string s;
    vector<string> letterCombinations(string digits) {
        s = digits;
        ss[2] = string("abc");
        ss[3] = string("def");
        ss[4] = string("ghi");
        ss[5] = string("jkl");
        ss[6] = string("mno");
        ss[7] = string("pqrs");
        ss[8] = string("tuv");
        ss[9] = string("wxyz");
        return dfs(0);
    }
    vector<string> dfs(int u){

        vector<string> res;
        if(!s[u]){
            res.push_back("");
            return res;
        }
        vector<string> cs = dfs(u+1);
        int p = s[u] - '0';
        for(int i=0;i<ss[p].size(); ++i)
        {
            for(int j=0;j<cs.size();++j){
                res.push_back(ss[p][i]+cs[j]);
            }
        }
        return res;
    }
};
void test(){
    string s("23");
    Solution sol;
    vector<string> res = sol.letterCombinations(s);
    for(int i=0;i<res.size();++i)cout<<res[i]<<" ";
    cout<<endl;
}
int main()
{
    test();
	return 0;
}


