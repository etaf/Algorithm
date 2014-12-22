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
    bool isPalindrome(string s) {
        int l =0,r = s.size()-1;
        int d = 'A'-'a';
        while(l<r){
            while(l<r && not_valid(s[l]))++l;
            if(l>=r)break;
            while(l<r && not_valid(s[r]))--r;
            if(l>=r)break;
            if( !(s[l] == s[r] || s[l]+d == s[r] || s[r]+d ==s[l]))return false;
            ++l;--r;
        }
        return true;
    }
    bool not_valid(char c){return !( ('0'<= c && c<='9') || ('a'<=c && c<='z') || ('A'<=c && c<='Z'));}
};
int main()
{
    Solution sol;
    cout<<sol.isPalindrome("race a car")<<endl;
	return 0;
}


