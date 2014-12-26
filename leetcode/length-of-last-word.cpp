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

    int lengthOfLastWord(const char *s) {
        int len = strlen(s);
        int l = 0;
        int i = len-1;
        while(i>=0 && s[i]==' ')--i;
        if(i<0) return 0;
        while(i>=0 && s[i]!=' ') --i,++l;
        return l;
    }
};
int main()
{
    Solution sol;
    char s[] = "   ";
    cout<<sol.lengthOfLastWord(s)<<endl;
    return 0;
}


