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
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ans;
        int n = words.size();
        int p=0;
        for(int i=0;i<n;++i){
            p = i;
            int cnt = words[i].size();
            int c_num = cnt;
            while(i+1<n && cnt+words[i+1].size()+1 <= L){
                c_num += words[i+1].size();
                cnt+=words[i+1].size()+1;
                ++i;
            }
            if(i == n-1 || i==p){
                string line = words[p];
                for(int j=p+1;j<=i;++j)
                    line+=" "+words[j];
                line += string(L-cnt,' ');
                ans.push_back(line);
                continue;
            }
            int space_num = L - c_num;
            vector<string> sps(i-p);
            int j=0;
            while(space_num){
                --space_num;
                sps[j].push_back(' ');
                j = (j+1)%(i-p);
            }
            string line = words[p];
            for(int j=p+1;j<=i;++j){
                line += sps[j-p-1] + words[j];
            }
            ans.push_back(line);
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    //vector<string> words({"This", "is", "an", "example", "of", "text", "justification."});
    //vector<string> words({"What","must","be","shall","be."});
    vector<string> words({"Listen","to","many,","speak","to","a","few."});
    vector<string> ans = sol.fullJustify(words,6);
    for(size_t i = 0;i<ans.size();++i){
        cout<<ans[i]<<endl;
    }
    return 0;
}


