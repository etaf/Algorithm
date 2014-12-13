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
#include<unordered_set>
#include<unordered_map>
#include<limits.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<int> ps;
        int n = s.size();
        string tmp;
        ps.push_back(n);
        for(int i=n-1;i>=0;--i){
            tmp = "";
            int k = i;
            for(int j=ps.size()-1;j>=0;--j)
            {
                for(;k<ps[j];++k){
                    tmp.push_back(s[k]);
                }
                if(dict.find(tmp)!=dict.end())
                {
                    ps.push_back(i);
                    break;
                }
            }
        }
        if(*(ps.end()-1) == 0)return true;
        else return false;
    }

};
void test()
{
    unordered_set<string> dict;
    dict.insert(string("a"));
    dict.insert(string("abc"));
    dict.insert(string("b"));
    dict.insert(string("cd"));
    string s = "babcdab";
    Solution sol;
    cout<<sol.wordBreak(s,dict)<<endl;

}
int main()
{
    test();
	return 0;
}


