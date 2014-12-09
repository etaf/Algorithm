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

class Solution {
public:
    
    void reverseWords(string &s) {
        string st = s;
        int len = s.size();
        int cnt = 0;
        bool flag = false;
        for(int i=0;i<len;++i){
            while(i<len && st[i] == ' ')++i;
            if(i >= len)break;
            if(flag){s[cnt++] = ' ';}
            else{ flag = true;}
            while(i<len && st[i] != ' ')s[cnt++] = st[i++];
        }
        for(int i=cnt;i<len;++i)s.pop_back();
        int l = 0,r=cnt-1;
        while(l<r){
            swap(s[l],s[r]);
            ++l;--r;
        }
        for(int i=0;i<cnt;++i){
            while(i<cnt && s[i] == ' ')++i;
            l = i;
            while(i<cnt && s[i] != ' ')++i;
            r = i-1;
            while(l<r)
            {
                swap(s[l],s[r]);
                ++l;--r;
            }
        }

    }
};
void test(){
    string s = "  hello   world  ";
    Solution sol;
    sol.reverseWords(s);
    cout<<s<<endl;
}
int main()
{
    test();
	return 0;
}


